#!/bin/bash

projects=(
    "raia-core"
    "raia-app"
    "raia-draw"
    "raia-file"
    "raia-duktape"
    "raia-lua"
    "raia-mruby"
)

include_path="-I ./include"
library_path="-L ./lib"

mkdir build
mkdir build/x86_64-windows-gnu
mkdir build/x86_64-linux-gnu
mkdir build/aarch64-macos-none

for os in windows linux macos ; do
    if [ $os = windows ] ; then
        target="x86_64-windows-gnu"
        out_dir="../build/x86_64-windows-gnu"
        lib_ext=".dll"
        exe_ext=".exe"
        library_path="-L ./lib -L ./lib/windows"
    elif [ $os = linux ] ; then
        target="x86_64-linux-gnu"
        out_dir="../build/x86_64-linux-gnu"
        lib_ext=".so"
        exe_ext=""
        library_path="-L ./lib -L ./lib/linux"
    elif [ $os = macos ] ; then
        target="aarch64-macos-none"
        out_dir="../build/aarch64-macos-none"
        lib_ext=".dylib"
        exe_ext=""
        library_path="-L ./lib -L /lib/macos"
    fi

    for project in ${projects[@]} ; do
        if [ $project = raia-core ] ; then
            options=""
            ext=${exe_ext}
        else
            options="-shared"
            ext=${lib_ext}
        fi

        links=("")

        if [ $project = raia-core ] ; then
            out_name="raia_core"
            sources=(
                "src/raia-core.c"
                "src/yyjson/yyjson.c"
            )
        elif [ $project = raia-app ] ; then
            out_name="raia_app"
            sources=(
                "src/raia_app.c"
                "src/static/static_callback.c"
                "src/yyjson/yyjson.c"
            )
            if [ $os = windows ] ; then
                links=("-lEGL" "-lglfw3" "-lGLESv2")
            elif [ $os = linux ] ; then
                links=("-lm" "-ldl" "-lEGL" "-lglfw" "-lGLESv2" "-lX11" "-lXxf86vm" "-lXrandr" "-lXinerama" "-lXcursor" "-lpthread" "-lXi")
            elif [ $os = macos ] ; then
                links=("-legl" "-lglfw" "-lGLESv2")
            fi
        elif [ $project = raia-draw ] ; then
            out_name="raia_draw"
            sources=(
                "src/raia_draw.c"
                "src/util/util_math.c"
                "src/util/util_pixel.c"
                "src/stb/stb_image.c"
                "src/wrapper/wrapper_stb_image.c"
                "src/lodepng/lodepng.c"
                "src/util/util_primitive3d.c"
                "src/wrapper/wrapper_stb_truetype.c"
                "src/util/util_utf8.c"
                "src/yyjson/yyjson.c"
            )
        elif [ $project = raia-file ] ; then
            out_name="raia_file"
            sources=(
                "src/raia_file.c"
                "src/util/util_file.c"
                "src/yyjson/yyjson.c"
            )
            links="-lm"
        elif [ $project = raia-duktape ] ; then
            out_name="raia_duktape"
            sources=(
                "src/raia_duktape.c"
                "src/util/util_file.c"
                "src/list/list.c"
                "src/list/list_iterator.c"
                "src/list/list_node.c"
                "src/duktape/duktape.c"
                "src/duktape-module/duk_module_duktape.c"
                "src/static/static_func_hash.c"
                "src/static/static_plugin_loader.c"
                "src/yyjson/yyjson.c "
                "src/static/static_entrust.c "
            )
        elif [ $project = raia-lua ] ; then
            out_name="raia_lua"
            sources=(
                "src/raia_lua.c"
                "src/lua/lapi.c"
                "src/lua/lauxlib.c"
                "src/lua/lbaselib.c"
                "src/lua/lcode.c"
                "src/lua/lcorolib.c"
                "src/lua/lctype.c"
                "src/lua/ldblib.c"
                "src/lua/ldebug.c"
                "src/lua/ldo.c"
                "src/lua/ldump.c"
                "src/lua/lfunc.c"
                "src/lua/lgc.c"
                "src/lua/linit.c"
                "src/lua/liolib.c"
                "src/lua/llex.c"
                "src/lua/lmathlib.c"
                "src/lua/lmem.c"
                "src/lua/loadlib.c"
                "src/lua/lobject.c"
                "src/lua/lopcodes.c"
                "src/lua/loslib.c"
                "src/lua/lparser.c"
                "src/lua/lstate.c"
                "src/lua/lstring.c"
                "src/lua/lstrlib.c"
                "src/lua/ltable.c"
                "src/lua/ltablib.c"
                "src/lua/ltm.c"
                "src/lua/lua.c"
                "src/lua/luac.c"
                "src/lua/lundump.c"
                "src/lua/lutf8lib.c"
                "src/lua/lvm.c"
                "src/lua/lzio.c"
                "src/list/list.c"
                "src/list/list_iterator.c"
                "src/list/list_node.c"
                "src/parson/parson.c"
                "src/static/static_func_hash.c"
                "src/util/util_file.c"
                "src/static/static_plugin_loader.c"
            )
        elif [ $project = raia-mruby ] ; then
            out_name="raia_mruby"
            sources=(
                "src/raia_mruby.c"
            )
            links="-lmruby"
        fi

        cd ${project}

        include_path="-I$(pwd)/include"
        library_path="-L$(pwd)/lib"
        echo zig cc -O2 -std=c11 ${options} --target=${target} ${include_path} ${library_path} ${links[@]} -o ${out_dir}/${out_name}${ext} ${sources[@]}
        echo

        zig cc -O2 -std=c11 ${options} --target=${target} ${include_path} ${library_path} ${links[@]} -o ${out_dir}/${out_name}${ext} ${sources[@]}
        # zig cc \
        #     -O2 \
        #     ${options} \
        #     --target=${target} \
        #     -o ${out_dir}/actions_practise.${ext} \
        #     main.c

        cd ../
    done
done