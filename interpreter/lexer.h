#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>

// Emum representing every lexeme type
enum LexemeType {
    PARENTHESIS, OPERATOR, SYMBOL, NUMBER, STRING, KEYWORD, NAME
};

// Struct defining a single lexeme
typedef struct Lexeme {
    LexemeType type;
    std::string value;
} Lexeme;

std::vector<Lexeme> tokenize(std::string source);

#endif
