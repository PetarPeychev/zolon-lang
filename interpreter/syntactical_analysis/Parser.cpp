#include "Parser.hpp"

using namespace syntactical_analysis;
using namespace lexical_analysis;

Parser::Parser(std::vector<Token*> tokens)
{
    this->current = 0;
    this->tokens = tokens;
}
