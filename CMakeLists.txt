enable_testing()

cmake_minimum_required(VERSION 3.0)

# ビルドディレクトリ内の子ディレクトリを取得
file(GLOB subdirectories RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *)

# 子ディレクトリごとにCMakeLists.txtを処理
foreach(subdirectory ${subdirectories})
    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${subdirectory})
        if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${subdirectory}/CMakeLists.txt)
            add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/${subdirectory})
        endif()
    endif()
endforeach()

add_executable(test_program Testing/test.c)
add_test(NAME TestProgram COMMAND test_program)