#include "Parser.hpp"
#include "../Interpreter.hpp"

using namespace syntactical_analysis;
using namespace lexical_analysis;
using namespace syntax_tree;

Parser::Parser(std::vector<Token*> tokens, evaluation::Environment *environment)
{
    // counter for the current token, similar to the scanner
    this->current = 0;

    // the token vector
    this->tokens = tokens;

    // a reference to the environment is required for 2 purposes:
    // 1. To evaluate bindings and function applications.
    // 2. To handle ambiguities in the grammar during the syntactical analysis pass
    this->environment = environment;
}

// the first parsing call in the recursive hierarchy
Statement *Parser::parseStatement()
{
    return this->statement();
}

// return an error to the interpreter
void Parser::error(std::string message)
{
    Interpreter::error(this->peek()->tokenLine(), message);
}

// same match logic as the Scanner, but this is an overloaded version,
// which can match a vector of many token types
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

// same match logic as the Scanner
bool Parser::match(TokenType type)
{
    if(this->check(type))
    {
        this->advance();
        return true;
    }
    return false;
}

// check serves a similar function to peek(1) in the Scanner
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

// similar to the peek(lookahead) from the Scanner
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

// same logic as advance in the Scanner - consumes a token
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

// check if the end of the token vector is (lookahead - 1) indices after current
bool Parser::atEnd(int lookahead)
{
    return this->current + lookahead - 1 >= static_cast<signed>(this->tokens.size());
}

// peek functions here are unsafe versions of the check functions
Token *Parser::peek()
{
    return this->tokens[this->current];
}

// same as above, with lookahead
Token *Parser::peek(int lookahead)
{
    return this->tokens[this->current + lookahead - 1];
}

// return the token just consumed
Token *Parser::previous()
{
    return this->tokens[this->current - 1];
}

// statements can be either bindings or expressions
// they can also be imports in the grammar, but that is to be implemented
// for a more higher-level view of this whole hierarchy, refer to the grammar definition
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

// a binding is in the format "IDENTIFIER BIND expression"
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
        // Logically impossible, as the condition is checked
        // in the statement function
        this->error("Missing an expected '=' after identifier.");
        return new InvalidBinding();
    }

    // construct and return a binding with a name and a pointer to an expression
    Expression *expr = this->expression();
    return new Binding(name, expr);
}

// the operator precedences and associativities are encoded as successive
// levels of recursive parsing calls. For details, refer to the grammar
Expression *Parser::expression()
{
    return this->logical();
}

// logical expressions of the format "expression LOGICAL_OPERATOR expression"
Expression *Parser::logical()
{
    Expression *expression = this->equality();
    std::vector<TokenType> operators = {AND, OR};
    while(this->match(operators))
    {
        Token *op = this->previous();
        Expression *right = this->equality();
        LogicalOperator logOp;
        switch(op->tokenType())
        {
            case(AND): logOp = Conjunction; break;
            case(OR): logOp = Disjunction; break;
            default: /* Logically Impossible */ break;
        }
        expression = new LogicalOperation(logOp, expression, right);
    }
    return expression;
}

// equality expressions of the format "expression EQUALITY_OPERATOR expression"
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

// comparison expressions of the format "expression RELATIONAL_OPERATOR expression"
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

// addition expressions of the format "expression ADDITION_OPERATOR expression"
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

// multiplication expressions of the format "expression MULTPLICATION_OPERATOR expression"
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

// unary expressions of the format "UNARY_OPERATOR expression"
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

// primitive values, which can be used in expressions
Expression *Parser::primary()
{
    // boolean literals
    if(this->match(BTRUE))
    {
        return new BooleanLiteral(true);
    }
    else if(this->match(BFALSE))
    {
        return new BooleanLiteral(false);
    }

    // numbers
    else if(this->match(NUMBER))
    {
        return new NumberLiteral(this->previous()->tokenNval());
    }
    // identifiers can either be functions or function calls,
    // so there needs to be a contextual check to disambiguate the grammar
    // This is why we need to check the environment to parse.
    else if(this->match(IDENTIFIER))
    {
        evaluation::Value *value = this->environment->find(this->previous()->tokenSval());

        // if the identifier refers to a zero-parameter function,
        // then we treat it as a function call
        if(value->valueType() == evaluation::NUMBER)
        {
            return new NumberLiteral(value->valueNval());
        }
        else if(value->valueType() == evaluation::BOOLEAN)
        {
            return new BooleanLiteral(value->valueBval());
        }
        // else, we treat it as a function value or throw an error
        else
        {
            // This is where the function parsing code would go.
            this->error("Attempting to call a nonexistent function.");
            return new InvalidExpression();
        }
    }
    // groupings of the format "( expression )"
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
    // if all else fails, throw a parsing error and return an invalid expression
    else
    {
        this->error("Unrecognized expression type.");
        return new InvalidExpression();
    }
}
