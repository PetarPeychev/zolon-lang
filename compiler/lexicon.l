%{
  #include <iostream>
  #include "syntactical-analyser.hpp"
  using namespace std;
  extern int yylex();
  int linenum = 1;
%}

%option noyywrap

%%

[ \t\f\r\v]                ;
\n                         { ++linenum; }
->                         { cout << yytext << endl; return MAP; }
[+\-*\/\=\(\),^$]           { cout << yytext[0] << endl; return yytext[0]; }
[0-9]+(\.[0-9]+)?          { cout << yytext << endl; yylval.fval = atof(yytext); return NUMBER; }
main                       { cout << "main" << endl; return MAIN; }
[_a-zA-Z][_0-9a-zA-Z]*     { cout << yytext << endl; yylval.sval = strdup(yytext); return IDENTIFIER; }

%%
