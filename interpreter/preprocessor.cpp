#include <fstream>
#include <sstream>
#include <iostream>
#include "preprocessor.h"

std::vector<Lexeme> preprocess(std::vector<Lexeme> tokens) {

  // Find import statements
  for (unsigned int i = 0; i < tokens.size(); i++) {
    if (tokens[i].value == "import") {
        if (tokens[i].type == NAME) {

          // TODO: Implement import statements

        }
    }

    std::cout << tokens[i].value << " "; // Remove in production
  }

  std::cout << std::endl; // Remove in production

  return tokens;
}
