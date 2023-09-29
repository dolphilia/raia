%{
#include <stdio.h>
#include <math.h>
#include "yyjson.h"
#include "utstring.h"

// #define YYSTYPE double

extern int yylex (void);
extern int yyparse();
extern int yyerror (const char* str);

//#define YY_DECL int yylex(void)
//extern int yylex(void);
//extern void yyerror(const char *s);
//extern FILE *yyin;

// typedef struct rag_hash_t {
//     char name[50];
//     char *str;
//     UT_hash_handle hh;
// } rag_hash_t;
// static rag_hash_t *rag_hash;

// typedef struct json_t {
//     yyjson_mut_doc *doc;
//     yyjson_mut_val *root;
// } json_t;

// static json_t *json;
//static char *joint;

static UT_string *utstring;

%}

//%skeleton "./bison.m4"

%union {
    int int_value;
    double double_value;
    char *string_value;
}

// コメント
%token COMMENT

// 空白
%token LF 
%token CR
%token EOL
%token TAB_H
%token TAB_V
%token TAB
%token FF
%token SPACE_ASCII
%token SPACE_UTF8_2BYTE
%token SPACE_UTF8_3BYTE
%token BLANK
%token BLANK_LINE

// 位置
%token INDENT

// 記号
%token DOT              // .
%token COMMA            // ,
%token EQUAL            // =
%token SQUARE_L         // [
%token SQUARE_R         // ]
%token CURLY_L          // {
%token CURLY_R          // }
%token ANGLE_L          // <
%token ANGLE_R          // >
%token ROUND_L          // (
%token ROUND_R          // (
%token PLUS             // +
%token MINUS            // -
%token MUL              // *
%token SLASH            // /
%token BACK_SLASH       // \
%token SEMICOLON        // ;
%token COLON            // :
%token DOLLAR           // $
%token PERCENT          // %
%token SHARP            // #
%token QUOTE_SINGLE     // '
%token QUOTE_DOUBLE     // "
%token QUOTE_BACK       // `
%token UNDERSCORE       // _
%token QUESTION         // ?
%token NOT              // !
%token AND              // &
%token AT               // @
%token HAT              // ^
%token TILDE            // ~
%token OR               // |

%token AT_TOL

// 2文字以上の記号
%token MUL_MUL          // **
%token INCREMENT        // ++
%token DECREMENT        // --
%token ANGLE_L_EQUAL    // <=
%token ANGLE_R_EQUAL    // >=
%token EQUAL_EQUAL      // ==
%token NOT_EQUAL        // !=
%token AND_AND          // &&
%token OR_OR            // ||
%token PLUS_EQUAL       // +=
%token MINUS_EQUAL      // -=
%token MUL_MUL_EQUAL    // **=
%token MUL_EQUAL        // *=
%token SLASH_EQUAL      // /=
%token PERCENT_EQUAL    // %=
%token AND_EQUAL        // &=
%token HAT_EQUAL        // ^=
%token OR_EQUAL         // |=
%token AND_AND_EQUAL    // &&=
%token OR_OR_EQUAL      // ||=
%token Q_Q_EQUAL        // ??=
%token ARROW            // =>
%token ARROW_SINGLE     // ->
%token SPREAD           // ...

// エスケープ文字
%token ESC_LF           // \n
%token ESC_CR           // \r
%token ESC_TAB          // \t
%token ESC_QUOTE_SINGLE // \'
%token ESC_QUOTE_DOUBLE // \"
%token ESC_BACK_SLASH   // \\

// メッセージ
%token MESSAGE

// ラベル
%token <string_value> LABEL_KEY

// タグ
%token <string_value> TAG_KEY

// 文字列
%token <string_value> TAG_STRING

// 数値
%token HEX_COLOR
%token NUMERAL_HEX
%token FLOAT
%token INTEGER
%token ZERO
%token DIGIT_NON_ZERO
%token <string_value> NUMBER

%token NOVEL_KEYS
%token <string_value> ALPHABET
%token UTF8


/* タイプ */
%type <string_value> MESSAGE
%type <string_value> MESSAGES_TAGS
%type <string_value> MESSAGES_SET
%type <string_value> MESSAGES_SETS
%type <string_value> TAGS_SET
%type <string_value> TAGS_SETS
%type <string_value> LABEL_NAME
%type <string_value> TAG_NAME
%type <string_value> TAG_ATTR
%type <string_value> TAG_ATTRS
%type <string_value> ZERO
%type <string_value> DIGIT_NON_ZERO
%type <string_value> INTEGER

/* 優先順位 */
%left '+' '-'
%left '*' '/' '%'
%right MUL_MUL

%start BLOCK

%%

BLOCK
    : BLOCK LINE {} 
    | LINE {}
    ;

LINE
    : MESSAGES_LINE {}
    | INDENT_LINE {}
    | EOL_LINE {}
    | LABEL_LINE {}
    ;

EOL_LINE
    : EOL {}
    | SQUARE_R EOL {}
    ;

MESSAGES_LINE
    : MESSAGES_TAGS EOL {}
    | TAGS EOL {}
    | MESSAGES EOL {}
    ;

MESSAGES_TAGS
    : MESSAGES_SETS MESSAGES {}
    | MESSAGES_SETS {}
    | TAGS_SETS TAGS {}
    | TAGS_SETS {}
    ;

TAGS_SETS
    : TAGS_SETS TAGS_SET {}
    | TAGS_SET {}
    ;

TAGS_SET
    : TAGS MESSAGES {}
    ;

MESSAGES_SETS
    : MESSAGES_SETS MESSAGES_SET {}
    | MESSAGES_SET {}
    ;

MESSAGES_SET
    : MESSAGES TAGS {}
    ;

MESSAGES
    : MESSAGES MESSAGE {printf("> メッセージ: %s\n",$2);}
    | MESSAGE {printf("> メッセージ: %s\n",$1);}
    ;

INDENT_LINE
    : INDENT {}
    ;

TAGS
    : TAGS TAG {}
    | TAG {}
    ;

TAG
    : TAG_COMPONENT {}
    ;

TAG_COMPONENT
    : SQUARE_L TAG_NAME TAG_ATTRS SQUARE_R {}
    | SQUARE_L TAG_NAME SQUARE_R {}
    | AT_TOL TAG_NAME TAG_ATTRS EOL {}
    | AT_TOL TAG_NAME EOL {}
    ;


TAG_ATTRS
    : TAG_ATTRS TAG_ATTR {}
    | TAG_ATTR {}
    ;

TAG_ATTR
    : TAG_KEY EQUAL TAG_KEY {
        printf("> 属性名: %s\n", $1);
        printf("> 属性値: %s\n", $3);
    }
    | TAG_KEY EQUAL QUOTE_DOUBLE TAG_STRING QUOTE_DOUBLE {
        printf("> 属性名: %s\n", $1);
        printf("> 文字列: \"%s\"\n", $4);
    }
    | TAG_KEY EQUAL NUMBER {
        printf("> 属性名: %s\n", $1);
        printf("> 数値: %s\n", $3);
    }
    ;

TAG_NAME
    : TAG_KEY {
        printf("> タグ名: %s\n", $1);
    }
    ;

LABEL_LINE
    : LABEL EOL {}
    ;

LABEL
    : LABEL_NAME {}
    | LABEL_NAME OR LABEL_SAVE {}
    ;

LABEL_SAVE
    : LABEL_KEY {
        printf("> セーブ名: %s\n", $1);
    }
    ;

LABEL_NAME
    : LABEL_KEY {
        printf("> ラベル名: %s\n", $1);
    }
    ;

%%

#include "lex.yy.c"

/* void add_joint(const char *str) {
    if(joint) {
        free((void *)joint);
    }
    int len = (int)strlen(str);
    joint = (char *)malloc(sizeof(char) * len + 1);
    strcpy(joint, str);
    joint[len] = '\0';
}     */

int yyerror (const char* str){
    fprintf(stderr, "parse error near %s\n", yytext);
    return 0;
}

/* Declarations */
void set_input_string(const char* in);
void end_lexical_scan(void);

/* This function parses a string */
int parse_string(const char* in) {
  set_input_string(in);
  int rv = yyparse();
  end_lexical_scan();
  return rv;
}

int main() {
    utstring_new(utstring);
    yyparse(); //parse_string("[name attr="string"]\n");
    printf("%s\n", utstring_body(utstring));
    utstring_free(utstring);
    return 0;
}