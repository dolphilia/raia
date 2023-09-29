cmake_minimum_required(VERSION 3.26)
project(raia_jni)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/include/darwin)
link_directories(${PROJECT_SOURCE_DIR}/lib)
link_directories(${PROJECT_SOURCE_DIR}/lib/server)

add_executable(raia_jni src/raia_jni.cpp)

target_link_libraries(raia_jni
        $<$<PLATFORM_ID:Darwin>: jvm>#attach awt awt_lwawt dt_socket extnet fontmanager freetype instrument j2gss j2pcsc j2pkcs11 jaas java javajpeg jawt jdwp jimage jli jsig jsound jvm lcms management management_agent management_ext mlib_image net nio osx osxapp osxkrb5 osxsecurity osxui prefs rmi saproc splashscreen syslookup verify zip>
        $<$<PLATFORM_ID:Linux>: >
        $<$<PLATFORM_ID:Windows>: >
)