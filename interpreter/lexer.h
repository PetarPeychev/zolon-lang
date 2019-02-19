#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>

// Emum representing every lexeme type
enum LexemeType {
    L_PARENTHESIS,
    R_PARENTHESIS,
    L_BRACKET,
    R_BRACKET,
    ASSIGNMENT_OPERATOR,
    PIPE_OPERATOR,
    ARITHMETIC_OPERATOR,
    COMPARISON_OPERATOR,
    BOOLEAN_OPERATOR,
    PREFIX_OPERATOR,
    COLON,
    BAR,
    MAPPING_OPERATOR,
    NUMBER_LITERAL,
    BOOLEAN_LITERAL,
    IDENTIFIER
};

// Struct defining a single lexeme
typedef struct Lexeme {
    LexemeType type;
    std::string value;
} Lexeme;

std::vector<Lexeme> tokenize(std::string source);

#endif
