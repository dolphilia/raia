#!/bin/sh

libs=(
    "app"
    "draw"
    "file"
    "duktape"
    "lua"
    "mruby"
    "sound"
    "sdk"
)

if [ "$(uname)" = "Darwin" ]; then
    echo "macOS:"
    exe_ext=""
    lib_ext=".dylib"
    out_dir="aarch64-macos-none"
    os="macos"
elif [ "$(uname)" = "Linux" ]; then
    echo "Linux:"
    exe_ext=""
    lib_ext=".so"
    out_dir="x86_64-linux-gnu"
    os="linux"
elif [ "$(uname -o)" = "Msys" ]; then
    echo "Windows (MinGW):"
    exe_ext=".exe"
    lib_ext=".dll"
    out_dir="x86_64-windows-gnu"
    os="windows"
else
    echo "Unable to determine OS."
    exit 1
fi

mv -f ./raia-core/raia_core${exe_ext} ./build/${out_dir}/

for lib in ${libs[@]} ; do
    mv -f ./raia-${lib}/raia_${lib}${lib_ext} ./build/${out_dir}/
done

# thirdparty libs
if [ "$(uname)" = "Darwin" ]; then
    echo "macOS:"
    third_libs=(
        "libabsl"
        "libc++_chrome"
        "libchrome_zlib"
        "libEGL"
        "libGLESv2"
        "libglfw.3.3"
    )
elif [ "$(uname)" = "Linux" ]; then
    echo "Linux:"
elif [ "$(uname -o)" = "Msys" ]; then
    echo "Windows (MinGW):"
else
    echo "Unable to determine OS."
    exit 1
fi

for third_lib in ${third_libs[@]} ; do
    cp -f ./raia-template/lib/${os}/${third_lib}${lib_ext} ./build/${out_dir}/
done

cp -f ./raia-template/raia_config.json ./build/${out_dir}
cp -R ./raia-template/duktape ./build/${out_dir}
cp -R ./raia-template/material ./build/${out_dir}