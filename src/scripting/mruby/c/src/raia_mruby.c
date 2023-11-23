#include "raia_mruby.h"

mrb_value raia_lib_open(mrb_state *mrb, mrb_value self) {
    char *dll_file = NULL;
    mrb_get_args(mrb, "z", &dll_file);
    char dll_file_extension[500];
    SPRINTF(dll_file_extension, "%s.%s", dll_file, DYNAMIC_LIB_EXT);
    void *handle = add_plugin_hash(dll_file_extension);
    return mrb_fixnum_value((int64_t)(uintptr_t)handle);
}

mrb_value raia_lib_add(mrb_state *mrb, mrb_value self) {
    mrb_int handle_i;
    char *dll_func_name = NULL;
    mrb_get_args(mrb, "iz", &handle_i, dll_func_name);
    void *handle = (void *)handle_i;
    add_plugin_func_hash(handle, dll_func_name);
    return mrb_nil_value();
}

RAIA_API const char *init(int argc, char *argv[]) {
    mrb_state *mrb = mrb_open();
    if (!mrb) {
        return NULL;
    }
    struct RClass *cls;
    cls = mrb_define_class(mrb, "Lib", mrb->object_class);
    mrb_define_class_method(mrb, cls, "open", raia_lib_open, MRB_ARGS_REQ(1));
    mrb_define_class_method(mrb, cls, "add", raia_lib_add, MRB_ARGS_REQ(2));

    const char *filename = "main.mrb";
    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        printf("%s file not open!\n", filename);
        return NULL;
    }
    mrb_load_file(mrb, file);
    fclose(file);

    if (mrb->exc) {
        mrb_print_error(mrb);
        mrb_close(mrb);
        return NULL;
    }
    mrb_close(mrb);
    return 0;
}
