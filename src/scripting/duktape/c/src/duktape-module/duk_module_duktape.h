//
// Created by dolphilia on 2022/12/10.
//

#if !defined(DUK_MODULE_DUKTAPE_H_INCLUDED)
#define DUK_MODULE_DUKTAPE_H_INCLUDED

#include "../duktape/duktape.h"

#if defined(__cplusplus)
extern "C" {
#endif

// 解決するCommonJSモジュール識別子の最大長。
// 長さには、現在のモジュールID、要求された（おそらく相対）モジュールID、およびその間のスラッシュの両方が含まれます。

#define  DUK_COMMONJS_MODULE_ID_LIMIT  256

extern void duk_module_duktape_init(duk_context *ctx);

#if defined(__cplusplus)
}
#endif  /* end 'extern "C"' wrapper */

#endif  /* DUK_MODULE_DUKTAPE_H_INCLUDED */
