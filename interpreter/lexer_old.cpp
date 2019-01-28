// #include <iostream>
// #include <string>
// #include <vector>
// #include <regex>
//
// using std::string;
// using std::cin;
// using std::cout;
// using std::endl;
// using std::vector;
//
// // // Emum representing every lexeme type
// // enum LexemeType {
// //   PARENTHESIS, OPERATOR, SYMBOL, NUMBER, STRING, KEYWORD, NAME
// // };
// //
// // // Struct defining a single lexeme
// // typedef struct Lexeme {
// //   LexemeType type;
// //   string value;
// // } Lexeme;
//
// // Splitting source code into lexemes and returning them in a vector<Lexeme>
// vector<Lexeme> tokenize(string source) {
//
//   int current = 0;
//   int max_length = source.length();
//
//   // vector <Lexeme> lexemes;
//
//   // // Replace all newlines and tabs with spaces
//   // for (int i = 0; i < int(source.length()); i++) {
//   //   if (source[i] == '\n' || source[i] == '\t') {
//   //     source[i] = ' ';
//   //   }
//   // }
//
//   // TODO: Remove in production
//   cout << source << endl;
//
//   // Read lexemes and push them onto the vector
//   while (current < int(source.length())) {
//
//     char c = source[current];
//
//     // TODO: Change from switch-case to if-else with regex matching
//     switch (c) {
//
//       // Check for PARENTHESIS LexemeType
//       case '(':
//       case ')': {
//         Lexeme paren = { PARENTHESIS, string(1, c) };
//         lexemes.push_back(paren);
//         current++;
//         continue;
//       }
//
//       // Check for single-length OPERATOR LexemeType
//       case '+':
//       case '-':
//       case '*':
//       case '/': {
//         Lexeme op = { OPERATOR, string(1, c) };
//         lexemes.push_back(op);
//         current++;
//         continue;
//       }
//
//       // Check for multi-length OPERATOR LexemeType
//       case '>':
//       case '<': {
//         string op = string(1, c);
//         if (++current < max_length) {
//
//           c = source[current];
//
//           if (c == '=') {
//             op = op + string(1, c);
//             current++;
//           }
//
//           Lexeme l = { OPERATOR, op };
//           continue;
//         }
//       }
//     }
//   }
//
//   return lexemes;
// }
