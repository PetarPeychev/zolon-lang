%{
  #include <iostream>
  #include "syntactical-analyser.h"
  using namespace std;
  extern int yylex();
  int linenum = 1;
%}

%option noyywrap

%%

[ \t\f\r\v]                ;
\n                         { ++linenum; }
\(                         { cout << "LPAREN: " << yytext << endl; return LPAREN; }
\)                         { cout << "RPAREN: " << yytext << endl; return RPAREN; }
\[                         { cout << "LBRACKET: " << yytext << endl; return LBRACKET; }
]                          { cout << "RBRACKET: " << yytext << endl; return RBRACKET; }
\=                         { cout << "BIND: " << yytext << endl; return BIND; }
\+                         { cout << "PLUS: " << yytext << endl; return PLUS; }
\-                         { cout << "MINUS: " << yytext << endl; return MINUS; }
\*                         { cout << "MULTIPLY: " << yytext << endl; return MULTIPLY; }
\/                         { cout << "DIVIDE: " << yytext << endl; return DIVIDE; }
\<                         { cout << "LESS: " << yytext << endl; return LESS; }
\>                         { cout << "GREATER: " << yytext << endl; return GREATER; }
:                          { cout << "COLON: " << yytext << endl; return COLON; }
,                          { cout << "COMMA: " << yytext << endl; return COMMA; }
\|                         { cout << "BAR: " << yytext << endl; return BAR; }
\|>                        { cout << "PIPE: " << yytext << endl; return PIPE; }
\<=                        { cout << "LESS_EQUAL: " << yytext << endl; return LESS_EQUAL; }
>=                         { cout << "GREATER_EQUAL: " << yytext << endl; return GREATER_EQUAL; }
!=                         { cout << "NOT_EQUAL: " << yytext << endl; return NOT_EQUAL; }
==                         { cout << "EQUAL: " << yytext << endl; return EQUAL; }
and                        { cout << "AND: " << yytext << endl; return AND; }
or                         { cout << "OR: " << yytext << endl; return OR; }
not                        { cout << "NOT: " << yytext << endl; return NOT; }
->                         { cout << "MAP: " << yytext << endl; return MAP; }
[0-9]+(\.[0-9]+)?          { cout << "NUMBER: " << yytext << endl; yylval.fval = atof(yytext); return NUMBER; }
true                       { cout << "TRUE: " << yytext << endl; return TRUE; }
false                      { cout << "FALSE: " << yytext << endl; return FALSE; }
main                       { cout << "MAIN: " << yytext << endl; return MAIN; }
if                         { cout << "IF: " << yytext << endl; return IF; }
[_a-zA-Z][_0-9a-zA-Z]*     { cout << "IDENTIFIER: " << yytext << endl; yylval.sval = strdup(yytext); return IDENTIFIER; }

%%
