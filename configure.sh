#!/bin/bash
#
cd third_party
#
# depot_tool のセットアップ
git clone https://chromium.googlesource.com/chromium/tools/depot_tools.git
export PATH=$PWD/depot_tools:$PATH
#
# ANGLE のセットアップ
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
#
# V8 のセットアップ
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
#
# GLFW のセットアップ
git clone https://github.com/glfw/glfw.git
cd glfw
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=ON ..
cmake --build .
cd ../../
cp glfw/build/src/libglfw.3.4.dylib ../sdk/macos/arm64/lib
rsync -av glfw/include/ ../sdk/macos/arm64/include/
#
# mruby のセットアップ
git clone https://github.com/mruby/mruby.git
cd mruby
make
cd ../
cp mruby/build/host/lib/libmruby_core.a ../sdk/macos/arm64/lib
cp mruby/build/host/lib/libmruby.a ../sdk/macos/arm64/lib
rsync -av mruby/build/host/include/ ../sdk/macos/arm64/include/
#
# Skia のセットアップ
brew install jpeg
brew install harfbuzz
brew install icu4c
git clone https://skia.googlesource.com/skia.git
cd skia
# git checkout  0d49b661d75adbb8ac8cf88f7d527b1587be2c63
# git submodule update --init --recursive
#
# skia/BUILD.gn から以下の記述を削除またはコメントアウトすること
#    "SK_DEFAULT_TYPEFACE_IS_EMPTY",
#    "SK_DISABLE_LEGACY_DEFAULT_TYPEFACE",
python3 tools/git-sync-deps
bin/gn gen out/Shared --args='
is_official_build = true
is_component_build = true
skia_use_angle = true
skia_enable_skottie = false
cc = "clang"
cxx = "clang++"
target_os = "mac"
target_cpu = "arm64"
extra_cflags = [ "-frtti", "-I/opt/homebrew/include", "-I/opt/homebrew/include/harfbuzz", "-I/opt/homebrew/opt/icu4c/include" ]
extra_ldflags = [ "-L/opt/homebrew/lib", "-L/opt/homebrew/opt/icu4c/lib" ]
'
# bin/gn gen out/Shared --args='
# is_official_build = false
# is_component_build = true
# cc = "clang"
# cxx = "clang++"
# target_os = "mac"
# target_cpu = "arm64"
# '
ninja -C out/Shared
cd ../
cp skia/out/Shared/libbentleyottmann.dylib ../sdk/macos/arm64/lib
cp skia/out/Shared/libskia.dylib ../sdk/macos/arm64/lib
cp skia/out/Shared/libskparagraph.dylib ../sdk/macos/arm64/lib
cp skia/out/Shared/libsksg.dylib ../sdk/macos/arm64/lib
cp skia/out/Shared/libskshaper.dylib ../sdk/macos/arm64/lib
cp skia/out/Shared/libskunicode.dylib ../sdk/macos/arm64/lib
cp skia/out/Shared/libcompression_utils_portable.a ../sdk/macos/arm64/lib
cp skia/out/Shared/libdng_sdk.a ../sdk/macos/arm64/lib
cp skia/out/Shared/libexpat.a ../sdk/macos/arm64/lib
cp skia/out/Shared/libpathkit.a ../sdk/macos/arm64/lib
cp skia/out/Shared/libpiex.a ../sdk/macos/arm64/lib
cp skia/out/Shared/libpng.a ../sdk/macos/arm64/lib
cp skia/out/Shared/libskcms.a ../sdk/macos/arm64/lib
cp skia/out/Shared/libskresources.a ../sdk/macos/arm64/lib
cp skia/out/Shared/libwuffs.a ../sdk/macos/arm64/lib
cp skia/out/Shared/libzlib.a ../sdk/macos/arm64/lib
mkdir ../sdk/macos/arm64/include/skia
mkdir ../sdk/macos/arm64/include/skia/include
rsync -av skia/include/ ../sdk/macos/arm64/include/skia/include/
#
# assimp のセットアップ
git clone https://github.com/assimp/assimp.git
cd assimp
mkdir build
cd build
cmake -G "Unix Makefiles" -DBUILD_SHARED_LIBS=ON ..
make
cd ../../
cp assimp/build/bin/libassimp.5.3.0.dylib ../sdk/macos/arm64/lib
cp assimp/build/include/assimp/config.h ../sdk/macos/arm64/include/assimp
rsync -av assimp/include/ ../sdk/macos/arm64/include/
#
# 共有ライブラリをsdkからbuildにコピーする
cd ../
# (debugにも)
cp sdk/macos/arm64/lib/libc++_chrome.dylib build/macos/arm64/debug
cp sdk/macos/arm64/lib/libchrome_zlib.dylib build/macos/arm64/debug
cp sdk/macos/arm64/lib/libEGL.dylib build/macos/arm64/debug
cp sdk/macos/arm64/lib/libGLESv2.dylib build/macos/arm64/debug
cp sdk/macos/arm64/lib/libglfw.3.4.dylib build/macos/arm64/debug
cp sdk/macos/arm64/lib/libthird_party_abseil-cpp_absl.dylib build/macos/arm64/debug
# (releaseにも)
cp sdk/macos/arm64/lib/libc++_chrome.dylib build/macos/arm64/release
cp sdk/macos/arm64/lib/libchrome_zlib.dylib build/macos/arm64/release
cp sdk/macos/arm64/lib/libEGL.dylib build/macos/arm64/release
cp sdk/macos/arm64/lib/libGLESv2.dylib build/macos/arm64/release
cp sdk/macos/arm64/lib/libglfw.3.4.dylib build/macos/arm64/release
cp sdk/macos/arm64/lib/libthird_party_abseil-cpp_absl.dylib build/macos/arm64/release
#
sh create_alias.sh
