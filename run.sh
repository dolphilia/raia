#!/bin/sh
#
if [ "$(uname)" = "Darwin" ]; then
    out_dir="macos/arm64/release"
elif [ "$(uname)" = "Linux" ]; then
    out_dir="linux/x86_64/release"
elif [ "$(uname -o)" = "Msys" ]; then
    out_dir="windows/x86_64/release"
else
    echo "Unable to determine OS."
    exit 1
fi
#
cp -R template/v8/* build/${out_dir}/
cd build/${out_dir}
./raia_startup
