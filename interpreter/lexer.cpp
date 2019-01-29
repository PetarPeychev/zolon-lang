#include <iostream>
#include <regex>
#include <unordered_set>
#include "lexer.h"

const std::unordered_set<std::string> RESERVED_WORDS = {"is", "and", "or", "not", "import"};

// Replace all newlines and tabs with spaces
std::string flatten(std::string source) {
  for (int i = 0; i < int(source.length()); i++) {
    if (source[i] == '\n' || source[i] == '\t') {
      source[i] = ' ';
    }
  }
  return source;
}

// Splitting source code into lexemes
std::vector<Lexeme> tokenize(std::string source) {

  std::vector <Lexeme> lexemes;
  source = flatten(source);
  int current = 0;
  int max_length = source.length();

  std::cout << "Flat Code:\n" << source << std::endl; // Remove in production

  while (current < int(max_length)) {

    std::string c(1, source[current]);

    std::regex whitespace(" ");
    if (regex_match(c, whitespace)) {
      current++;
      continue;
    }

    std::regex paren("[()]");
    if (regex_match(c, paren)) {
      Lexeme parenthesis = { PARENTHESIS, c };
      lexemes.push_back(parenthesis);
      current++;
      std::cout << "PARENTHESIS: " << c << std::endl; // Remove in production
      continue;
    }

    std::regex single_symbol("[:]");
    if (regex_match(c, single_symbol)) {
      Lexeme single_symbol = { SYMBOL, c};
      lexemes.push_back(single_symbol);
      current++;
      std::cout << "SYMBOL: " << c << std::endl; // Remove in production
      continue;
    }

    std::regex potential_double_s("\\|");
    if (regex_match(c, potential_double_s)) {
      if (current + 1 < int(max_length)) {
        std::string c_new = c + source[current + 1];

        std::regex double_s("\\|>");
        if (regex_match(c_new, double_s)) {
          Lexeme double_symbol = { SYMBOL, c_new };
          lexemes.push_back(double_symbol);
          current += 2;
          std::cout << "SYMBOL: " << c_new << std::endl; // Remove in production
          continue;
        }
      }

      Lexeme single_symbol = { SYMBOL, c };
      lexemes.push_back(single_symbol);
      current++;
      std::cout << "SYMBOL: " << c << std::endl; // Remove in production
      continue;
    }

    std::regex single_op("[+\\-\\*/=]");
    if (regex_match(c, single_op)) {
      Lexeme single_operator = { OPERATOR, c};
      lexemes.push_back(single_operator);
      current++;
      std::cout << "OPERATOR: " << c << std::endl; // Remove in production
      continue;
    }

    std::regex potential_double_op("[><]");
    if (regex_match(c, potential_double_op)) {
      if (current + 1 < int(max_length)) {
        std::string c_new = c + source[current + 1];

        std::regex double_op("(<=)|(>=)");
        if (regex_match(c_new, double_op)) {
          Lexeme double_operator = { OPERATOR, c_new };
          lexemes.push_back(double_operator);
          current += 2;
          std::cout << "OPERATOR: " << c_new << std::endl; // Remove in production
          continue;
        }
      }

      Lexeme single_operator = { OPERATOR, c };
      lexemes.push_back(single_operator);
      current++;
      std::cout << "OPERATOR: " << c << std::endl; // Remove in production
      continue;
    }

    std::regex letter("[a-zA-Z]");
    if (regex_match(c, letter)) {
      std::string word;

      std::regex w("\\w");
      while (current < int(max_length)) {
        c = std::string(1, source[current]);
        if (regex_match(c, w)) {
          word += c;
          current++;
        }
        else {
          current--;
          if (RESERVED_WORDS.find(word) != RESERVED_WORDS.end()) {
            Lexeme keyword = { KEYWORD, word };
            lexemes.push_back(keyword);
            std::cout << "KEYWORD: " << word << std::endl; // Remove in production
            break;
          }

          Lexeme name = { NAME, word };
          lexemes.push_back(name);
          std::cout << "NAME: " << word << std::endl; // Remove in production
          break;
        }
      }

      current++;
      continue;
    }

    std::regex digit("[0-9]");
    if (regex_match(c, digit)) {
      std::string digits;

      std::regex num("[0-9.]+");
      while (current < int(max_length)) {
        c = std::string(1, source[current]);
        if (regex_match(c, num)) {
          digits += c;
          current++;
          continue;
        }
        Lexeme number = { NUMBER, digits };
        lexemes.push_back(number);
        std::cout << "NUMBER: " << digits << std::endl; // Remove in production
        break;
      }
      continue;
    }

    std::cout << "Lexeme not recognised: " << c << std::endl;
    current++;
    continue;

  }

  return lexemes;
}
