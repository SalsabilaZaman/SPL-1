#include <bits/stdc++.h>
using namespace std;

vector<double> coefficients;
vector<double> constants;

bool IsOp(string c) {
    return c == "+" || c == "-" || c == "*" || c == "/" || c == "^";
}
bool IsOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^'||c == '=';
}
bool IsOperand(string token) {
    return !IsOp(token) && token != "(" && token != ")";
}
string makeOpposite(string sign){
	string oppositeSign;
	if(sign=="+")
		oppositeSign="-";
	else if(sign=="-")
		oppositeSign="+";
	return oppositeSign;		
}
void standardizeEquation(vector<string> tokens){
	int i=0;
	while(tokens[i]!="="){
		if(tokens[i].find("x")!=string::npos){
			string coOfX="";
			if(i!=0)
			   coOfX=tokens[i-1];
			if(tokens[i].substr(0,tokens[i].find("x"))=="")
			   coOfX+="1";
			else   			
			   coOfX+=tokens[i].substr(0,tokens[i].find("x"));			
			coefficients.push_back(stod(coOfX));
		}
		else if(!IsOp(tokens[i])){
		    	string constant="";
			if(i!=0)
			   constant=tokens[i-1];
			constant+=tokens[i];			
			constants.push_back(stod(constant));
		}
		i++;	
	}
	i++;
	while(i<tokens.size()){
		if(tokens[i].find("x")!=string::npos){
			string coOfX;
			if(IsOp(tokens[i-1]))
			   coOfX=makeOpposite(tokens[i-1]);
			else
			   coOfX=makeOpposite("+");   
			if(tokens[i].substr(0,tokens[i].find("x"))=="")
			   coOfX+="1";
			else   			
			   coOfX+=tokens[i].substr(0,tokens[i].find("x"));			
			coefficients.push_back(stod(coOfX));
		}
		else if(IsOperand(tokens[i])){
		    	string constant;
			if(IsOp(tokens[i-1]))
			   constant=makeOpposite(tokens[i-1]);
			else
			   constant=makeOpposite("+");
			constant+=tokens[i];			
			constants.push_back(stod(constant));
		}
		i++;
	}

}
vector<string> tokenizeEquation(string expression) {
    vector<string> tokens;
    string token;

    for (char c : expression) {
        if (c == ' ') {
            continue;
        }

        if (IsOperator(c) || c == '(' || c == ')') {
            
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

void  linearEquationSolver(){
	string equation;
	double a=0,b=0,x;
	cout <<"Enter your equation:";
	cin >> equation;
	vector<string> tokens=tokenizeEquation(equation);
	
	cout<<"Tokens-";
	for(auto t:tokens)
		cout <<t<<" ";
	cout <<endl;
	standardizeEquation(tokens);
	
	cout<<"Coefficients-";
	for(auto c1:coefficients){
		a+=c1;
		cout <<c1<<" ";
	}	
	cout <<endl;
	cout<<"Constants-";
	for(auto c2:constants){
		b+=c2;
		cout <<c2<<" ";
	}	
	cout <<endl;
	cout << "a="<<a<<" ";
	cout << "b="<<b<<" ";
	x=((-b)/a);
	cout <<endl<<"x="<<x<<endl;	
}
