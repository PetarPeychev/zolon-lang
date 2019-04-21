/*-------------------------------------------------------

The parser class, which performs syntactical analysis
according to the grammar and builds a syntax tree.

---------------------------------------------------------*/

#ifndef SYNTACTICALANALYSIS_PARSER_H
#define SYNTACTICALANALYSIS_PARSER_H

#include <vector>
#include <string>
#include "../lexical_analysis/Token.hpp"
#include "../syntax_tree/syntax_tree.hpp"

namespace syntactical_analysis {

class Parser
{
private:
    std::vector<lexical_analysis::Token*> tokens;
    int current;
    void error(std::string);
    bool match(std::vector<lexical_analysis::TokenType>);
    bool match(lexical_analysis::TokenType);
    bool check(lexical_analysis::TokenType);
    bool check(lexical_analysis::TokenType, int);
    lexical_analysis::Token *advance();
    bool atEnd();
    bool atEnd(int);
    lexical_analysis::Token *peek();
    lexical_analysis::Token *peek(int);
    lexical_analysis::Token *previous();
    syntax_tree::Statement *statement();
    syntax_tree::Binding *binding();
    syntax_tree::Expression *expression();
    syntax_tree::Expression *equality();
    syntax_tree::Expression *comparison();
    syntax_tree::Expression *addition();
    syntax_tree::Expression *multiplication();
    syntax_tree::Expression *unary();
    syntax_tree::Expression *primary();
    syntax_tree::Expression *boolean();
    syntax_tree::Expression *function();
    syntax_tree::Expression *function_body();
    syntax_tree::Expression *subdomain_list();
    syntax_tree::Expression *function_application();
public:
    Parser(std::vector<lexical_analysis::Token*>);
    syntax_tree::Statement *parseStatement();
};
}

#endif
