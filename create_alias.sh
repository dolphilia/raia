#!/bin/sh
create_alias() {
    local src_file="$1"
    local dest_folder="$2"
    local alias_name="$3"
    osascript <<END_SCRIPT
tell application "Finder"
    make alias file to (POSIX file "$src_file") at (POSIX file "$dest_folder") with properties {name:"$alias_name"}
end tell
END_SCRIPT
}
create_alias "${PWD}/sdk/macos/arm64/lib/libglfw.3.4.dylib" "${PWD}/sdk/macos/arm64/lib" "libglfw.3.dylib"
create_alias "${PWD}/sdk/macos/arm64/lib/libglfw.3.4.dylib" "${PWD}/sdk/macos/arm64/lib" "libglfw.dylib"
create_alias "${PWD}/build/macos/arm64/debug/libglfw.3.4.dylib" "${PWD}/build/macos/arm64/debug" "libglfw.3.dylib"
create_alias "${PWD}/build/macos/arm64/debug/libglfw.3.4.dylib" "${PWD}/build/macos/arm64/debug" "libglfw.dylib"
create_alias "${PWD}/build/macos/arm64/release/libglfw.3.4.dylib" "${PWD}/build/macos/arm64/release" "libglfw.3.dylib"
create_alias "${PWD}/build/macos/arm64/release/libglfw.3.4.dylib" "${PWD}/build/macos/arm64/release" "libglfw.dylib"
