cmake_minimum_required(VERSION 3.28)
project(raia_system C)

include(${PROJECT_SOURCE_DIR}/../../setting.cmake)

set(CMAKE_C_STANDARD 11)

add_library(raia_system SHARED raia_system.c)

# OSに応じた条件分岐
if(WIN32)
    # Windowsの場合
    target_link_libraries(raia_system PRIVATE kernel32)
elseif(APPLE)
    # macOSの場合
    find_library(IOKIT_LIBRARY IOKit)
    find_library(CORE_FOUNDATION_LIBRARY CoreFoundation)
    target_link_libraries(raia_system PRIVATE ${IOKIT_LIBRARY} ${CORE_FOUNDATION_LIBRARY})
elseif(UNIX AND NOT APPLE)
    # Linuxの場合（macOSはUNIXとして認識されるので除外）
    # ここでは特にリンクするライブラリは不要ですが、依存関係がある場合は指定します
endif()

#target_link_libraries(raia_system
#        $<$<PLATFORM_ID:Darwin>: -framework IOKit -framework CoreFoundation>
#        $<$<PLATFORM_ID:Linux>: >
#        $<$<PLATFORM_ID:Windows>: >
#)