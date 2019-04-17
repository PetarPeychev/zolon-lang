/*-------------------------------------------------------

The parser class, which performs syntactical analysis
according to the grammar and builds a syntax tree.

---------------------------------------------------------*/

#ifndef SYNTACTICALANALYSIS_PARSER_H
#define SYNTACTICALANALYSIS_PARSER_H

#include <vector>
#include "../lexical_analysis/Token.hpp"

namespace syntactical_analysis {

class Parser
{
private:
    std::vector<lexical_analysis::Token*> tokens;
    int current;
public:
    Parser(std::vector<lexical_analysis::Token*>);
};
}

#endif
