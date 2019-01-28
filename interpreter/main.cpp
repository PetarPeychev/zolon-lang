#include <iostream>
#include <fstream>
#include <sstream>
#include "lexer.h"

int main(int argc, char* argv[]) {

  // Validate number of command-line arguments
  if (argc == 1) {
    std::cout << "No file name argument provided!";
    return 1;
  }

  if (argc > 2) {
    std::cout << "Too many arguments provided!";
    return 1;
  }

  if (argc >= 2) {
    std::cout << "File name argument provided: " << argv[1] << std::endl;
  }

  // Read source file and store in a string
  std::ifstream input(argv[1]);
  std::stringstream sstr;
  while(input >> sstr.rdbuf());
  std::string sourceCode = sstr.str();

  std::cout << "Original Code:\n" << sourceCode << std::endl; // Remove in production

  std::vector<Lexeme> tokenVector = tokenize(sourceCode);

  std::string x;
  std::getline(std::cin, x);

  return 0;
}
