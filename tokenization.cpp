#include <iostream>
#include <vector>
#include <string>

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

std::vector<std::string> tokenizeExpression(const std::string& expression) {
    std::vector<std::string> tokens;
    std::string token;

    for (char c : expression) {
        if (c == ' ') {
            continue;
        }

        if (isOperator(c) || c == '(' || c == ')') {
            
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
            tokens.push_back(std::string(1, c));
        } else {
            
            token += c;
        }
    }

   
    if (!token.empty()) {
        tokens.push_back(token);
    }

    return tokens;
}

int main() {
    std::string expression;
    std::cout << "Enter an arithmetic expression: ";
    std::getline(std::cin, expression);

    std::vector<std::string> tokens = tokenizeExpression(expression);

    std::cout << "Tokens: ";
    for (const std::string& token : tokens) {
        std::cout << token << "		";
    }
    std::cout << std::endl;

    return 0;
}

