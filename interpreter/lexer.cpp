#include <iostream>
#include <regex>
#include <unordered_set>
#include "lexer.h"

// Reserved identifiers
const std::unordered_set<std::string> BOOLEAN_OPERATORS = {"and", "or"};
const std::unordered_set<std::string> BOOLEAN_LITERALS = {"true", "false"};
const std::unordered_set<std::string> PREFIX_OPERATORS = {"not"};

// Replace all newlines and tabs with spaces
std::string flatten(std::string source) {
    for (char &i : source) {
        if (i == '\n' || i == '\t') {
            i = ' ';
        }
    }
    return source;
}

// Splitting source code into lexemes
std::vector<Lexeme> tokenize(std::string source) {

    std::vector <Lexeme> lexemes;
    source = flatten(source);
    int current = 0;
    auto max_length = static_cast<int>(source.length());

    std::cout << "Flat Code:\n" << source << std::endl; // Remove in production

    while (current < max_length) {

        std::string c(1, source[current]);

        // Match whitespace and discard it.
        // Not added to vector, but required for separating other lexemes
        std::regex whitespace(" ");
        if (regex_match(c, whitespace)) {
            current++;
            continue;
        }

        // Match parentheses
        std::regex leftParenthesis("\\(");
        if (regex_match(c, leftParenthesis)) {
            Lexeme lex = { L_PARENTHESIS, c };
            lexemes.push_back(lex);
            current++;
            std::cout << "L_PARENTHESIS: " << c << std::endl; // Remove in production
            continue;
        }

        std::regex rightParenthesis("\\)");
        if (regex_match(c, rightParenthesis)) {
            Lexeme lex = { R_PARENTHESIS, c };
            lexemes.push_back(lex);
            current++;
            std::cout << "R_PARENTHESIS: " << c << std::endl; // Remove in production
            continue;
        }

        // Match brackets
        std::regex leftBracket("\\[");
        if (regex_match(c, leftBracket)) {
            Lexeme lex = { L_BRACKET, c };
            lexemes.push_back(lex);
            current++;
            std::cout << "L_BRACKET: " << c << std::endl; // Remove in production
            continue;
        }

        std::regex rightBracket("\\]");
        if (regex_match(c, rightBracket)) {
            Lexeme lex = { R_BRACKET, c };
            lexemes.push_back(lex);
            current++;
            std::cout << "R_PARENTHESIS: " << c << std::endl; // Remove in production
            continue;
        }

        // Match colon
        std::regex colon(":");
        if (regex_match(c, colon)) {
            Lexeme lex = { COLON, c};
            lexemes.push_back(lex);
            current++;
            std::cout << "COLON: " << c << std::endl; // Remove in production
            continue;
        }

        // Match pipe or bar
        std::regex bar("\\|");
        if (regex_match(c, bar)) {
            if (current + 1 < max_length) {
                std::string c_new = c + source[current + 1];

                std::regex pipe("\\|>");
                if (regex_match(c_new, pipe)) {
                    Lexeme lex = { PIPE_OPERATOR, c_new };
                    lexemes.push_back(lex);
                    current += 2;
                    std::cout << "PIPE_OPERATOR: " << c_new << std::endl; // Remove in production
                    continue;
                }
            }

            Lexeme lex = { BAR, c };
            lexemes.push_back(lex);
            current++;
            std::cout << "BAR: " << c << std::endl; // Remove in production
            continue;
        }

        // Match arithmetic operators
        std::regex plus("\\+");
        if (regex_match(c, plus)) {
            Lexeme lex = { ARITHMETIC_OPERATOR, c};
            lexemes.push_back(lex);
            current++;
            std::cout << "ARITHMETIC_OPERATOR: " << c << std::endl; // Remove in production
            continue;
        }

        std::regex asterisk("\\*");
        if (regex_match(c, asterisk)) {
            Lexeme lex = { ARITHMETIC_OPERATOR, c};
            lexemes.push_back(lex);
            current++;
            std::cout << "ARITHMETIC_OPERATOR: " << c << std::endl; // Remove in production
            continue;
        }

        std::regex slash("/");
        if (regex_match(c, slash)) {
            Lexeme lex = { ARITHMETIC_OPERATOR, c};
            lexemes.push_back(lex);
            current++;
            std::cout << "ARITHMETIC_OPERATOR: " << c << std::endl; // Remove in production
            continue;
        }

        // Match -> or -
        std::regex dash("-");
        if (regex_match(c, dash)) {
            if (current + 1 < max_length) {
                std::string c_new = c + source[current + 1];

                std::regex mapping("->");
                if (regex_match(c_new, mapping)) {
                    Lexeme lex = { MAPPING_OPERATOR, c_new };
                    lexemes.push_back(lex);
                    current += 2;
                    std::cout << "MAPPING_OPERATOR: " << c_new << std::endl; // Remove in production
                    continue;
                }
            }

            Lexeme lex = { ARITHMETIC_OPERATOR, c };
            lexemes.push_back(lex);
            current++;
            std::cout << "ARITHMETIC_OPERATOR: " << c << std::endl; // Remove in production
            continue;
        }

        // Match == or =
        std::regex equals("=");
        if (regex_match(c, equals)) {
            if (current + 1 < max_length) {
                std::string c_new = c + source[current + 1];

                std::regex equality("==");
                if (regex_match(c_new, equality)) {
                    Lexeme lex = { COMPARISON_OPERATOR, c_new };
                    lexemes.push_back(lex);
                    current += 2;
                    std::cout << "COMPARISON_OPERATOR: " << c_new << std::endl; // Remove in production
                    continue;
                }
            }

            Lexeme lex = { ASSIGNMENT_OPERATOR, c };
            lexemes.push_back(lex);
            current++;
            std::cout << "ASSIGNMENT_OPERATOR: " << c << std::endl; // Remove in production
            continue;
        }

        // Match < or <=
        std::regex lessThan("<");
        if (regex_match(c, lessThan)) {
            if (current + 1 < max_length) {
                std::string c_new = c + source[current + 1];

                std::regex lessOrEqual("<=");
                if (regex_match(c_new, lessOrEqual)) {
                    Lexeme lex = { COMPARISON_OPERATOR, c_new };
                    lexemes.push_back(lex);
                    current += 2;
                    std::cout << "COMPARISON_OPERATOR: " << c_new << std::endl; // Remove in production
                    continue;
                }
            }

            Lexeme lex = { COMPARISON_OPERATOR, c };
            lexemes.push_back(lex);
            current++;
            std::cout << "COMPARISON_OPERATOR: " << c << std::endl; // Remove in production
            continue;
        }

        // Match > or >=
        std::regex moreThan(">");
        if (regex_match(c, moreThan)) {
            if (current + 1 < max_length) {
                std::string c_new = c + source[current + 1];

                std::regex moreOrEqual("<=");
                if (regex_match(c_new, moreOrEqual)) {
                    Lexeme lex = { COMPARISON_OPERATOR, c_new };
                    lexemes.push_back(lex);
                    current += 2;
                    std::cout << "COMPARISON_OPERATOR: " << c_new << std::endl; // Remove in production
                    continue;
                }
            }

            Lexeme lex = { COMPARISON_OPERATOR, c };
            lexemes.push_back(lex);
            current++;
            std::cout << "COMPARISON_OPERATOR: " << c << std::endl; // Remove in production
            continue;
        }

        // Match !=
        std::regex exclamation("!");
        if (regex_match(c, exclamation)) {
            if (current + 1 < max_length) {
                std::string c_new = c + source[current + 1];

                std::regex notEquals("!=");
                if (regex_match(c_new, notEquals)) {
                    Lexeme lex = { COMPARISON_OPERATOR, c_new };
                    lexemes.push_back(lex);
                    current += 2;
                    std::cout << "COMPARISON_OPERATOR: " << c_new << std::endl; // Remove in production
                    continue;
                }
            }

            Lexeme lex = { COMPARISON_OPERATOR, c };
            lexemes.push_back(lex);
            current++;
            std::cout << "COMPARISON_OPERATOR: " << c << std::endl; // Remove in production
            continue;
        }

        // Match reserved or free identifiers
        std::regex identifierStartingChar("[_a-zA-Z]");
        if (regex_match(c, identifierStartingChar)) {
            std::string word;

            std::regex identifierChar("\\w");
            while (current < max_length) {
                c = std::string(1, source[current]);
                if (regex_match(c, identifierChar)) {
                    word += c;
                    current++;
                }
                else {
                    current--;

                    // Check if identifier is a boolean operator
                    if (BOOLEAN_OPERATORS.find(word) != BOOLEAN_OPERATORS.end()) {
                        Lexeme lex = { BOOLEAN_OPERATOR, word };
                        lexemes.push_back(lex);
                        std::cout << "BOOLEAN_OPERATOR: " << word << std::endl; // Remove in production
                        break;
                    }

                    // Check if identifier is a boolean literal
                    if (BOOLEAN_LITERALS.find(word) != BOOLEAN_LITERALS.end()) {
                        Lexeme lex = { BOOLEAN_LITERAL, word };
                        lexemes.push_back(lex);
                        std::cout << "BOOLEAN_LITERAL: " << word << std::endl; // Remove in production
                        break;
                    }

                    // Check if identifier is a prefix operator
                    if (PREFIX_OPERATORS.find(word) != PREFIX_OPERATORS.end()) {
                        Lexeme lex = { PREFIX_OPERATOR, word };
                        lexemes.push_back(lex);
                        std::cout << "PREFIX_OPERATOR: " << word << std::endl; // Remove in production
                        break;
                    }

                    Lexeme lex = { IDENTIFIER, word };
                    lexemes.push_back(lex);
                    std::cout << "IDENTIFIER: " << word << std::endl; // Remove in production
                    break;
                }
            }

            current++;
            continue;
        }


        // Match numbers, which start with a digit and are followed by
        // 0+ digits or decimal points. Does not validate numbers
        std::regex digit("[0-9]");
        if (regex_match(c, digit)) {
            std::string digits;

            std::regex num("[0-9.]+");
            while (current < max_length) {
                c = std::string(1, source[current]);
                if (regex_match(c, num)) {
                    digits += c;
                    current++;
                    continue;
                }
                Lexeme lex = { NUMBER_LITERAL, digits };
                lexemes.push_back(lex);
                std::cout << "NUMBER_LITERAL: " << digits << std::endl; // Remove in production
                break;
            }
            continue;
        }

        // If no match, return an unrecognized lexeme error
        throw std::invalid_argument(
                "\nLexical Analysis Error:\nLexeme \"" + c + "\" not recognized.");
    }
    return lexemes;
}
