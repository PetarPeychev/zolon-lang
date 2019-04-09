#include "Scanner.hpp"
#include "../exceptions/NotImplementedException.hpp"
#include "../Interpreter.hpp"

using namespace lexical_analysis;

Scanner::Scanner(std::string statement)
{
    this->statement = statement;
    this->start = 0;
    this->current = 0;
    this->line = 1;
}

char Scanner::advance()
{
    this->current++;
    return this->statement[current - 1];
}

void Scanner::scanToken()
{
    char ch = this->advance();
    switch (ch)
    {
        case '+': this->tokens.push_back(new Token(PLUS, this->line)); break;
        case '*': this->tokens.push_back(new Token(ASTERISK, this->line)); break;
        case '/': this->tokens.push_back(new Token(FSLASH, this->line)); break;
        case '\\': this->tokens.push_back(new Token(BSLASH, this->line)); break;
        case '(': this->tokens.push_back(new Token(LPAREN, this->line)); break;
        case ')': this->tokens.push_back(new Token(RPAREN, this->line)); break;
        case ',': this->tokens.push_back(new Token(COMMA, this->line)); break;
        case '^': this->tokens.push_back(new Token(CARET, this->line)); break;
        case ':': this->tokens.push_back(new Token(COLON, this->line)); break;
        case '|': this->tokens.push_back(new Token(BAR, this->line)); break;
        case '{': this->tokens.push_back(new Token(LBRACKET, this->line)); break;
        case '}': this->tokens.push_back(new Token(RBRACKET, this->line)); break;
        case ';': this->tokens.push_back(new Token(SEMICOLON, this->line)); break;
        default: Interpreter::error(line, "Scanner encountered an unexpected character."); break;
    }
}

bool Scanner::atEnd()
{
    return this->current >= static_cast<signed>(this->statement.length());
}

std::vector<Token*> Scanner::scanTokens()
{
    while(!this->atEnd())
    {
        this->start = this->current;
        this->scanToken();
    }
    return tokens;
}
