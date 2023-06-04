#!/bin/bash

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

# ディレクトリをコピーする "コピー元となるディレクトリのパス" "コピー先となるディレクトリのパス"
copy_directory "/Users/dolphilia/Documents/github/raia-core" "/Users/dolphilia/Documents/github/raia-engine/raia-core"
copy_directory "/Users/dolphilia/Documents/github/raia-app" "/Users/dolphilia/Documents/github/raia-engine/raia-app"
copy_directory "/Users/dolphilia/Documents/github/raia-draw" "/Users/dolphilia/Documents/github/raia-engine/raia-draw"
copy_directory "/Users/dolphilia/Documents/github/raia-file" "/Users/dolphilia/Documents/github/raia-engine/raia-file"
copy_directory "/Users/dolphilia/Documents/github/raia-sound" "/Users/dolphilia/Documents/github/raia-engine/raia-sound"

copy_directory "/Users/dolphilia/Documents/github/raia-duktape" "/Users/dolphilia/Documents/github/raia-engine/raia-duktape"
copy_directory "/Users/dolphilia/Documents/github/raia-lua" "/Users/dolphilia/Documents/github/raia-engine/raia-lua"
copy_directory "/Users/dolphilia/Documents/github/raia-mruby" "/Users/dolphilia/Documents/github/raia-engine/raia-mruby"

copy_directory "/Users/dolphilia/Documents/github/raia-sdk" "/Users/dolphilia/Documents/github/raia-engine/raia-sdk"
copy_directory "/Users/dolphilia/Documents/github/raia-example" "/Users/dolphilia/Documents/github/raia-engine/raia-example"
copy_directory "/Users/dolphilia/Documents/github/raia-document" "/Users/dolphilia/Documents/github/raia-engine/raia-document"
copy_directory "/Users/dolphilia/Documents/github/raia-template" "/Users/dolphilia/Documents/github/raia-engine/raia-template"