#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

// Emum representing every lexeme type
enum LexemeType {
  PARENTHESIS, OPERATOR, SYMBOL, NUMBER, STRING, KEYWORD, NAME
};

// Struct defining a single lexeme
typedef struct Lexeme {
  LexemeType type;
  string value;
} Lexeme;

// Splitting source code into lexemes and returning them in a vector<Lexeme>
vector<Lexeme> tokenize(string source) {

  int current = 0;

  vector <Lexeme> lexemes;

  // Replace all newlines and tabs with spaces
  for (int i = 0; i < int(source.length()); i++) {
    if (source[i] == '\n' || source[i] == '\t') {
      source[i] = ' ';
    }
  }

  // Read lexemes and push them onto the vector
  while (current < int(source.length())) {

    // TODO: Store current character and check for lexemes

  }

  return lexemes;
}

// TODO: Abstract out the command-line program from lexical analyser
int main(int argc, char* argv[]) {

  // Validate number of command-line arguments
  if (argc == 1)
    cout << "No file name argument provided!";

  if (argc > 2)
    cout << "Too many arguments provided!";

  if (argc >= 2) {
    cout << "File name argument provided: " << argv[1] << endl;
  }

  // Read source file and store in a string
  std::ifstream input(argv[1]);
  std::stringstream sstr;
  while(input >> sstr.rdbuf());
  string sourceCode = sstr.str();

  cout << sourceCode;

  tokenize(sourceCode);

  string x;
  std::getline(cin, x);

  return 0;
}
