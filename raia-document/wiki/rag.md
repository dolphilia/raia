
## 文字コード

- utf-8

## スクリプトファイルの拡張子

- `.rag`
- `.rags`

# スクリプトの文法

## トークン

### 空白

- `LF`: `0x0A`
- `CR`: `0x0D`
- `EOL`: `<LF>`, `<CR>`, `<CR><LF>` のいずれか 
- `TAB_H`: `0x09`
- `TAB_V`: `0x0B`
- `TAB`: `<TAB_H>`, `<TAB_V>` のいずれか
- `FF`: `0x0C`
- `SPACE_ASCII`: `0x20`。行頭に4つ以上連続して存在すると新しいスクリプト行として解釈されます。
- `SPACE_UTF8_2BYTE`: `0xC2A0`
- `SPACE_UTF8_3BYTE`: `0xE38080`
- `BLANK`: `<SPACE_ASCII>`, `<EOL>`, `<TAB>`, `<FF>` のいずれか。文字列や他のトークンの間隔を開ける役割をする。

### 記号

- `DOT`: `.`
- `COMMA`: `,`
- `EQUAL`: `=`
- `SQUARE_L`: `[`
- `SQUARE_R`: `]`
- `CURLY_L`: `{`
- `CURLY_R`: `}`
- `ANGLE_L`: `<`
- `ANGLE_R`: `>`
- `ROUND_L`: `(`
- `ROUND_R`: `)`
- `PLUS`: `+`
- `HYPHEN`: `-`
- `ASTERISK`: `*`
- `SLASH`: `/`
- `BACK_SLASH`: `\`
- `SEMICOLON`: `;`
- `COLON`: `:`
- `DOLLAR`: `$`
- `PERCENT`: `%`
- `SHARP`: `#`
- `QUOTE_SINGLE`: `'`
- `QUOTE_DOUBLE`: `"`
- `QUOTE_BACK`: `` ` ``
- `UNDERSCORE`: `_`
- `QUESTION`: `?`
- `EXCLAMATION`: `!`
- `AND`: `&`
- `AT`: `@`
- `HAT`: `^`
- `TILDE`: `~`
- `OR`: `|`

### エスケープ文字

- `ESC_LF`: `\n`。文字列か`<NOVEL_MESSAGE_KEYS>`に使用する。それ以外のコンテキストでは使用できない。
- `ESC_CR`: `\r`。文字列か`<NOVEL_MESSAGE_KEYS>`に使用する。それ以外のコンテキストでは使用できない。
- `ESC_TAB`: `\t`。文字列か`<NOVEL_MESSAGE_KEYS>`に使用する。それ以外のコンテキストでは使用できない。
- `ESC_QUOTE_SINGLE`: `\'`。文字列か`<NOVEL_MESSAGE_KEYS>`に使用する。それ以外のコンテキストでは使用できない。
- `ESC_QUOTE_DOUBLE`: `\"`。文字列か`<NOVEL_MESSAGE_KEYS>`に使用する。それ以外のコンテキストでは使用できない。
- `ESC_BACK_SLASH`: `\\`。文字列か`<NOVEL_MESSAGE_KEYS>`に使用する。それ以外のコンテキストでは使用できない。
- `ESC_CHAR`: `<ESC_LF>`, `<ESC_CR>`, `<ESC_TAB>`, `<ESC_QUOTE_SINGLE>`, `<ESC_QUOTE_DOUBLE>`, `<ESC_BACK_SLASH>` のいずれか。文字列か`<NOVEL_MESSAGE_KEYS>`に使用する。それ以外のコンテキストでは使用できない。

### メッセージ用の記号

- `MESSAGE_SYMBOL_NON_TOP`: `<ASTERISK>`, `<SEMICOLON>`, `<SHARP>`, `<AT>`, `<HAT>`。`<NOVEL_MESSAGE_KEYS>`に使用する。先頭には使用しない。
- `MESSAGE_SYMBOL`: `<DOT>`, `<COMMA>`, `<EQUAL>`, `<ROUND_L>`, `<ROUND_R>`, `<PLUS>`, `<HYPHEN>`, `<SLASH>`, `<COLON>`, `<DOLLAR>`, `<PERCENT>`, `<UNDERSCORE>`, `<QUESTION>`, `<EXCLAMATION>`, `<AND>`, `<TILDE>`, `<OR>` のいずれか。`<NOVEL_MESSAGE_KEYS>`に使用する。

### アルファベット

- `ALPHABET`: `a-z`、`A-Z` のいずれか。アルファベッドは変数名や関数名などの識別子に使用され、小文字と大文字を区別します。

### UTF-8

- `U1`: `0x80`から`0xBF`のいずれか（続くバイト）
- `U2`: `0xC2`から`0xDF`のいずれか（2バイト文字の最初のバイト）
- `U3`: `0xE0`、`0xE1`から`0xEC`、`0xEE`、`0xEF`のいずれか（3バイト文字の最初のバイト）
- `U4`: `0xF0`から`0xF4`のいずれか（4バイト文字の最初のバイト）
- `UTF8_TWO_BYTE`: `<U2><U1>`（2バイトのUTF-8文字）
- `UTF8_THREE_BYTE`: `<U3><U1><U1>`（3バイトのUTF-8文字）
- `UTF8_FOUR_BYTE`: `<U4><U1><U1><U1>`（4バイトのUTF-8文字）
- `UTF8`: `<UTF8_TWO_BYTE>`, `<UTF8_THREE_BYTE>`, `<UTF8_FOUR_BYTE>` のいずれか

### 予約語

- `NONE`: `none`
- `NULL`: `null`
- `BOOLEAN`: `true`、`false` のいずれか
- `IF_START`: `if`
- `IF_END`: `endif`
- `IGNORE_START`: `ignore`
- `IGNORE_END`: `endignore`
- `MACRO_START`: `macro`
- `MACRO_END`: `endmacro`
- `SCRIPT_START`: `script`, `iscript` のいずれか
- `SCRIPT_END`: `endscript`, `endiscript` のいずれか
- `LINK_START`: `link`
- `LINK_END`: `endlink`
- `RETURN`: `return`
- `STOP`: `stop`, `s`のいずれか

### 数値

- `DIGIT_NON_ZERO`: `1`, `2`, `3`, `4`, `5`, `6`, `7`, `8`, `9` のいずれか。1から9までの任意の数字を指す。
- `DIGIT`: `0`, `<DIGIT_NON_ZERO>` のいずれか
- `DIGITS`: `<DIGIT>`の1つ以上の連続
- `INTEGER`: `<DIGIT>` または `<DIGIT_NON_ZERO><DIGITS>`
- `FLOAT`: `<DIGITS><DOT><DIGITS>`
- `DIGIT_HEX`: `<DIGIT>`, `a`, `b`, `c`, `d`, `e`, `f`, `A`, `B`, `C`, `D`, `E`, `F` のいずれか
- `DIGITS_HEX`: `<DIGIT_HEX>`の1つ以上の連続
- `NUMERAL_HEX`: `0x<DIGITS_HEX>`, `0X<DIGITS_HEX>`
- `SIGN`: `<PLUS>`, `<HYPHEN>` のいずれか
- `SIGNED_INTEGER`: `<SIGN><INTEGER>`
- `SIGNED_FLOAT`: `<SIGN><FLOAT>`

### 色

- `HEX_COLOR_RRGGBB`: `<SHARP><DIGIT_HEX><DIGIT_HEX><DIGIT_HEX><DIGIT_HEX><DIGIT_HEX><DIGIT_HEX>`

## 文法

- `RAG_SCRIPT`: `<BLANK_BLOCK>`, `<SCRIPT_STRING_BLOCK>`, `<NOVEL_BLOCK>`,  で構成される
- `BLANK_BLOCK`: `<BLANK_LINE>` の連続が1つ以上
- `SCRIPT_STRING_BLOCK`: `<SCRIPT_STRING_LINE>` の連続が1つ以上
- `NOVEL_BLOCK`: `<NOVEL_LINE>` の連続が1つ以上
- `BLANK_LINE`: `<BLANK>` で構成される行

- `SCRIPT_STRING_LINE`: `<SPACE_ASCII>`が行頭から連続して4つ以上ある行末までの文字列。
- `SCRIPT_KEYS`: `<ALPHABET>`, `<DIGIT>`, `<UNDERSCORE>`, `<UTF8>`の1つ以上の連続

- `NOVEL_LINE`: `<SPACE_ASCII>`が存在しないか、行頭から０個から3個が連続してあった場合、その後`<NOVEL_ELEMENTS>`で構成される行
- `NOVEL_ELEMENTS`: `<NOVEL_ELEMENT>`の連続が1つ以上
- `NOVEL_ELEMENT`: `<NOVEL_COMMAND>`、`<NOVEL_STRING>`、`<NOVEL_LABEL>`、`<NOVEL_SCRIPT_BLOCK>`、`<NOVEL_MACRO_BLOCK>`、`<NOVEL_LINK_BLOCK>`、`<NOVEL_SUBROUNTINE>`、`<NOVEL_IF_BLOCK>`、`<NOVEL_IGNORE_BLOCK>`、 `<NOVEL_COMMENT    >`、`<NOVEL_MESSAGE>` のいずれか
- `NOVEL_MESSAGE`: `<NOVEL_MESSAGE_KEYS>`で構成される。`<NOVEL_COMMAND>`、`<NOVEL_LABEL>`、`<NOVEL_COMMENT>`、`<NOVEL_SCRIPT_BLOCK>` に該当しない
- `NOVEL_COMMENT`: `<NOVEL_HAT_COMMENT>`, `<NOVEL_SEMICOLON_COMMENT>` のいずれか
- `NOVEL_HAT_COMMENT`: `<HAT>`から行末まで。`<NOVEL_SCRIPT_BLOCK>`と`<NOVEL_STRING>`内を除く
- `NOVEL_SEMICOLON_COMMENT`: 行頭の`<SEMICOLON>`から行末まで。`<NOVEL_SCRIPT_BLOCK>`と`<NOVEL_STRING>`内を除く
- `NOVEL_IGNORE_BLOCK`: `<IGNORE_START>`命令から`<IGNORE_END>`命令まで。間にはラベルを挟まないように。
- `NOVEL_IF_BLOCK`: `<IF_START>`命令から`<IF_END>`命令まで。間にはラベルを挟んではいけない。
- `NOVEL_SUBROUTINE`: `<NOVEL_LABEL>`から`<NOVEL_SUBROUTINE_END>`まで
- `NOVEL_SUBROUTINE_END`: `<RETURN>`命令あるいは`<STOP>`命令、またはファイル末尾
- `NOVEL_LINK_BLOCK`: `<LINK_START>`命令から`<LINK_END>`命令まで
- `NOVEL_MACRO_ATTRIBUTE_ALL`: `<NOVEL_MACRO_BLOCK>`内の`<NOVEL_COMMAND>`の`<NOVEL_COMMAND_NAME>`の次の`<ASTERISK>`。例: `[macro name=""new_macro][move *][endmacro]`における`*`が該当します。
- `NOVEL_MACRO_ATTRIBUTE_DEFAULT`: `<NOVEL_MACRO_ATTRIBUTE_VALUE>`の次が`<OR>`であった場合の次の`<NOVEL_KEYS>`。例: `[macro name="new_macro"][move time=%t|2000][endmacro]`における`2000`が該当します。
- `NOVEL_MACRO_ATTRIBUTE_VALUE`: `<NOVEL_MACRO_BLOCK>`でのみ使用できる`<NOVEL_COMMAND_ATTRIBUTE>`。必ず`%`で始まる。例: `[macro name="new_macro"][move time=%t][endmacro]`における`%t`が該当します
- `NOVEL_MACRO_BLOCK`: `<MACRO_START>`命令から`<MACRO_END>`命令まで
- `NOVEL_SCRIPT_BLOCK`: `<SCRIPT_START>`命令から`<SCRIPT_END>`命令に囲まれた文字列
- `NOVEL_SAVE_NAME`: `<NOVEL_LABEL_NAME>`の次の`<NOVEL_KEYS>`または`<NOVEL_ENTITY>`。ただし`<NOVEL_LABEL_NAME>`と`<KAB_SAVE_NAME>`の間には`|`が必要。例:`*label|save_name`における`save_name`が該当します。
- `NOVEL_LABEL_NAME`: `<NOVEL_LABEL>`内の最初の`<NOVEL_KEYS>`。ただし、直前の`<NOVEL_LABEL_NAME>`が必要な場合もあります。
- `NOVEL_LABEL`: `<NOVEL_LABEL_TOP_FILE>`あるいは`<NOVEL_LABEL_NOMAL>`
- `NOVEL_LABEL_NORMAL`: 行頭が `<ASTERISK>` で始まる行
- `NOVEL_LABEL_TOP_FILE`: ファイルの最初の行を示すラベル。
- `NOVEL_STRING`: `<NOVEL_STRING_SINGLE>`、`<NOVEL_STRING_DOUBLE>` のどちらか
- `NOVEL_STRING_DOUBLE`: `"` で囲まれた文字列。内包する`'`、`\"`は文字列とみなされる。ネストは許可されない。
- `NOVEL_STRING_SINGLE`: `'` で囲まれた文字列。内包する`"`、`\'`は文字列とみなされる。ネストは許可されない。
- `NOVEL_COMMAND_ATTRIBUTE_VALUE`: `<NOVEL_COMMAND_ATTRIBUTE>`の等式の右辺。例: `[move time=2000]`における`2000`が該当します。
- `NOVEL_COMMAND_ATTRIBUTE_NAME`: `<NOVEL_COMMAND_ATTRIBUTE>`の等式の左辺。例: `[move time=2000]`における`time`が該当します。
- `NOVEL_COMMAND_ATTRIBUTE`: `<NOVEL_COMMAND_NAME>`の後ろに続く`<NOVEL_KEYS><EQUAL><NOVEL_KEYS>`形式の等式。等式中の空白文字は無視されます。例：`[move time=2000]`における`time=2000`が該当します。
- `NOVEL_COMMAND_NAME`: `<NOVEL_COMMAND>`の最初の`<NOVEL_KEYS>`
- `NOVEL_COMMAND`: 「x」命令の形式で記述される要素。`<NOVEL_COMMAND_SQUARE_BRACKET>`あるいは`<NOVEL_COMMAND_AT>`である。`[` ``NOVEL_COMMAND_NAME` `...` `]` あるいは`@` `NOVEL_COMMAND_NAME` `...`の形式を取る。
- `NOVEL_COMMAND_AT`: `<at><NOVEL_COMMAND_NAME>`、あるいは `<at><NOVEL_COMMAND_NAME><NOVEL_COMMAND_ATTRIBUTE>+`
- `NOVEL_COMMAND_SQUARE_BRACKET`: `<SQUARE_L><NOVEL_COMMAND_NAME><SQUARE_L>`, または`<SQUARE_L><NOVEL_COMMAND_NAME><NOVEL_COMMAND_ATTRIBUTE>+<SQUARE_R>`。ただし`[[`、`\[`にはマッチしない。
- `NOVEL_ENTITY`: `&f.<NOVEL_KEYS>`, `&sf.<NOVEL_KEYS>`, `&tf.<NOVEL_KEYS>`, `&kag.<NOVEL_KEYS>`のいずれか
- `NOVEL_MESSAGE_KEYS`: `<ALPHABET>`, `<DIGIT>`, `<UTF8>`, `<ESC_CHAR>`, `<MESSAGE_SYMBOL>`, のいずれか、続いて`<ALPHABET>`, `<DIGIT>`, `<UNDERSCORE>`, `<UTF8>`, `<MESSAGE_SYMBOL>`、`<MESSAGE_SYMBOL_NON_TOP>`の０以上の連続。
- `NOVEL_KEYS`: `<ALPHABET>`, `<DIGIT>`, `<UNDERSCORE>`, `<UTF8>`, から構成されるキー



## 吉里吉里のKAGと違うところ

- 自動改行、手動改行の切り替え

## ティラノスクリプト拡張記法

- `#`+名前でキャラクター名を指定できる
- `#`+名前+`:`+表情など で表情を指定できる

## 拡張記法

- `MESSAGE_BLOCK`: `message`命令から`endmessage`命令まで
- `@script`命令。
- スクリプトの途中の行末に`\`を挿入ことで、スクリプトを複数行に渡って記述できる
- 終了命令に`end...`の代わりに`[/if]`を指定できる
- インデントで命令記号を省略してスクリプトで記述できる
- `if {} macro {} ignore {}`が使える。
- `for` `while` などが使える
- `iscript`、`endscript`は無視される。
- スクリプト中はスクリプトに準拠するが基本的に、`//`,`/**/`, `#`コメントを使える
- `\{\{script\}\}`でスクリプトを呼び出せる。`@eval`と同等。
- `[?mruby ?]`
- キャラ名：行頭+KEYS+`:` + `\n | (...)` でキャラ名の指定ができる。`:`の後にKEYSが来てはいけない。
- `キャラ名.表情:` で表情を指定できる
- 表情指定：キャラ名指定ののち`(...)`の間に表情指定などができる
- ボイス指定：表情指定ののちに`{...}`でボイス形式でアニメーションなどを指定できる
- キャラ名と同等の記法でメッセージとして`:`を使用したい時は`\:`を用いる。
- メッセージ行
- メッセージブロック: メッセージ行の連続、空白行または命令、インデントブロック、あるいは末尾まで
- メッセージ内に`$(x)`で表情差分、`${x}`でボイス、`$<x>`で特殊演出、`\{\{script\}\}`でスクリプト
- メッセージ内に指定がなければ、事前予約された表情、
- `-` リストでリンクの分岐が作れる（？）
- `[1]` 命令名の部分が数値だったばあいは予約参照

## メモ

- [eval exp="f.flag1 = 1000"]でスクリプトの式を計算できる
    - ゲーム変数であれば f. を、システム変数であれば sf. を、一時変数であれば tf. を付けます
    - kag. はKAGシステムへのアクセスに使われる
    - delete var で変数削除
    - [emb exp="f.var"]で変数の内容を表示
    - [font size="&f.fontsize"] のように& の後に書かれた属性の値の内容を、TJS2 式として実行して、その結果で属性の値を置き換える
- cond 属性には TJS式 を指定し、この式を評価した結果が真の時のみにその命令が実行されます
    - `macro endmacro if else elsif endif ignore endignore iscript endscript` の命令をのぞく
- 音声と表情の同期。

### 演算子

- `GROUPING`: `( ... )`。結合性はなし。
- `LOGICAL_NOT`: `! ...`。結合性は右から左。
- `UNARY_NEGATION`: `- ...`。結合性は右から左。
- `EXPONENTIATION`: `... ** ...`。結合性は右から左。
- 乗除算余剰演算子 (*, /, %)結合性は左から右。
- 加減算演算子 (+, -)結合性は左から右。
- 比較演算子（例： >, <, >=, <=）結合性は左から右。
- 等価不等価（==, !=）結合性は左から右。
- 論理AND (&&)結合性は左から右。
- 論理OR (||)。結合性は左から右。
- 代入演算子 (=)。結合性は右から左。

```

先生: ()
わたしもやき{1}が回ったってことかしら？
そうでもなければだ{2}ものね。
でも、そう{3}かんがえると

それでは・・・そういうことかもしれない。

私: (face normal) {voice 0%:"78", 50%:happy, 9%:shy}
そういうことであれば、{{script}}

少女: (face) {voice}
$(1)なるほど、わかりました。
$(2)そういうことであれば、気をつけます。
$(3)あなたもがんばってください。

少女: {
    character: {

    },

}

```

## TOML

### TOMLのトークン

- `TOML_COMMENT`: `#` から行末まで
- `TOML_KEY`: `"`で囲まれた任意の文字列、またはアルファベット、数字、アンダースコア、ハイフンの連続
- `TOML_NUMBER`:  浮動小数点数または整数。数字とアンダースコアの連続で、アンダースコアは数字の間にだけ現れます。
- `TOML_BOOLEAN`: trueまたはfalse
- `TOML_DATE`: 日付
- `TOML_DOT`: `.`
- `TOML_COMMA`: `,`
- `TOML_EQ`: `=`
- `TOML_LBRACKET`: `[`
- `TOML_RBRACKET`: `]`
- `TOML_LBRACE`: `(`
- `TOML_RBRACE`: `)`

### TOMLの文法

- `TOML_VALUE`: `TOML_KEY`、`TOML_NUMBER`、`TOML_BOOLEAN`、`TOML_DATE`、`TOML_ARRAY`、`TOML_INLINE_TABLE` のいずれかです。
- `TOML_ARRAY`: `[]`で囲まれた`TOML_VALUE`のリストです。リスト内の値は`,`で区切られます。
- `TOML_INLINE_TABLE`: `{}`で囲まれた`TOML_KEY_VALUE`のリストです。リスト内の`TOML_KEY_VALUE`は`,`で区切られます。ただし、`TOML_INLINE_TABLE`は単一行に収めるべきです。
- `TOML_KEY_VALUE`: `TOML_KEY_OR_STR`、`=`、`TOML_VALUEで`で構成されます。
- `TOML_TABLE_ENTRIES`: 0つ以上の`TOML_KEY_VALUE`からなるリストです。
- `TOML_PATH`: `TOML_KEY_OR_STR`、`.`、`TOML_KEY_OR_STR`が0回以上続く形式です。
- `TOML_TABLE_HEADER`: `[]`で囲まれた`TOML_PATH`です。
- `TOML_TABLE_ARRAY_HEADER`: `[[]]`で囲まれた`TOML_PATH`です。
- `TOML_TABLE_ARRAY`: `TOML_TABLE_ARRAY_HEADER`と`TOML_TABLE_ENTRIES`で構成されます。
- `TOML_TABLE`: `TOML_TABLE_HEADER`と`TOMLE_TABLE_ENTRIES`で構成されます。
- `TOML_EXPRESSION`: `TOML_KEY_VALUE`、`TOML_TABLE`、`TOML_TABLE_ARRAY`のいずれかです。
- `TOML_CONTENT`: 0個つ以上の`TOML_EXPRESSION`で構成されます