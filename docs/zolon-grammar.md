# Zolon Grammar Specification

### Non-Terminal Production Rules
````
program = binding* main-binding .

binding = IDENTIFIER BIND expression .

main-binding = MAIN BIND expression .

expression = LPAREN expression RPAREN
           | function
           | infix-operation
           | prefix-operation
           | literal
           | IDENTIFIER
           | list

function = IDENTIFIER MAP (expression COLON expression PIPE)* expression .

infix-operation = expression infix-operator expression .

infix-operator = PIPE
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
               | OR .

prefix-operation = prefix-operator expression .

prefix-operator = NOT .

literal = NUMBER | boolean .

boolean = TRUE | FALSE .

list = LBRACKET (expression COMMA)* expression RBRACKET .
````
### Terminal Symbols
````
IDENTIFIER =      [_a-zA-Z][_0-9a-zA-Z]*
MAIN =            main
BIND =            =
LPAREN =          \(
RPAREN =          \)
MAP =             ->
COLON =           :
PIPE =            \|>
PLUS =            \+
MINUS =           -
MULTIPLY =        \*
DIVIDE =          \/
LESS =            <
GREATER =         >
EQUAL =           =
LESS_EQUAL =      <=
GREATER_EQUAL =   >=
NOT_EQUAL =       !=
AND =             and
OR =              or
NOT =             not
NUMBER =          [0-9]+(\.[0-9]+)?
TRUE =            true
FALSE =           false
COMMA =           ,
LBRACKET =        \[
RBRACKET =        ]
````
