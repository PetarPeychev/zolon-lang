#include <fstream>
#include <sstream>
#include <iostream>
#include "preprocessor.h"

std::vector<Lexeme> preprocess(std::vector<Lexeme> tokens) {

    // Find import statements
    for (auto &token : tokens) {
        if (token.value == "import") {
            if (token.type == IDENTIFIER) {

                // TODO: Implement import statements

            }
        }

        std::cout << token.value << " "; // Remove in production
    }

    std::cout << std::endl; // Remove in production

    return tokens;
}
