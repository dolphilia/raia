/* flex lexer.l */
/* gcc lex.yy.c -ll -o lexer */

%option 8bit

%{
#include "parser.tab.h"
#include <stdio.h>
#include <stdlib.h>
%}

/* コメント */
COMMENT             ^";".+
HAT_COMMENT         "^".+

/* ラベル */
LABEL               ^"*"

/* 空白 */
LF                  "\x0A"
CR                  "\x0D"
EOL                 {CR}{LF}|{LF}|{CR}
TAB_H               "\x09"
TAB_V               "\x0B"
TAB                 {TAB_H}|{TAB_V}
FF                  "\x0C"
SPACE_ASCII         "\x20"
SPACE_UTF8_2BYTE    "\xC2A0"
SPACE_UTF8_3BYTE    "\xE38080"
BLANK               {SPACE_ASCII}|{EOL}|{TAB}|{FF}
BLANK_LINE          ^{BLANK}+{EOL}
SPACE_STRING        {SPACE_ASCII}{SPACE_UTF8_2BYTE}{SPACE_UTF8_3BYTE}

/* 位置 */
NOT_INDENT          {SPACE_ASCII}{0,3}
INDENT              ^{SPACE_ASCII}{4}+

/* 記号 */
DOT                 "\."
COMMA               ","
EQUAL               "="
SQUARE_L            "\["
SQUARE_R            "\]"
CURLY_L             "\{"
CURLY_R             "\}"
ANGLE_L             "\<"
ANGLE_R             "\>"
ROUND_L             "\("
ROUND_R             "\)"
PLUS                "\+"
MINUS               "-"
MUL                 "\*"
SLASH               "/"
BACK_SLASH          "\\"
SEMICOLON           ";"
COLON               ":"
DOLLAR              "\$"
PERCENT             "%"
SHARP               "#"
QUOTE_SINGLE        "'"
QUOTE_DOUBLE        "\""
QUOTE_BACK          "`"
UNDERSCORE          "_"
QUESTION            "?"
NOT                 "!"
AND                 "&"
AT                  "@"
HAT                 "\^"
TILDE               "~"
OR                  "\|"
SYMBOL_STRING       {DOT}|{COMMA}|{EQUAL}|{SQUARE_L}|{SQUARE_R}|{CURLY_L}|{CURLY_R}|{ANGLE_L}|{ANGLE_R}|{ROUND_L}|{ROUND_R}|{PLUS}|{MINUS}|{MUL}|{SLASH}|{BACK_SLASH}|{SEMICOLON}|{COLON}|{DOLLAR}|{PERCENT}|{SHARP}|{QUOTE_SINGLE}|{QUOTE_BACK}|{UNDERSCORE}|{QUESTION}|{NOT}|{AND}|{AT}|{HAT}|{TILDE}|{OR}

AT_TOL              ^{NOT_INDENT}{AT}

/* 2文字以上の記号 */
MUL_MUL             "**"
INCREMENT           "++"
DECREMENT           "--"
ANGLE_L_EQUAL       "<="
ANGLE_R_EQUAL       ">="
EQUAL_EQUAL         "=="
NOT_EQUAL           "!="
AND_AND             "&&"
OR_OR               "\|\|"
PLUS_EQUAL          "+="
MINUS_EQUAL         "-="
MUL_MUL_EQUAL       "**="
MUL_EQUAL           "*="
SLASH_EQUAL         "/="
PERCENT_EQUAL       "%="
AND_EQUAL           "&="
HAT_EQUAL           "^="
OR_EQUAL            "\|="
AND_AND_EQUAL       "&&="
OR_OR_EQUAL         "\|\|="
Q_Q_EQUAL           "??="
ARROW               "=>"
ARROW_SINGLE        "->"
SPREAD              "..."

/* 演算子 */
OPERATOR        [+\-*/%()[]]|{MUL_MUL}

/* エスケープ文字 */
ESC_LF              "\\n"
ESC_CR              "\\r"
ESC_TAB             "\\t"
ESC_QUOTE_SINGLE    "\\'"
ESC_QUOTE_DOUBLE    "\\\""
ESC_BACK_SLASH      "\\\\"
ESC_CHAR            {ESC_LF}|{ESC_CR}|{ESC_TAB}|{ESC_QUOTE_SINGLE}|{ESC_QUOTE_DOUBLE}|{ESC_BACK_SLASH}

/* アルファベット */
ALPHABET            [a-zA-Z]

/* UTF8 */
U1                  [\x80-\xBF]
U2                  [\xC2-\xDF]
U3                  [\xE0-\xE1\xE2-\xEC\xEE-\xEF]
U4                  [\xF0-\xF4]
UTF8_TWO_BYTE       {U2}{U1}
UTF8_THREE_BYTE     {U3}{U1}{U1}
UTF8_FOUR_BYTE      {U4}{U1}{U1}{U1}
UTF8                {UTF8_TWO_BYTE}|{UTF8_THREE_BYTE}|{UTF8_FOUR_BYTE}

/* 数値 */
ZERO                [0]
DIGIT_NON_ZERO      [1-9]
DIGIT               [0]|{DIGIT_NON_ZERO}
DIGITS              {DIGIT}+
INTEGER             {DIGITS}|{DIGIT_NON_ZERO}{DIGITS}
FLOAT               {DIGITS}\.{DIGITS}
SIGN                \+|\-
SIGNED_INTEGER      {SIGN}{INTEGER}
SIGNED_FLOAT        {SIGN}{FLOAT}
NUMBER              {INTEGER}|{FLOAT}
DIGIT_HEX           {DIGIT}|[a-fA-F]
DIGITS_HEX          {DIGIT_HEX}+
NUMERAL_HEX         0x{DIGITS_HEX}|0X{DIGITS_HEX}

/* 色 */
HEX_COLOR           #{DIGIT_HEX}{6}

/* KAGメッセージ用の記号 */
/* |{HAT} */
MESSAGE_SYMBOL_NG_TOP   {MUL}|{SEMICOLON}|{SHARP}|{AT}|{SPACE_ASCII}
MESSAGE_SYMBOL_OK_TOP   {QUOTE_SINGLE}|{QUOTE_DOUBLE}|{DOT}|{COMMA}|{EQUAL}|{ROUND_L}|{ROUND_R}|{PLUS}|{MINUS}|{SLASH}|{COLON}|{DOLLAR}|{PERCENT}|{UNDERSCORE}|{QUESTION}|{NOT}|{AND}|{TILDE}|{OR}
MESSAGE_OK_TOP          {MESSAGE_SYMBOL_OK_TOP}|{UTF8}|{DIGIT}|{ALPHABET}
MESSAGE_MIX             {MESSAGE_SYMBOL_NG_TOP}|{MESSAGE_OK_TOP}
MESSAGE                 {MESSAGE_OK_TOP}+|{MESSAGE_OK_TOP}{MESSAGE_MIX}+

/* 予約語 */
NONE            "none"
NULL            "null"
TRUE            "true"
FALSE           "false"
BOOLEAN         {TRUE}|{FALSE}
IF_START        "if"
IF_END          "endif
IGNORE_START    "ignore
IGNORE_END      "endignore"
MACRO_START     "macro"
MACRO_END       "endmacro"
SCRIPT_START    "script"|"iscript"
SCRIPT_END      "endscript"|"endiscript"
LINK_START      "link"
LINK_END        "endlink"
RETURN          "return"
STOP            "stop"|"s"

/* キー */
TAG_KEY_OK_TOP      {UTF8}|{ALPHABET}|{UNDERSCORE}
TAG_KEY_MIX         {TAG_KEY_OK_TOP}|{DIGIT}|{DOT}
TAG_KEY             {TAG_KEY_OK_TOP}{TAG_KEY_MIX}+|{TAG_KEY_OK_TOP}

LABEL_KEY           {TAG_KEY}

/* 文字列 */
TAG_STRING_CHAR     {UTF8}|{ALPHABET}|{ESC_CHAR}|{DIGIT}|{SPACE_STRING}|{SYMBOL_STRING}
TAG_STRING          {TAG_STRING_CHAR}+



/*
 * 排他的スタート状態の場合: %x
 * 包含的スタート状態の場合: %s
 */
%x STATE_COMMENT
%x STATE_INDENT
%x STATE_LABEL
%x STATE_AT_TAG
%x STATE_AT_TAG_STRING
%x STATE_TAG
%x STATE_TAG_STRING

/* 字句解析のルール */
%%
{COMMENT}                               {puts("> コメント");BEGIN(STATE_COMMENT);}
{HAT_COMMENT}                           {puts("> コメント");BEGIN(STATE_COMMENT);}
{LABEL}                                 {BEGIN(STATE_LABEL);}
{INDENT}                                {BEGIN(STATE_INDENT);}
{MESSAGE}                               {yylval.string_value = strdup(yytext);return MESSAGE;}

{AT_TOL}                                {/* ^@ */BEGIN(STATE_AT_TAG);return AT_TOL;}
{SQUARE_L}                              {/* [ */BEGIN(STATE_TAG);return SQUARE_L;}
<STATE_TAG>{SQUARE_L}                   {/* [ */return SQUARE_L;}
<STATE_TAG>{SQUARE_R}                   {/* ] */BEGIN(INITIAL);return SQUARE_R;}

<STATE_LABEL>{LABEL_KEY}                {yylval.string_value = strdup(yytext);return LABEL_KEY;}

<STATE_AT_TAG_STRING>{TAG_STRING}       {yylval.string_value = strdup(yytext);return TAG_STRING;}
<STATE_AT_TAG>{TAG_KEY}                 {yylval.string_value = strdup(yytext);return TAG_KEY;}
<STATE_TAG_STRING>{TAG_STRING}          {yylval.string_value = strdup(yytext);return TAG_STRING;}
<STATE_AT_TAG>{NUMBER}                  {yylval.string_value = strdup(yytext);return NUMBER;}
<STATE_TAG>{NUMBER}                     {yylval.string_value = strdup(yytext);return NUMBER;}
<STATE_TAG>{TAG_KEY}                    {yylval.string_value = strdup(yytext);return TAG_KEY;}

<STATE_TAG>{ESC_LF}                     {/* \n */return ESC_LF;}
<STATE_TAG>{ESC_CR}                     {/* \r */return ESC_CR;}
<STATE_TAG>{ESC_TAB}                    {/* \t */return ESC_TAB;}
<STATE_TAG>{ESC_QUOTE_SINGLE}           {/* \' */return ESC_QUOTE_SINGLE;}
<STATE_TAG>{ESC_QUOTE_DOUBLE}           {/* \" */return ESC_QUOTE_DOUBLE;}
<STATE_TAG>{ESC_BACK_SLASH}             {/* \\ */return ESC_BACK_SLASH;}

<STATE_TAG>{MUL_MUL}                    {/* ** */  return MUL_MUL;}
<STATE_TAG>{INCREMENT}                  {/* ++ */  return INCREMENT;}
<STATE_TAG>{DECREMENT}                  {/* -- */  return DECREMENT;}
<STATE_TAG>{ANGLE_L_EQUAL}              {/* <= */  return ANGLE_L_EQUAL;}
<STATE_TAG>{ANGLE_R_EQUAL}              {/* >= */  return ANGLE_R_EQUAL;}
<STATE_TAG>{EQUAL_EQUAL}                {/* == */  return EQUAL_EQUAL;}
<STATE_TAG>{NOT_EQUAL}                  {/* != */  return NOT_EQUAL;}
<STATE_TAG>{AND_AND}                    {/* && */  return AND_AND;}
<STATE_TAG>{OR_OR}                      {/* || */  return OR_OR;}
<STATE_TAG>{PLUS_EQUAL}                 {/* += */  return PLUS_EQUAL;}
<STATE_TAG>{MINUS_EQUAL}                {/* -= */  return MINUS_EQUAL;}
<STATE_TAG>{MUL_MUL_EQUAL}              {/* **= */ return MUL_MUL_EQUAL;}
<STATE_TAG>{MUL_EQUAL}                  {/* *= */  return MUL_EQUAL;}
<STATE_TAG>{SLASH_EQUAL}                {/* /= */  return SLASH_EQUAL;}
<STATE_TAG>{PERCENT_EQUAL}              {/* %= */  return PERCENT_EQUAL;}
<STATE_TAG>{AND_EQUAL}                  {/* &= */  return AND_EQUAL;}
<STATE_TAG>{HAT_EQUAL}                  {/* ^= */  return HAT_EQUAL;}
<STATE_TAG>{OR_EQUAL}                   {/* |= */  return OR_EQUAL;}
<STATE_TAG>{AND_AND_EQUAL}              {/* &&= */ return AND_AND_EQUAL;}
<STATE_TAG>{OR_OR_EQUAL}                {/* ||= */ return OR_OR_EQUAL;}
<STATE_TAG>{Q_Q_EQUAL}                  {/* ??= */ return Q_Q_EQUAL;}
<STATE_TAG>{ARROW}                      {/* => */  return ARROW;}
<STATE_TAG>{ARROW_SINGLE}               {/* -> */  return ARROW_SINGLE;}
<STATE_TAG>{SPREAD}                     {/* ... */ return SPREAD;}

<STATE_TAG>{SPACE_UTF8_2BYTE}           {return SPACE_UTF8_2BYTE;}
<STATE_TAG>{SPACE_UTF8_3BYTE}           {return SPACE_UTF8_3BYTE;}
<STATE_TAG>{UTF8}                       {return UTF8;}

<STATE_TAG>{HEX_COLOR}                  {/* 0x[0-9a-fA-F]{6} */return HEX_COLOR;}
<STATE_TAG>{NUMERAL_HEX}                {/* 0x[0-9a-fA-F]+ */return NUMERAL_HEX;}
<STATE_TAG>{FLOAT}                      {/* [0-9]+.[0-9]+ */return FLOAT;}
<STATE_TAG>{INTEGER}                    {/* [0-9][0-9]+ */yylval.string_value = strdup(yytext); return INTEGER;}
<STATE_TAG>{DIGIT_NON_ZERO}             {/* 1-9 */yylval.string_value = strdup(yytext); return DIGIT_NON_ZERO;}
<STATE_TAG>{ZERO}                       {/* 0 */yylval.string_value = strdup(yytext); return ZERO;}

<STATE_TAG>{ALPHABET}                   {/* a-zA-A */yylval.string_value = strdup(yytext); return ALPHABET; }

<STATE_TAG>{QUOTE_DOUBLE}               {/* " */BEGIN(STATE_TAG_STRING);return QUOTE_DOUBLE;}
<STATE_TAG_STRING>{QUOTE_DOUBLE}        {/* " */BEGIN(STATE_TAG);return QUOTE_DOUBLE;}
<STATE_AT_TAG>{QUOTE_DOUBLE}            {/* " */BEGIN(STATE_AT_TAG_STRING);return QUOTE_DOUBLE;}
<STATE_AT_TAG_STRING>{QUOTE_DOUBLE}     {/* " */BEGIN(STATE_AT_TAG);return QUOTE_DOUBLE;}
<STATE_TAG>{DOT}                        {/* . */return DOT;}
<STATE_TAG>{COMMA}                      {/* , */return COMMA;}
<STATE_AT_TAG>{EQUAL}                   {/* = */return EQUAL;}
<STATE_TAG>{EQUAL}                      {/* = */return EQUAL;}
<STATE_TAG>{CURLY_L}                    {/* { */return CURLY_L;}
<STATE_TAG>{CURLY_R}                    {/* } */return CURLY_R;}
<STATE_TAG>{ANGLE_L}                    {/* < */return ANGLE_L;}
<STATE_TAG>{ANGLE_R}                    {/* > */return ANGLE_R;}
<STATE_TAG>{ROUND_L}                    {/* ( */return ROUND_L;}
<STATE_TAG>{ROUND_R}                    {/* ( */return ROUND_R;}
<STATE_TAG>{PLUS}                       {/* + */return PLUS;}
<STATE_TAG>{MINUS}                      {/* - */return MINUS;}
<STATE_TAG>{MUL}                        {/* * */return MUL;}
<STATE_TAG>{SLASH}                      {/* / */return SLASH;}
<STATE_TAG>{BACK_SLASH}                 {/* \ */return BACK_SLASH;}
<STATE_TAG>{SEMICOLON}                  {/* ; */return SEMICOLON;}
<STATE_TAG>{COLON}                      {/* : */return COLON;}
<STATE_TAG>{DOLLAR}                     {/* $ */return DOLLAR;}
<STATE_TAG>{PERCENT}                    {/* % */return PERCENT;}
<STATE_TAG>{SHARP}                      {/* # */return SHARP;}
<STATE_TAG>{QUOTE_SINGLE}               {/* ' */return QUOTE_SINGLE;}
<STATE_TAG>{QUOTE_BACK}                 {/* ` */return QUOTE_BACK;}
<STATE_TAG>{UNDERSCORE}                 {/* _ */return UNDERSCORE;}
<STATE_TAG>{QUESTION}                   {/* ? */return QUESTION;}
<STATE_TAG>{NOT}                        {/* ! */return NOT;}
<STATE_TAG>{AND}                        {/* & */return AND;}
<STATE_TAG>{AT}                         {/* @ */return AT;}
<STATE_TAG>{HAT}                        {/* ^ */return HAT;}
<STATE_TAG>{TILDE}                      {/* ~ */return TILDE;}
<STATE_LABEL>{OR}                       {/* | */return OR;}
<STATE_TAG>{OR}                         {/* | */return OR;}

<STATE_COMMENT>{EOL}                    {BEGIN(INITIAL);return EOL;}
<STATE_INDENT>{EOL}                     {BEGIN(INITIAL);return EOL;}
<STATE_LABEL>{EOL}                      {BEGIN(INITIAL);return EOL;}
<STATE_AT_TAG>{EOL}                     {BEGIN(INITIAL);return EOL;}
<STATE_TAG>{EOL}                        {return EOL;}
{EOL}                                   {return EOL;}
<STATE_INDENT>{SPACE_ASCII}             {}
<STATE_LABEL>{SPACE_ASCII}              {}
<STATE_AT_TAG>{SPACE_ASCII}             {}
<STATE_TAG>{SPACE_ASCII}                {}

<STATE_COMMENT>.                        {}
.                                       {}
%%

/*
<STATE_TAG>{SQUARE_L}                   {return SQUARE_L;}
<STATE_TAG>{SQUARE_R}                   {return SQUARE_R;}
*/

/*{OPERATOR}          { printf("<OPERATOR>"); return(yytext[0]); }*/

void set_input_string(const char* in) {
  yy_scan_string(in);
}

void end_lexical_scan(void) {
  yy_delete_buffer(YY_CURRENT_BUFFER);
}

/* int main(void) {
    yylex();
    return 0;
} */

int yywrap() {
    return 1;
}

/* {NUMBER}          { printf("<NUMBER>");
                    yylval = atof(yytext);
                    return NUMBER; } */

/*

*/