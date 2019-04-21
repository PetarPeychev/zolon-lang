#include "Parser.hpp"
#include "../Interpreter.hpp"

using namespace syntactical_analysis;
using namespace lexical_analysis;
using namespace syntax_tree;

Parser::Parser(std::vector<Token*> tokens)
{
    this->current = 0;
    this->tokens = tokens;
}

Statement *Parser::parseStatement()
{
    return this->statement();
}

void Parser::error(std::string message)
{
    Interpreter::error(this->peek()->tokenLine(), message);
}

bool Parser::match(std::vector<TokenType> types)
{
    for(auto type : types)
    {
        if(this->check(type))
        {
            this->advance();
            return true;
        }
    }
    return false;
}

bool Parser::match(TokenType type)
{
    if(this->check(type))
    {
        this->advance();
        return true;
    }
    return false;
}

bool Parser::check(TokenType type)
{
    if(this->atEnd())
    {
        return false;
    }
    else
    {
        return this->peek()->tokenType() == type;
    }
}

bool Parser::check(TokenType type, int lookahead)
{
    if(this->atEnd(lookahead))
    {
        return false;
    }
    else
    {
        return this->peek(lookahead)->tokenType() == type;
    }
}

Token *Parser::advance()
{
    if(!this->atEnd())
    {
        this->current++;
    }
    return this->previous();
}

bool Parser::atEnd()
{
    return this->current >= static_cast<signed>(this->tokens.size());
}

bool Parser::atEnd(int lookahead)
{
    return this->current + lookahead - 1 >= static_cast<signed>(this->tokens.size());
}

Token *Parser::peek()
{
    return this->tokens[this->current];
}

Token *Parser::peek(int lookahead)
{
    return this->tokens[this->current + lookahead - 1];
}

Token *Parser::previous()
{
    return this->tokens[this->current - 1];
}

Statement *Parser::statement()
{
    if(this->check(IDENTIFIER) && this->check(BIND, 2))
    {
        return new Statement(this->binding());
    }
    else
    {
        return new Statement(this->expression());
    }
}

Binding *Parser::binding()
{
    this->match(IDENTIFIER);
    std::string name = this->previous()->tokenSval();
    if(this->check(BIND))
    {
        this->advance();
    }
    else
    {
        this->error("Missing an expected '=' after identifier.");
        return new InvalidBinding();
    }
    Expression *expr = this->expression();
    return new Binding(name, expr);
}

Expression *Parser::expression()
{
    return this->equality();
}

Expression *Parser::equality()
{
    Expression *expression = this->comparison();
    std::vector<TokenType> operators = {EQUALS, NEQUALS};
    while(this->match(operators))
    {
        Token *op = this->previous();
        Expression *right = this->comparison();
        RelationalOperator relOp;
        switch(op->tokenType())
        {
            case(EQUALS): relOp = Equality; break;
            case(NEQUALS): relOp = Inequality; break;
            default: /* Logically Impossible */ break;
        }
        expression = new RelationalOperation(relOp, expression, right);
    }
    return expression;
}

Expression *Parser::comparison()
{
    Expression *expression = this->addition();
    std::vector<TokenType> operators = {LESS, LEQUALS, GREATER, GEQUALS};
    while(this->match(operators))
    {
        Token *op = this->previous();
        Expression *right = this->addition();
        RelationalOperator relOp;
        switch(op->tokenType())
        {
            case(LESS): relOp = LessThan; break;
            case(LEQUALS): relOp = LessOrEqual; break;
            case(GREATER): relOp = GreaterThan; break;
            case(GEQUALS): relOp = GreaterOrEqual; break;
            default: /* Logically Impossible */ break;
        }
        expression = new RelationalOperation(relOp, expression, right);
    }
    return expression;
}

Expression *Parser::addition()
{
    Expression *expression = this->multiplication();
    std::vector<TokenType> operators = {PLUS, MINUS};
    while(this->match(operators))
    {
        Token *op = this->previous();
        Expression *right = this->multiplication();
        ArithmeticOperator arithOp;
        switch(op->tokenType())
        {
            case(PLUS): arithOp = Addition; break;
            case(MINUS): arithOp = Subtraction; break;
            default: /* Logically Impossible */ break;
        }
        expression = new ArithmeticOperation(arithOp, expression, right);
    }
    return expression;
}

Expression *Parser::multiplication()
{
    Expression *expression = this->unary();
    std::vector<TokenType> operators = {ASTERISK, FSLASH};
    while(this->match(operators))
    {
        Token *op = this->previous();
        Expression *right = this->unary();
        ArithmeticOperator arithOp;
        switch(op->tokenType())
        {
            case(ASTERISK): arithOp = Multiplication; break;
            case(FSLASH): arithOp = Division; break;
            default: /* Logically Impossible */ break;
        }
        expression = new ArithmeticOperation(arithOp, expression, right);
    }
    return expression;
}

Expression *Parser::unary()
{
    std::vector<TokenType> arithOperators = {MINUS};
    std::vector<TokenType> logicOperators = {NOT};
    if(this->match(arithOperators))
    {
        Token *op = this->previous();
        Expression *right = this->unary();
        ArithmeticOperator arithOp;
        switch(op->tokenType())
        {
            case(MINUS): arithOp = ArithmeticNegation; break;
            default: /* Logically Impossible */ break;
        }
        return new ArithmeticOperation(arithOp, right);
    }
    else if(this->match(logicOperators))
    {
        Token *op = this->previous();
        Expression *right = this->unary();
        LogicalOperator logicOp;
        switch(op->tokenType())
        {
            case(NOT): logicOp = LogicalNegation; break;
            default: /* Logically Impossible */ break;
        }
        return new LogicalOperation(logicOp, right);
    }
    return this->primary();
}

Expression *Parser::primary()
{
    if(this->match(BTRUE))
    {
        return new BooleanLiteral(true);
    }
    else if(this->match(BFALSE))
    {
        return new BooleanLiteral(false);
    }
    else if(this->match(NUMBER))
    {
        return new NumberLiteral(this->previous()->tokenNval());
    }
    else if(this->match(LPAREN))
    {
        Expression *expr = this->expression();
        if(this->check(RPAREN))
        {
            this->advance();
        }
        else
        {
            this->error("Missing an expected ')' after expression.");
            return new InvalidExpression();
        }
        return expr;
    }
    else
    {
        this->error("Unrecognized expression type.");
        return new InvalidExpression();
    }
}
