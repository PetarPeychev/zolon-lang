#include "Token.hpp"

lexical_analysis::Token::Token(TokenType type, int line)
{
    this->type = type;
    this->line = line;
}

lexical_analysis::Token::Token(TokenType type, int line, std::string sval)
{
    this->type = type;
    this->line = line;
    this->sval = sval;
}

lexical_analysis::Token::Token(TokenType type, int line, double nval)
{
    this->type = type;
    this->line = line;
    this->nval = nval;
}

std::string lexical_analysis::Token::toString()
{
    std::string str = "<Type:";
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
        case LEQUALS: str += "LEQUALS, "; break;
        case GEQUALS: str += "GEQUALS, "; break;
        case NEQUALS: str += "NEQUALS, "; break;
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
    str += "Line:" + std::to_string(this->line) + ">";
    return str;
}
