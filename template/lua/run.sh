if [ "$(uname)" = "Darwin" ]; then
    echo "macOS:"
    out_dir="macos/arm64/release"
elif [ "$(uname)" = "Linux" ]; then
    echo "Linux:"
    out_dir="linux/x86_64/release"
elif [ "$(uname -o)" = "Msys" ]; then
    echo "Windows (MinGW):"
    out_dir="windows/x86_64/release"
else
    echo "Unable to determine OS."
    exit 1
fi
cp -R ./* ../../build/${out_dir}/
cd ../../build/${out_dir}/
./raia_startup
