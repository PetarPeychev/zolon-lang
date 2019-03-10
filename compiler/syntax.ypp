%{
  #include <cstdio>
  #include <iostream>
  using namespace std;

  extern int yylex();
  extern int yyparse();
  extern FILE *yyin;
  extern int linenum;

  void yyerror(const char *s);
%}

%union {
  float fval;
  char *sval;
}

%token <fval> NUMBER
%token <sval> IDENTIFIER
%token MAP "->"
%token MAIN "main"
%left '+' '-'
%left '*' '/'
%precedence NEG
%right '^'

%%

script:
  main-binding
  | binding-list main-binding
  ;

binding-list:
  binding
  | binding-list binding
  ;

binding:
  IDENTIFIER '=' function
  | IDENTIFIER '=' expression
  ;

main-binding:
  "main" '=' function
  | "main" '=' expression
  ;

function:
  parameter-list "->" expression
  ;

parameter-list:
  parameter
  | parameter-list parameter
  ;

parameter:
  '$' IDENTIFIER
  ;

expression:
  NUMBER
  | IDENTIFIER
  | function-application
  | expression '+' expression
  | expression '-' expression
  | expression '*' expression
  | expression '/' expression
  | '-' expression  %prec NEG
  | expression '^' expression
  | '(' expression ')'
  ;

function-application:
  function '(' expression-list ')'
  ;

expression-list:
  %empty
  | expression
  | expression-list ',' expression
  ;

%%

int main(int argc, char** argv) {
  if (argc != 2) {
    cout << "Incorrect number of arguments!" << endl;
    return -1;
  }

  FILE *myfile = fopen(argv[1], "r");

  if (!myfile) {
    cout << "Failed to open a .zl file!" << endl;
    return -1;
  }

  yyin = myfile;

  yyparse();
}

void yyerror(const char *s) {
  cout << "Parse Error: " << s << " on line " << linenum << endl;
  exit(-1);
}
