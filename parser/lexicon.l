%{
  #include <iostream>
  using namespace std;
  extern int yylex();
  int linenum = 0;
%}

%option noyywrap

%%

[ \t]                      ;
\n                         { ++linenum; }
\(                         { cout << "Left Parenthesis: " << yytext << endl; }
\)                         { cout << "Right Parenthesis: " << yytext << endl; }
\[                         { cout << "Left Bracket: " << yytext << endl; }
\]                         { cout << "Right Bracket: " << yytext << endl; }
=                          { cout << "Equal Sign: " << yytext << endl; }
\|>                        { cout << "Pipe: " << yytext << endl; }
\+                         { cout << "Plus Sign: " << yytext << endl; }
-                          { cout << "Minus Sign: " << yytext << endl; }
\*                         { cout << "Asterisk: " << yytext << endl; }
\/                         { cout << "Slash: " << yytext << endl; }
\<                         { cout << "Less: " << yytext << endl; }
>                          { cout << "More: " << yytext << endl; }
\<=                        { cout << "Less or Equal: " << yytext << endl; }
>=                         { cout << "More or Equal: " << yytext << endl; }
!=                         { cout << "Not Equal: " << yytext << endl; }
==                         { cout << "Equal: " << yytext << endl; }
and                        { cout << "Logical And: " << yytext << endl; }
or                         { cout << "Logical Or: " << yytext << endl; }
not                        { cout << "Logical Not: " << yytext << endl; }
:                          { cout << "Colon: " << yytext << endl; }
\|                         { cout << "Bar: " << yytext << endl; }
->                         { cout << "Map: " << yytext << endl; }
[0-9]+(\.[0-9]+)?          { cout << "Number Literal: " << yytext << endl; }
true                       { cout << "Boolean True: " << yytext << endl; }
false                      { cout << "Boolean False: " << yytext << endl; }
[_a-zA-Z][_0-9a-zA-Z]*     { cout << "Identifier: " << yytext << endl; }

%%

int main(int, char**) {
  // lex through the input:
  while (yylex());
}
