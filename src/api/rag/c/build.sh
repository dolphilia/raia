bison -d parser.y
flex lexer.l
#gcc lex.yy.c -ll -o lexer
#./lexer
bison parser.y
gcc parser.tab.c yyjson.c -ll -o parser
