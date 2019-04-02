#include "Scanner.hpp"
#include "../exceptions/NotImplementedException.hpp"

lexical_analysis::Scanner::Scanner(std::string statement)
{
    this->statement = statement;
}

std::vector<lexical_analysis::Token> lexical_analysis::Scanner::scanTokens()
{
    throw exceptions::NotImplementedException();
}
