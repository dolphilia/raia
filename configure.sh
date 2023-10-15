#!/bin/bash
cd third_party
git clone https://chromium.googlesource.com/chromium/tools/depot_tools.git
export PATH=$PWD/depot_tools:$PATH
mkdir angle
cd angle
fetch angle
gn gen out/Release
autoninja -C out/Release
cd ../
cp angle/out/Release/libc++_chrome.dylib ../sdk/macos/arm64/lib
cp angle/out/Release/libchrome_zlib.dylib ../sdk/macos/arm64/lib
cp angle/out/Release/libEGL.dylib ../sdk/macos/arm64/lib
cp angle/out/Release/libGLESv2.dylib ../sdk/macos/arm64/lib
cp angle/out/Release/libthird_party_abseil-cpp_absl.dylib ../sdk/macos/arm64/lib
rsync -av angle/include/ ../sdk/macos/arm64/include/
mkdir v8
cd v8
fetch v8
cd v8
git checkout refs/tags/11.7.115
gclient sync -D
python3 tools/dev/v8gen.py arm64.release
cat <<EOF >out.gn/arm64.release/args.gn
dcheck_always_on = false
is_component_build = false
is_debug = false
target_cpu = "arm64"
use_custom_libcxx = false
v8_monolithic = true
v8_enable_sandbox = false
v8_use_external_startup_data = false
v8_enable_pointer_compression = false
v8_enable_31bit_smis_on_64bit_arch = false
EOF

ninja -C out.gn/arm64.release v8_monolith

cd ../../
cp v8/v8/out.gn/arm64.release/obj/libv8_monolith.a ../sdk/macos/arm64/lib
cp v8/v8/out.gn/arm64.release/obj/libv8_libbase.a ../sdk/macos/arm64/lib
cp v8/v8/out.gn/arm64.release/obj/libv8_libplatform.a ../sdk/macos/arm64/lib
rsync -av v8/v8/include/ ../sdk/macos/arm64/include/
git clone https://github.com/glfw/glfw.git
cd glfw
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=ON ..
cmake --build .
cd ../../
cp glfw/build/src/libglfw.3.4.dylib ../sdk/macos/arm64/lib
rsync -av glfw/include/ ../sdk/macos/arm64/include/
git clone https://github.com/mruby/mruby.git
cd mruby
make
cd ../
cp mruby/build/host/lib/libmruby_core.a ../sdk/macos/arm64/lib
cp mruby/build/host/lib/libmruby.a ../sdk/macos/arm64/lib
rsync -av mruby/build/host/include/ ../sdk/macos/arm64/include/