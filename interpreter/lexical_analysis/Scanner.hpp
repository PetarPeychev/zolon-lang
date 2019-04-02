/*-------------------------------------------------------

The lexical analyser, which converts a statement string
to a token vector.

---------------------------------------------------------*/

#ifndef LEXICALANALYSIS_SCANNER_H
#define LEXICALANALYSIS_SCANNER_H

#include <string>
#include <vector>
#include "Token.hpp"

namespace lexical_analysis {

class Scanner
{
private:
    std::string statement;
public:
    Scanner(std::string statement);
    std::vector<lexical_analysis::Token> scanTokens();
};
}

#endif