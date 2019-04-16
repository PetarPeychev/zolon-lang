#include "Scanner.hpp"
#include "../exceptions/NotImplementedException.hpp"
#include "../Interpreter.hpp"
#include <cctype>

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

bool Scanner::match(char expected)
{
    if(this->atEnd())
    {
        return false;
    }
    if(this->statement[this->current] != expected)
    {
        return false;
    }
    this->current++;
    return true;
}

char Scanner::peek(int lookahead)
{
    lookahead--;
    if(this->current + lookahead >= (int)this->statement.length())
    {
        return '\0';
    }
    else
    {
        return this->statement[this->current + lookahead];
    }
}

void Scanner::scanToken()
{
    char ch = this->advance();
    switch (ch)
    {
        // Whitespace
        case '\n': this->line++; break;
        case ' ':
        case '\t':
        case '\r': break;

        // Single char tokens
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

        // One or two char tokens
        case '-': this->tokens.push_back(new Token(match('>') ? MAP : MINUS, this->line)); break;
        case '=': this->tokens.push_back(new Token(match('=') ? EQUALS : BIND, this->line)); break;
        case '<': this->tokens.push_back(new Token(match('=') ? LEQUALS : LESS, this->line)); break;
        case '>': this->tokens.push_back(new Token(match('=') ? GEQUALS : GREATER, this->line)); break;
        case '!': if(match('='))
        {
            this->tokens.push_back(new Token(NEQUALS, this->line));
            break;
        }

        // Longer tokens
        default:
        if(std::isalpha(ch) || ch == '_')
        {
            this->scanIdentifier();
        }
        else if(std::isdigit(ch))
        {
            this->scanNumber();
        }
        else
        {
            Interpreter::error(this->line, "Scanner encountered an unexpected character."); break;
        }
    }
}

void Scanner::scanIdentifier()
{
    while(std::isalpha(this->peek(1))
    || this->peek(1) == '_'
    || std::isdigit(this->peek(1)))
    {
        this->advance();
    }
    std::string identifier = this->statement.substr(
        this->start, this->current - this->start);
    if(identifier == "true") this->tokens.push_back(new Token(BTRUE, this->line));
    else if(identifier == "false") this->tokens.push_back(new Token(BFALSE, this->line));
    else if(identifier == "not") this->tokens.push_back(new Token(NOT, this->line));
    else if(identifier == "and") this->tokens.push_back(new Token(AND, this->line));
    else if(identifier == "or") this->tokens.push_back(new Token(OR, this->line));
    else this->tokens.push_back(new Token(IDENTIFIER, this->line, identifier));
}

void Scanner::scanNumber()
{
    while(std::isdigit(this->peek(1)))
    {
        this->advance();
    }
    if(this->peek(1) == '.' && std::isdigit(peek(2)))
    {
        this->advance();
        while(std::isdigit(this->peek(1)))
        {
            this->advance();
        }
    }
    double number = std::stod(this->statement.substr(this->start, this->current - this->start));
    this->tokens.push_back(new Token(NUMBER, this->line, number));
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
