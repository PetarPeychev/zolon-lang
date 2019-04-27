#include "Scanner.hpp"
#include "../exceptions/NotImplementedException.hpp"
#include "../Interpreter.hpp"
#include <cctype>

using namespace lexical_analysis;

Scanner::Scanner(std::string statement)
{
    this->statement = statement;
    // the start position of the current token being scanned
    this->start = 0;
    // the current character being considered for the token
    this->current = 0;
    // the line counter for the statement
    this->line = 1;
}

// move to the next character
char Scanner::advance()
{
    this->current++;
    return this->statement[current - 1];
}

// try to match a specific character and advance if it's matched
// is essentially a combination of peek(1) and advance
bool Scanner::match(char expected)
{
    if(this->atEnd())
    {
        return false;
    }
    else if(this->statement[this->current] != expected)
    {
        return false;
    }
    else
    {
        this->current++;
        return true;
    }
}

// peek at the character which is (lookahead - 1) indices after the current
// the specific grammar only needs a lookahead of 2, but the function allows for more
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

// the main scan logic function
void Scanner::scanToken()
{
    // consume the next character
    char ch = this->advance();

    // switch over it and test which type it belongs to
    switch (ch)
    {
        // Whitespace can be safely ignored, except for a new line, which
        // needs to increment the line counter
        case '\n': this->line++; break;
        case ' ':
        case '\t':
        case '\r': break;

        // Single char tokens can be immediately resolved into single-char tokens
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

        // Some tokens can either be single-character and resolved immediately or
        // alternatively be double-characters. To determine this, we need to peek at the
        // following token.
        case '-': this->tokens.push_back(new Token(match('>') ? MAP : MINUS, this->line)); break;
        case '=': this->tokens.push_back(new Token(match('=') ? EQUALS : BIND, this->line)); break;
        case '<': this->tokens.push_back(new Token(match('=') ? LEQUALS : LESS, this->line)); break;
        case '>': this->tokens.push_back(new Token(match('=') ? GEQUALS : GREATER, this->line)); break;
        case '!': if(match('='))
        {
            this->tokens.push_back(new Token(NEQUALS, this->line));
            break;
        }

        // Tokens of variable length require their own loops to be scanned.
        // The scanning logic for them is extracted to functions.
        default:
        // identifiers begin with a letter or underscore
        if(std::isalpha(ch) || ch == '_')
        {
            this->scanIdentifier();
        }
        // numbers begin with a digit
        else if(std::isdigit(ch))
        {
            this->scanNumber();
        }
        else // everything else is an invalid character
        {
            Interpreter::error(this->line, "Scanner encountered an unexpected character."); break;
        }
    }
}

void Scanner::scanIdentifier()
{
    // consume characters, while they are letters, underscores or numbers
    while(std::isalpha(this->peek(1))
    || this->peek(1) == '_'
    || std::isdigit(this->peek(1)))
    {
        this->advance();
    }

    std::string identifier = this->statement.substr(this->start, this->current - this->start);

    // check for reserved keywords
    if(identifier == "true") this->tokens.push_back(new Token(BTRUE, this->line));
    else if(identifier == "false") this->tokens.push_back(new Token(BFALSE, this->line));
    else if(identifier == "not") this->tokens.push_back(new Token(NOT, this->line));
    else if(identifier == "and") this->tokens.push_back(new Token(AND, this->line));
    else if(identifier == "or") this->tokens.push_back(new Token(OR, this->line));

    // if it's not reserved, push the string as an identifier
    else this->tokens.push_back(new Token(IDENTIFIER, this->line, identifier));
}

void Scanner::scanNumber()
{
    // consume characters, while they are numbers for the integer part
    while(std::isdigit(this->peek(1)))
    {
        this->advance();
    }

    // if there's a decimal point followed by another digit, start consuming
    // digits for the fractional part of the number
    if(this->peek(1) == '.' && std::isdigit(peek(2)))
    {
        this->advance();
        while(std::isdigit(this->peek(1)))
        {
            this->advance();
        }
    }

    // convert the whole string to a double and push it as a number token
    double number = std::stod(this->statement.substr(this->start, this->current - this->start));
    this->tokens.push_back(new Token(NUMBER, this->line, number));
}

// check if the scanner has reached the end of the statement
bool Scanner::atEnd()
{
    return this->current >= static_cast<signed>(this->statement.length());
}

// loop over the statement, scanning tokens
std::vector<Token*> Scanner::scanTokens()
{
    while(!this->atEnd())
    {
        this->start = this->current;
        this->scanToken();
    }
    return tokens;
}
