%{
  #include <iostream>
  #include "syntactical-analyser.hpp"
  using namespace std;
  extern int yylex();
  int linenum = 1;
%}

%option noyywrap

%%

[ \t\f\r\v]                    ;
\n                             { ++linenum; }
->                             { cout << yytext << endl; return MAP; }
[+\-*\/\\\=\(\),^$\<\>:\|{}]   { cout << yytext[0] << endl; return yytext[0]; }
[0-9]+(\.[0-9]+)?              { cout << yytext << endl; yylval.fval = atof(yytext); return NUMBER; }
True                           { cout << "True" << endl; return BTRUE; }
False                          { cout << "False" << endl; return BFALSE; }
import                         { cout << "import" << endl; return IMPORT; }
not                            { cout << "not" << endl; return NOT; }
and                            { cout << "and" << endl; return AND; }
or                             { cout << "or" << endl; return OR; }
\=\=                           { cout << "==" << endl; return EQUALS; }
\<\=                           { cout << "<=" << endl; return LEQUALS; }
\>\=                           { cout << ">=" << endl; return GEQUALS; }
!\=                            { cout << "!=" << endl; return NEQUALS; }
\'.+\'                         { yylval = new AST::Path(yytext); }
[_a-zA-Z][_0-9a-zA-Z]*         { cout << yytext << endl; yylval.sval = strdup(yytext); return IDENTIFIER; }

%%
