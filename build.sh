#!/bin/bash

cd cmake
cmake -DCMAKE_C_COMPILER=/opt/homebrew/bin/gcc-13 -DCMAKE_BUILD_TYPE=Release ../src
cmake --build .
ctest

# OS=$(uname)

# case "$OS" in
#     "Darwin")
#         # macOSの場合の処理
#         cd build/macos/arm64/release
#         ;;
#     "Linux")
#         if grep -q Microsoft /proc/version; then
#             # WindowsのWSLの場合の処理
#         else
#             # 通常のLinuxの場合の処理
#         fi
#         ;;
#     *)
#         # その他
#         echo "Unknown OS"
#         ;;
# esac

# cmake -DCMAKE_BUILD_TYPE=Release ../../
# cmake --build .