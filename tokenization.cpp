#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

vector<string> tokenizeExpression(string expression) {
    vector<string> tokens;
    string token;

    for (char c : expression) {
        if (c == ' ') {
            continue;
        }

        if (isOperator(c) || c == '(' || c == ')') {
            
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
            tokens.push_back(string(1, c));
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
    string expression;
    cout << "Enter an arithmetic expression: ";
    getline(cin, expression);

    vector<string> tokens = tokenizeExpression(expression);

    cout << "Tokens: ";
    for (string token : tokens) {
        cout << token << "		";
    }
    cout << endl;

    return 0;
}

