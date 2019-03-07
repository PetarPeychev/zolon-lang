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
%token MAIN LPAREN RPAREN TRUE FALSE LBRACKET RBRACKET IF

%left COMMA
%left BIND
%left COLON MAP
%left BAR
%left PIPE
%left AND OR
%left EQUAL NOT_EQUAL LESS GREATER LESS_EQUAL GREATER_EQUAL
%left PLUS MINUS
%left MULTIPLY DIVIDE

%right NOT

%%

program:
  bindings main-binding { cout << "Detected a Zolon program" << endl; }
  ;

bindings:
  bindings binding
  | binding
  ;

binding:
  IDENTIFIER BIND expression
  ;

main-binding:
  MAIN BIND expression
  ;

expression:
  LPAREN expression RPAREN
  | function
  | infix-operation
  | prefix-operation
  | literal
  | function-call
  | list
  ;

function:
  IDENTIFIER MAP expression
  ;

infix-operation:
  expression infix-operator expression
  ;

infix-operator:
  PIPE
  | PLUS
  | MINUS
  | MULTIPLY
  | DIVIDE
  | LESS
  | GREATER
  | EQUAL
  | LESS_EQUAL
  | GREATER_EQUAL
  | NOT_EQUAL
  | AND
  | OR
  ;

prefix-operation:
  prefix-operator expression
  ;

prefix-operator:
  NOT
  ;

literal:
  NUMBER
  | boolean
  ;

boolean:
  TRUE
  | FALSE
  ;

function-call:
  IDENTIFIER IDENTIFIER
  ;

list:
  LBRACKET list-items RBRACKET
  ;

list-items:
  %empty
  | non-empty-list-items
  ;

non-empty-list-items:
  list-items COMMA expression
  | expression
  ;

%%

int main(int, char**) {
  FILE *myfile = fopen("test.zl", "r");

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
