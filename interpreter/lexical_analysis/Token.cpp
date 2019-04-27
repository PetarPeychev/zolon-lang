#include "Token.hpp"

// constructor for tokens without a literal value
lexical_analysis::Token::Token(TokenType type, int line)
{
    this->type = type;
    this->line = line;
}

// constructor for tokens with a string literal value
lexical_analysis::Token::Token(TokenType type, int line, std::string sval)
{
    this->type = type;
    this->line = line;
    this->sval = sval;
}

// constructor for tokens with a number literal value
lexical_analysis::Token::Token(TokenType type, int line, double nval)
{
    this->type = type;
    this->line = line;
    this->nval = nval;
}

int lexical_analysis::Token::tokenLine()
{
    return this->line;
}

lexical_analysis::TokenType lexical_analysis::Token::tokenType()
{
    return this->type;
}

double lexical_analysis::Token::tokenNval()
{
    if(this->type == NUMBER)
    {
        return this->nval;
    }
    else
    {
        throw "Token type does not contain a number value!";
    }
}

std::string lexical_analysis::Token::tokenSval()
{
    if(this->type == PATH || this->type == IDENTIFIER)
    {
        return this->sval;
    }
    else
    {
        throw "Token type does not contain a string value!";
    }
}

// turn a token into a string in the format: <Type:NUMBER, Nval:5.000000, Line:1>
std::string lexical_analysis::Token::toString()
{
    std::string str = "<Type:";

    // add the appropriate token type
    switch(this->type)
    {
        case PLUS: str += "PLUS, "; break;
        case ASTERISK: str += "ASTERISK, "; break;
        case FSLASH: str += "FSLASH, "; break;
        case BSLASH: str += "BSLASH, "; break;
        case LPAREN: str += "LPAREN, "; break;
        case RPAREN: str += "RPAREN, "; break;
        case COMMA: str += "COMMA, "; break;
        case CARET: str += "CARET, "; break;
        case COLON: str += "COLON, "; break;
        case BAR: str += "BAR, "; break;
        case LBRACKET: str += "LBRACKET, "; break;
        case RBRACKET: str += "RBRACKET, "; break;
        case MINUS: str += "MINUS, "; break;
        case MAP: str += "MAP, "; break;
        case BIND: str += "BIND, "; break;
        case EQUALS: str += "EQUALS, "; break;
        case LESS: str += "LESS, "; break;
        case GREATER: str += "GREATER, "; break;
        case LEQUALS: str += "LEQUALS, "; break;
        case GEQUALS: str += "GEQUALS, "; break;
        case NEQUALS: str += "NEQUALS, "; break;

        // some tokens need a literal value as well
        case IDENTIFIER: str += "IDENTIFIER, Sval:" + this->sval + ", "; break;
        case NUMBER: str += "NUMBER, Nval:" + std::to_string(this->nval) + ", "; break;

        case PATH: str += "PATH, "; break;
        case BTRUE: str += "BTRUE, "; break;
        case BFALSE: str += "BFALSE, "; break;
        case IMPORT: str += "IMPORT, "; break;
        case NOT: str += "NOT, "; break;
        case AND: str += "AND, "; break;
        case OR: str += "OR, "; break;
        case SEMICOLON: str += "SEMICOLON, "; break;
    }

    // add the line number and return
    str += "Line:" + std::to_string(this->line) + ">";
    return str;
}
