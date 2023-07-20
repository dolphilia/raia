#!/bin/sh

# ディレクトリを再帰的にコピーする関数
copy_directory() {
    local source="$1"
    local destination="$2"

    # コピー先ディレクトリが存在する場合は一度削除する
    if [[ -d "$destination" ]]; then
        rm -rf "$destination"
    fi
    
    # コピー元ディレクトリをコピー先に作成
    mkdir -p "$destination"
    
    # ディレクトリ内のファイルとディレクトリを取得
    local items=( "$source"/* )
    
    for item in "${items[@]}"; do
        local item_name=$(basename "$item")
        
        # .gitディレクトリと.gitignoreファイルを除外
        if [[ "$item_name" != ".git" && \
              "$item_name" != ".gitignore" && \
              "$item_name" != ".DS_Store" && \
              "$item_name" != ".github" && \
              "$item_name" != "cmake-build-debug" && \
              "$item_name" != "cmake-build-release" ]]; then
            if [[ -d "$item" ]]; then
                # サブディレクトリの場合、再帰的にコピーする
                copy_directory "$item" "$destination/$item_name"
            elif [[ -f "$item" ]]; then
                # ファイルの場合、コピー先ディレクトリにコピーする
                cp "$item" "$destination/$item_name"
            fi
        fi
    done
}

if [ "$(uname)" = "Darwin" ]; then
    echo "macOS:"
    out_dir="aarch64-macos-none"
elif [ "$(uname)" = "Linux" ]; then
    echo "Linux:"
    out_dir="x86_64-linux-gnu"
elif [ "$(uname -o)" = "Msys" ]; then
    echo "Windows (MinGW):"
    out_dir="x86_64-windows-gnu"
else
    echo "Unable to determine OS."
    exit 1
fi

copy_directory "../raia-template" "./raia-template"

cp -f ./raia-template/config.json ./build/${out_dir}
cp -f ./raia-template/raia_config.json ./build/${out_dir}
cp -R ./raia-template/v8 ./build/${out_dir}
cp -R ./raia-template/duktape ./build/${out_dir}
cp -R ./raia-template/material ./build/${out_dir}

cd build/${out_dir}

./raia_core