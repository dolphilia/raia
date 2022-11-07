//
//  static_dlfcn.c
//  raia-engine
//
//  Created by dolphilia on 2022/11/07.
//

#include "static_dlfcn.h"

PluginList *plugin_list;
FuncList *func_list;

//== プラグインの連結リスト

// コンストラクタ
static PluginCell *make_plugin_cell(raia_handle_t handle, PluginCell *cp) {
    PluginCell *newcp = malloc(sizeof(PluginCell));
    if (newcp != NULL) {
        newcp->handle = handle;
        newcp->next = cp;
    }
    return newcp;
}

PluginList *make_plugin_list(void) {
    PluginList *ls = malloc(sizeof(PluginList));
    if (ls != NULL) {
        ls->top = make_plugin_cell(0, NULL);  // ヘッダセルをセット
        if (ls->top == NULL) {
            free(ls);
            return NULL;
        }
    }
    return ls;
}

// 解放
static void delete_plugin_cell_(PluginCell *cp) {
    while (cp != NULL) {
        PluginCell *temp = cp->next;
        free(cp);
        cp = temp;
    }
}

void delete_plugin_list(PluginList *ls) {
    delete_plugin_cell_(ls->top);
    free(ls);
}

// n 番目のセルを返す
static PluginCell *nth_plugin_cell_(PluginCell *cp, int n) {
    for (int i = -1; cp != NULL; i++, cp = cp->next) {
        if (i == n) break;
    }
    return cp;
}

// n 番目の要素を返す
raia_handle_t nth_plugin_list(PluginList *ls, int n, bool *err) {
    PluginCell *cp = nth_plugin_cell_(ls->top, n);
    if (cp == NULL) {
        *err = false;
        return 0;
    }
    *err = true;
    return cp->handle;
}

// n 番目に x を挿入
bool insert_nth_plugin_list(PluginList *ls, int n, raia_handle_t handle) {
    PluginCell *cp = nth_plugin_cell_(ls->top, n - 1);
    if (cp == NULL) {
        return false;
    }
    cp->next = make_plugin_cell(handle, cp->next);
    return true;
}

// n 番目の要素を削除
bool delete_nth_plugin_list(PluginList *ls, int n) {
    PluginCell *cp = nth_plugin_cell_(ls->top, n - 1);
    if (cp == NULL || cp->next == NULL) {
        return false;
    }
    PluginCell *temp = cp->next;
    cp->next = cp->next->next;
    free(temp);
    return true;
}

// 先頭に追加
bool push_plugin_list(PluginList *ls, raia_handle_t handle) {
    return insert_nth_plugin_list(ls, 0, handle);
}

// 先頭から要素を取り出す
raia_handle_t pop_plugin_list(PluginList *ls, bool *err) {
    raia_handle_t handle_ret = nth_plugin_list(ls, 0, err);
    if (*err) {
        delete_nth_plugin_list(ls, 0);
    }
    return handle_ret;
}

// リストは空か
bool empty_plugin_list(PluginList *ls) {
  return ls->top->next == NULL;
}

// リストの表示
void print_plugin_list(PluginList *ls) {
  //printf("( ");
  //for (Cell *cp = ls->top->next; cp != NULL; cp = cp->next)
  //  printf("%X ", cp->pfunc);
  //printf(")\n");
}

//== 関数の連結リスト

// コンストラクタ
static FuncCell *make_func_cell(duk_ret_t (*pfunc)(duk_context * ctx), FuncCell *cp) {
  FuncCell *newcp = malloc(sizeof(FuncCell));
  if (newcp != NULL) {
    newcp->pfunc = pfunc;
    newcp->next = cp;
  }
  return newcp;
}

FuncList *make_func_list(void) {
  FuncList *ls = malloc(sizeof(FuncList));
  if (ls != NULL) {
    ls->top = make_func_cell(0, NULL);  // ヘッダセルをセット
    if (ls->top == NULL) {
      free(ls);
      return NULL;
    }
  }
  return ls;
}

// 解放
static void delete_func_cell_(FuncCell *cp) {
  while (cp != NULL) {
    FuncCell *temp = cp->next;
    free(cp);
    cp = temp;
  }
}

void delete_func_list(FuncList *ls) {
  delete_func_cell_(ls->top);
  free(ls);
}

// n 番目のセルを返す
static FuncCell *nth_func_cell_(FuncCell *cp, int n) {
  for (int i = -1; cp != NULL; i++, cp = cp->next)
    if (i == n) break;
  return cp;
}

// n 番目の要素を返す
duk_ret_t (*nth_func_list(FuncList *ls, int n, bool *err)) (duk_context *ctx) {
  FuncCell *cp = nth_func_cell_(ls->top, n);
  if (cp == NULL) {
    *err = false;
    return 0;
  }
  *err = true;
  return cp->pfunc;
}

// n 番目に x を挿入
bool insert_nth_func_list(FuncList *ls, int n, duk_ret_t (*pfunc)(duk_context * ctx)) {
  FuncCell *cp = nth_func_cell_(ls->top, n - 1);
  if (cp == NULL) return false;
  cp->next = make_func_cell(pfunc, cp->next);
  return true;
}

// n 番目の要素を削除
bool delete_nth_func_list(FuncList *ls, int n) {
  FuncCell *cp = nth_func_cell_(ls->top, n - 1);
  if (cp == NULL || cp->next == NULL) return false;
  FuncCell *temp = cp->next;
  cp->next = cp->next->next;
  free(temp);
  return true;
}

// 先頭に追加
bool push_func_list(FuncList *ls, duk_ret_t (*pfunc)(duk_context * ctx)) {
  return insert_nth_func_list(ls, 0, pfunc);
}

// 先頭から要素を取り出す
duk_ret_t (*pop_func_list(FuncList *ls, bool *err)) (duk_context *ctx) {
  duk_ret_t (*pfunc)(duk_context * ctx) = nth_func_list(ls, 0, err);
  if (*err) delete_nth_func_list(ls, 0);
  return pfunc;
}

// リストは空か
bool empty_func_list(FuncList *ls) {
  return ls->top->next == NULL;
}

// リストの表示
void print_func_list(FuncList *ls) {
  //printf("( ");
  //for (Cell *cp = ls->top->next; cp != NULL; cp = cp->next)
  //  printf("%X ", cp->pfunc);
  //printf(")\n");
}

//======

void init_dlfcn(const char * dll_file) {
    plugin_list = make_plugin_list();
    func_list = make_func_list();
    push_plugin_list(plugin_list, raia_dlopen(dll_file)); //先頭に追加
    /// @TODO エラー処理
    //if (handle == 0) {
    //    fprintf(stderr, "%s\n", dlerror());
    //    return;
    //}
}

void close_dlfcn(void) {
    bool err;
    raia_handle_t handle = nth_plugin_list(plugin_list, 0, &err);
    if (raia_dlclose(handle) != 0) {
        /// @TODO エラー処理
        //fprintf(stderr, "%s\n", dlerror());
        return;
    }
}

raia_handle_t get_dlfcn_handle(void) {
    bool err;
    raia_handle_t handle = nth_plugin_list(plugin_list, 0, &err);
    return handle;
}

duk_ret_t (*add_dlfcn_func(duk_context *ctx, const char* dll_func_name)) (duk_context * ctx) {
    bool err_a;
    raia_handle_t handle = nth_plugin_list(plugin_list, 0, &err_a);
    duk_ret_t (*pfunc)(duk_context * ctx) = raia_dlsym(handle, dll_func_name);
    push_func_list(func_list, pfunc);
    bool err_b;
    pfunc = nth_func_list(func_list, 0, &err_b);
    return pfunc;
}
