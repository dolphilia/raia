//
// Duktape 1.x互換のモジュール読み込みフレームワーク
//

#include "../duktape/duktape.h"
#include "duk_module_duktape.h"

// (v)snprintf()はMSVC2015以前は欠番です。
// なお、_(v)snprintf()は切り捨て時にNUL終端しないが、ここでは問題ない。
// http://stackoverflow.com/questions/2915672/snprintf-and-visual-studio-2010

#if defined(_MSC_VER) && (_MSC_VER < 1900)
#define snprintf _snprintf
#endif

#if 0  /* Enable manually */
#define DUK__ASSERT(x) do { \
        if (!(x)) { \
            fprintf(stderr, "ASSERTION FAILED at %s:%d: " #x "\n", __FILE__, __LINE__); \
            fflush(stderr);  \
        } \
    } while (0)
#define DUK__ASSERT_TOP(ctx,val) do { \
        DUK__ASSERT(duk_get_top((ctx)) == (val)); \
    } while (0)
#else
#define DUK__ASSERT(x) do { (void) (x); } while (0)
#define DUK__ASSERT_TOP(ctx, val) do { (void) ctx; (void) (val); } while (0)
#endif

static void duk__resolve_module_id(duk_context *ctx, const char *req_id, const char *mod_id) {
    duk_uint8_t buf[DUK_COMMONJS_MODULE_ID_LIMIT];
    duk_uint8_t *p;
    duk_uint8_t *q;
    duk_uint8_t *q_last;  /* last component */
    duk_int_t int_rc;

    DUK__ASSERT(req_id != NULL);
    // mod_id は NULL かもしれない

    // アルゴリズムに関する注意点
    //
    // - 用語が'.'または'..'でない限り、ピリオドで始まることは許されません。
    //   これは実装を簡単にするためです（そしてCommonJSモジュールの仕様の範囲内です）。
    // - ここでは、出力の境界チェックはほとんどありません。
    //   これは意図的なもので、解決入力は長さチェックされ、出力が入力より長くなることはない。
    //   解決された出力は、アルゴリズムのどの時点でも入力より長くなることはないため、入力の上に直接書き込まれます。
    // - 非ASCII文字は個々のバイトとして処理されるため、特別な処理は必要ありません。
    //   ただし、U+0000はアルゴリズムを終了します。
    //   U+0000はいずれにせよ望ましい用語文字ではないので、これは問題ではありません。

    // 要求されたIDを直接（絶対または現在のモジュールパスがない場合）、または現在のモジュールIDを前置して（相対で現在のモジュールパスがある場合）、解像度入力を設定することです。
    // 現在のモジュールが「foo/bar」で、相対パスが「./quux」であるとする。
    // この場合、'bar'コンポーネントを置き換える必要があるため、初期入力は'foo/bar/.././quux'となります。

    if (mod_id != NULL && req_id[0] == '.') {
        int_rc = snprintf((char *) buf, sizeof(buf), "%s/../%s", mod_id, req_id);
    } else {
        int_rc = snprintf((char *) buf, sizeof(buf), "%s", req_id);
    }
    if (int_rc >= (duk_int_t) sizeof(buf) || int_rc < 0) {
        // 切り捨ての可能性があり、NULはいかなる場合も保証されない。
        // (int_rc < 0)のケースは、実際には発生しないはずです。
        goto resolve_error;
    }
    DUK__ASSERT(strlen((const char *) buf) < sizeof(buf));  // 最大でsizeof(buf) - 1となる。

    // 解決ループ:
    // ループの先頭には、'.'、'...'、またはピリオドで始まらない空でない識別子という有効な用語が求められます。

    p = buf;
    q = buf;
    for (;;) {
        duk_uint_fast8_t c;

        // ここで、'p'は常に用語の開始を指している。
        // また、ここでq_lastを無条件にリセットすることもできます。
        // これが最後の（空でない）項であれば、q_lastはループ終了時に正しい値を持つことになります。

        DUK__ASSERT(p >= q);  /* 解決中に出力が入力より長くなることはない */

        q_last = q;

        c = *p++;
        if (c == 0) {
            goto resolve_error;
        } else if (c == '.') {
            c = *p++;
            if (c == '/') {
                // 用語は'.'であり、完全に食べられている（重複するスラッシュを含む）。
                goto eat_dup_slashes;
            }
            if (c == '.' && *p == '/') {
                // 用語が「..」であったため、解決した名前を1つ分後ろにさかのぼります。
                //  q[-1] = 直前のスラッシュ (またはバッファの開始を超える)
                //  q[-2] = 直前のコンポーネントの最後の文字（またはバッファの開始位置を超えている）。
                p++;  // （最初の）入力スラッシュをたべる
                DUK__ASSERT(q >= buf);
                if (q == buf) {
                    goto resolve_error;
                }
                DUK__ASSERT(*(q - 1) == '/');
                q--;  // 最後の出力スラッシュまでバックトラックする（重複はすでに排除されている）。
                for (;;) {
                    // 前のスラッシュまたはバッファの開始位置までバックトラックする。
                    DUK__ASSERT(q >= buf);
                    if (q == buf) {
                        break;
                    }
                    if (*(q - 1) == '/') {
                        break;
                    }
                    q--;
                }
                goto eat_dup_slashes;
            }
            goto resolve_error;
        } else if (c == '/') {
            // 例：require('/foo')、空文字列は不可。
            goto resolve_error;
        } else {
            for (;;) {
                // 用語名を末尾または'/'までコピーします。
                *q++ = c;
                c = *p++;
                if (c == 0) {
                    // これが最後のタームであり、q_lastはループトップでこのタームに一致するように更新された。
                    goto loop_done;
                } else if (c == '/') {
                    *q++ = '/';
                    break;
                } else {
                    // 次のループに書き込む
                }
            }
        }

        eat_dup_slashes:
        for (;;) {
            /* eat dup slashes */
            c = *p;
            if (c != '/') {
                break;
            }
            p++;
        }
    }
    loop_done:
    // 出力#1：解決した絶対名
    DUK__ASSERT(q >= buf);
    duk_push_lstring(ctx, (const char *) buf, (size_t) (q - buf));

    // 出力#2：最後のコンポーネント名。 
    DUK__ASSERT(q >= q_last);
    DUK__ASSERT(q_last >= buf);
    duk_push_lstring(ctx, (const char *) q_last, (size_t) (q - q_last));
    return;

    resolve_error:
    (void) duk_type_error(ctx, "cannot resolve module id: %s", (const char *) req_id);
}

// インデックスを積み重ねて見やすくする.
#define DUK__IDX_REQUESTED_ID   0   // 要求されたモジュールID
#define DUK__IDX_REQUIRE        1   // 現在のrequire()関数
#define DUK__IDX_REQUIRE_ID     2   // 現在の require() 関数のベース ID、解決ベース
#define DUK__IDX_RESOLVED_ID    3   // 解決済み、正規化された絶対モジュールID
#define DUK__IDX_LASTCOMP       4   // 解決されたパスの最後のコンポーネント名
#define DUK__IDX_DUKTAPE        5   // duktapeオブジェクト
#define DUK__IDX_MODLOADED      6   // Duktape.modLoaded[]モジュールキャッシュ
#define DUK__IDX_UNDEFINED      7   // 'undefined'、ルックアップのアーティファクト
#define DUK__IDX_FRESH_REQUIRE  8   // モジュールに新しいrequire()関数を追加し、解像度ベースを更新しました。
#define DUK__IDX_EXPORTS        9   // デフォルトエクスポートテーブル
#define DUK__IDX_MODULE         10  // module.exports を含むモジュールオブジェクト

static duk_ret_t duk__require(duk_context *ctx) {
    const char *str_req_id;  // request識別子
    const char *str_mod_id;  // 現在のモジュールのrequire.id
    duk_int_t pcall_rc;

    // 注：不要なポップを避けることでコードサイズを最小化しようとするため、この関数ではスタックが少し乱雑に見える。
    // DUK__ASSERT_TOP() アサーションは、各ステップでスタックの構成が正しいことを保証するために使用されます。

    // モジュール識別子を正規の絶対形式に変換する。
    str_req_id = duk_require_string(ctx, DUK__IDX_REQUESTED_ID);
    duk_push_current_function(ctx);
    duk_get_prop_string(ctx, -1, "id");
    str_mod_id = duk_get_string(ctx, DUK__IDX_REQUIRE_ID);  // 非文字列を無視する
    duk__resolve_module_id(ctx, str_req_id, str_mod_id);
    str_req_id = NULL;
    str_mod_id = NULL;

    // [ requested_id require require.id resolved_id last_comp ]
    DUK__ASSERT_TOP(ctx, DUK__IDX_LASTCOMP + 1);

    // キャッシュ・モジュール・チェック。
    //
    // モジュールがロードされている場合、またはロードが終了せずに既にロードが開始されている場合は、同じキャッシュされた値（module.exports）を返す。
    // この値は、モジュールのロード開始時に登録されるため、循環参照にある程度対応することができる。

    duk_push_global_stash(ctx);
    duk_get_prop_string(ctx, -1, "\xff" "module:Duktape");
    duk_remove(ctx, -2);  // Duktape "オリジナルオブジェクトを検索します。
    duk_get_prop_string(ctx, DUK__IDX_DUKTAPE, "modLoaded");  // Duktape.modLoaded
    duk_require_type_mask(ctx, DUK__IDX_MODLOADED, DUK_TYPE_MASK_OBJECT);
    DUK__ASSERT_TOP(ctx, DUK__IDX_MODLOADED + 1);

    duk_dup(ctx, DUK__IDX_RESOLVED_ID);
    if (duk_get_prop(ctx, DUK__IDX_MODLOADED)) {
        // [ requested_id require require.id resolved_id last_comp Duktape Duktape.modLoaded Duktape.modLoaded[id] ]
        duk_get_prop_string(ctx, -1, "exports");  // return module.exports
        return 1;
    }
    DUK__ASSERT_TOP(ctx, DUK__IDX_UNDEFINED + 1);

    // [ requested_id require require.id resolved_id last_comp Duktape Duktape.modLoaded undefined ]

    // モジュールがロードされていない（以前にロードが開始されていない）。
    //
    // ロードするモジュールの解決済みIDを'id'に設定した新しいrequire()関数を作成する。
    // また、'exports' と 'module' テーブルを作成しますが、ロードされたテーブルにはまだ exports を登録しないようにします。
    // ユーザーモジュール検索コールバックがモジュールを見つけることに成功しない限り、それを実行したくありません。

    // 新鮮なrequire: require.idは設定可能なまま（書き込みはできない）なので、誤っていじってしまうことはありませんが、それでもObject.defineProperty()を使うことで可能なのです。
    // 
    // XXX: require.idは、（少なくともECMAScriptのコードからは）実際に触る理由がないので、設定不可能にすることもできます。
    duk_push_c_function(ctx, duk__require, 1 /*nargs*/);
    duk_push_string(ctx, "name");
    duk_push_string(ctx, "require");
    duk_def_prop(ctx, DUK__IDX_FRESH_REQUIRE,
                 DUK_DEFPROP_HAVE_VALUE);  /* not writable, not enumerable, not configurable */
    duk_push_string(ctx, "id");
    duk_dup(ctx, DUK__IDX_RESOLVED_ID);
    duk_def_prop(ctx, DUK__IDX_FRESH_REQUIRE, DUK_DEFPROP_HAVE_VALUE |
                                              DUK_DEFPROP_SET_CONFIGURABLE);  /* require.idを解決したターゲットモジュールidとした新しいrequire()です。 */

    // モジュールテーブル：
    // - module.exports: 初期エクスポートテーブル (ユーザーによって置き換えられるかもしれない)
    // - モジュール.idは、CommonJSの仕様では、可能であればこのようにすることが推奨されているため、書き込み不可、設定不可である。
    // - module.filename：設定されていない、modSearch()で明示的に設定されていない場合、解決されたIDがデフォルト（.fileNameではなく、Node.jsにマッチした大文字に注意）。
    // - module.name：設定されていない、modSearch()で明示的に設定されていない場合、解決されたIDの最後のコンポーネントをデフォルトとする。
    duk_push_object(ctx);  // exports
    duk_push_object(ctx);  // module
    duk_push_string(ctx, "exports");
    duk_dup(ctx, DUK__IDX_EXPORTS);
    duk_def_prop(ctx, DUK__IDX_MODULE, DUK_DEFPROP_HAVE_VALUE | DUK_DEFPROP_SET_WRITABLE |
                                       DUK_DEFPROP_SET_CONFIGURABLE);  // module.exports = exports
    duk_push_string(ctx, "id");
    duk_dup(ctx, DUK__IDX_RESOLVED_ID);  // resolved id: require(id)はこの同じモジュールを返さなければならない
    duk_def_prop(ctx, DUK__IDX_MODULE,
                 DUK_DEFPROP_HAVE_VALUE);  // module.id = resolved_id; 書き込み不可、列挙不可、設定不可
    duk_compact(ctx, DUK__IDX_MODULE);  // モジュールテーブルがmodLoadedに登録されたままなので、そのサイズを最小にする。
    DUK__ASSERT_TOP(ctx, DUK__IDX_MODULE + 1);

    // [ requested_id require require.id resolved_id last_comp Duktape Duktape.modLoaded undefined fresh_require exports module ]

    // modSearch()でも循環参照をサポートできるように、modLoaded[]にモジュールテーブルを早期に登録する。  エラーが発生した場合は、参照を削除するようにします。
    duk_dup(ctx, DUK__IDX_RESOLVED_ID);
    duk_dup(ctx, DUK__IDX_MODULE);
    duk_put_prop(ctx, DUK__IDX_MODLOADED);  /* Duktape.modLoaded[resolved_id] = module */

    // ユーザー提供のモジュール検索機能を呼び出し、ラップされたモジュールのソースコードを構築する（必要な場合）。
    // モジュール検索機能は、純粋なEcmacsript、純粋なC、および混合ECMAScript/Cモジュールを実装するために使用することができます。
    // 
    // モジュール検索機能は、エクスポートテーブルを直接操作することができます（例：DLLコードはエクスポートテーブルに値を登録することができます）。
    // また、モジュールのソースコードとして解釈される文字列を返すこともできます（文字列以外が返された場合、モジュールは純粋なC言語であるとみなされます）。 
    // モジュールが見つからない場合は、ユーザーコールバックによってエラーが投げられる必要があります。
    // Duktape.modLoaded[]にはすでにロード中のモジュールが含まれているため、Cモジュールの循環参照も機能するはずです（ただし、かなり稀なケースになると思われます）。

    duk_push_string(ctx, "(function(require,exports,module){");

    // Duktape.modSearch(resolved_id, fresh_require, exports, module). 
    duk_get_prop_string(ctx, DUK__IDX_DUKTAPE, "modSearch");  // Duktape.modSearch
    duk_dup(ctx, DUK__IDX_RESOLVED_ID);
    duk_dup(ctx, DUK__IDX_FRESH_REQUIRE);
    duk_dup(ctx, DUK__IDX_EXPORTS);
    duk_dup(ctx, DUK__IDX_MODULE);  // [ ... Duktape.modSearch resolved_id last_comp fresh_require exports module ]
    pcall_rc = duk_pcall(ctx, 4 /*nargs*/);  // -> [ ... source ]
    DUK__ASSERT_TOP(ctx, DUK__IDX_MODULE + 3);

    if (pcall_rc != DUK_EXEC_SUCCESS) {
        //Duktape.modLoaded[]のエントリーを削除し、rethrowする。
        goto delete_rethrow;
    }

    // ユーザーコールバックがソースコードを返さなかった場合、モジュールのロードは終了します（ユーザーコールバックはエクスポートテーブルを直接初期化します）。
    if (!duk_is_string(ctx, -1)) {
        // ユーザーコールバックはソースコードを返さなかったので、モジュールのロードは終了しています：modLoadedを最終モジュール.exportsで更新すれば完了です。
        goto return_exports;
    }

    // ラップされたモジュールのソースを完成させます。
    // モジュール内で定義された関数に設定されるように、module.filename を関数 .fileName として強制的に使用します。
    // これは、モジュール内で作成されたロガーが、デフォルトのロガー名としてモジュールID（またはオーバーライドされたファイル名）を取得することも保証します。
    // (大文字に注意: .filename は Node.js と一致し、.fileName は Duktape の他の場所で使用されます)。
    duk_push_string(ctx, "\n})");  // Newline は、モジュールの最終行に // コメントを含めることを可能にします。
    duk_concat(ctx, 3);
    if (!duk_get_prop_string(ctx, DUK__IDX_MODULE, "filename")) {
        // .fileNameの場合はmodule.filename、存在しない場合はresolved IDがデフォルトとなります。
        duk_pop(ctx);
        duk_dup(ctx, DUK__IDX_RESOLVED_ID);
    }
    pcall_rc = duk_pcompile(ctx, DUK_COMPILE_EVAL);
    if (pcall_rc != DUK_EXEC_SUCCESS) {
        goto delete_rethrow;
    }
    pcall_rc = duk_pcall(ctx, 0);  // -> eval関数ラッパー（未呼び出し）
    if (pcall_rc != DUK_EXEC_SUCCESS) {
        goto delete_rethrow;
    }

    // モジュールは、ラップされたモジュール関数に評価されるようになりました。
    // スタックトレースにも表示されるように、その .name を module.name (デフォルトは解決された ID の最後のコンポーネント) と一致させるように強制します。 
    // 関数スコープに実際の名前バインディングを導入してはいけないことに注意してください（通常、名前付き関数の場合）。
    // これは、モジュールが見るスコープに影響を与え、同じ名前のグローバルへのシャドウアクセスになるからです。
    // このため、関数を匿名としてコンパイルし、"has name binding "フラグを設定せずに.nameを強制的に設定することで、これを実現しています。

    duk_push_string(ctx, "name");
    if (!duk_get_prop_string(ctx, DUK__IDX_MODULE, "name")) {
        // .nameをmodule.name、存在しない場合は最後のコンポーネントをデフォルトとします。
        duk_pop(ctx);
        duk_dup(ctx, DUK__IDX_LASTCOMP);
    }
    duk_def_prop(ctx, -3, DUK_DEFPROP_HAVE_VALUE | DUK_DEFPROP_FORCE);

    // ラップされたモジュール関数を呼び出す。
    //
    // モジュールがエラーを投げてもDuktape.modLoaded[resolved_id]を更新できるように、protectedコールを使用する。

    // [ requested_id require require.id resolved_id last_comp Duktape Duktape.modLoaded undefined fresh_require exports module mod_func ] 
    DUK__ASSERT_TOP(ctx, DUK__IDX_MODULE + 2);

    duk_dup(ctx, DUK__IDX_EXPORTS);  // exports (this binding) 
    duk_dup(ctx, DUK__IDX_FRESH_REQUIRE);  // fresh require (argument) 
    duk_get_prop_string(ctx, DUK__IDX_MODULE,
                        "exports");  // modSearchによって変更された場合に備えて、module.exportsからexportsを再調査する。
    duk_dup(ctx, DUK__IDX_MODULE);  // モジュール（引数）
    DUK__ASSERT_TOP(ctx, DUK__IDX_MODULE + 6);

    // [ requested_id require require.id resolved_id last_comp Duktape Duktape.modLoaded undefined fresh_require exports module mod_func exports fresh_require exports module ]

    pcall_rc = duk_pcall_method(ctx, 3 /*nargs*/);
    if (pcall_rc != DUK_EXEC_SUCCESS) {
        // モジュールの読み込みに失敗しました。
        // Node.jsはモジュールの登録を忘れてしまうので、別のrequire()が再度モジュールを読み込もうとします。
        // その挙動を真似てください。
        goto delete_rethrow;
    }

    // [ requested_id require require.id resolved_id last_comp Duktape Duktape.modLoaded undefined fresh_require exports module result(ignored) ]
    DUK__ASSERT_TOP(ctx, DUK__IDX_MODULE + 2);

    // fall through

    return_exports:
    duk_get_prop_string(ctx, DUK__IDX_MODULE, "exports");
    duk_compact(ctx, -1);  // エクスポートテーブルをコンパクトにする
    return 1;  // return module.exports

    delete_rethrow:
    duk_dup(ctx, DUK__IDX_RESOLVED_ID);
    duk_del_prop(ctx, DUK__IDX_MODLOADED);  // delete Duktape.modLoaded[resolved_id] 
    (void) duk_throw(ctx);  // 元の誤りを撤回する
    return 0;  // 届かない
}

void duk_module_duktape_init(duk_context *ctx) {
    // 修正された場合に備えて「Duktape」をためておく。
    duk_push_global_stash(ctx);
    duk_get_global_string(ctx, "Duktape");
    duk_put_prop_string(ctx, -2, "\xff" "module:Duktape");
    duk_pop(ctx);

    // require`をグローバル関数として登録する。
    duk_eval_string(ctx,
                    "(function(req) {"
                    "    var D = Object.defineProperty;"
                    "    D(req, 'name', {value: 'require'});"
                    "    D(this, 'require', {value: req, writable: true, configurable: true});"
                    "    D(Duktape, 'modLoaded', {value: Object.create(null), writable: true,configurable: true});"
                    "})");
    duk_push_c_function(ctx, duk__require, 1 /*nargs*/);
    duk_call(ctx, 1);
    duk_pop(ctx);
}

#undef DUK__ASSERT
#undef DUK__ASSERT_TOP
#undef DUK__IDX_REQUESTED_ID
#undef DUK__IDX_REQUIRE
#undef DUK__IDX_REQUIRE_ID
#undef DUK__IDX_RESOLVED_ID
#undef DUK__IDX_LASTCOMP
#undef DUK__IDX_DUKTAPE
#undef DUK__IDX_MODLOADED
#undef DUK__IDX_UNDEFINED
#undef DUK__IDX_FRESH_REQUIRE
#undef DUK__IDX_EXPORTS
#undef DUK__IDX_MODULE
