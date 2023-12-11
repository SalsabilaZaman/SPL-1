#include <bits/stdc++.h>
using namespace std;

vector<double> coefficientsOfXsquare;
vector<double> coefficientsOfX;
vector<double> constants;

bool isOp(string c) {
    return c == "+" || c == "-" || c == "*" || c == "/" || c == "^";
}
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' ||c == '=';
}
bool isOperand(string token) {
    return !isOp(token) && token != "(" && token != ")";
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
		if(tokens[i].find("x")!=string::npos && tokens[i].find("^")!=string::npos){
			string coOfX="";
			if(i!=0)
			   coOfX=tokens[i-1];
			if(tokens[i].substr(0,tokens[i].find("x"))=="")
			   coOfX+="1";
			else   			
			   coOfX+=tokens[i].substr(0,tokens[i].find("x"));			
			coefficientsOfXsquare.push_back(stod(coOfX));
		}
		else if(tokens[i].find("x")!=string::npos ){
			string coOfX="";
			if(i!=0)
			   coOfX=tokens[i-1];
			if(tokens[i].substr(0,tokens[i].find("x"))=="")
			   coOfX+="1";
			else   			
			   coOfX+=tokens[i].substr(0,tokens[i].find("x"));			
			coefficientsOfX.push_back(stod(coOfX));
		}
		else if(!isOp(tokens[i])){
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
		if(tokens[i].find("x")!=string::npos && tokens[i].find("^")!=string::npos){
			string coOfX;
			if(isOp(tokens[i-1]))
			   coOfX=makeOpposite(tokens[i-1]);
			else
			   coOfX=makeOpposite("+");   
			if(tokens[i].substr(0,tokens[i].find("x"))=="")
			   coOfX+="1";
			else   			
			   coOfX+=tokens[i].substr(0,tokens[i].find("x"));			
			coefficientsOfXsquare.push_back(stod(coOfX));
		}
		else if(tokens[i].find("x")!=string::npos){
			string coOfX;
			if(isOp(tokens[i-1]))
			   coOfX=makeOpposite(tokens[i-1]);
			else
			   coOfX=makeOpposite("+");   
			if(tokens[i].substr(0,tokens[i].find("x"))=="")
			   coOfX+="1";
			else   			
			   coOfX+=tokens[i].substr(0,tokens[i].find("x"));			
			coefficientsOfX.push_back(stod(coOfX));
		}
		else if(isOperand(tokens[i])){
		    	string constant;
			if(isOp(tokens[i-1]))
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

int main(){
	string equation;
	double a=0,b=0,c=0,x;
	cout <<"Enter your equation:";
	getline(cin,equation);
	vector<string> tokens=tokenizeEquation(equation);
	
	cout<<"Tokens-";
	for(auto t:tokens)
		cout <<t<<" ";
	cout <<endl;
	standardizeEquation(tokens);
	cout<<"Coefficients Of X^2-";
	for(auto c1:coefficientsOfXsquare){
		a+=c1;
		cout <<c1<<" ";
	}	
	cout <<endl;
	cout<<"Coefficients Of X-";
	for(auto c1:coefficientsOfX){
		b+=c1;
		cout <<c1<<" ";
	}	
	cout <<endl;
	cout<<"Constants-";
	for(auto c2:constants){
		c+=c2;
		cout <<c2<<" ";
	}	
	cout <<endl;
	cout << "a="<<a<<" ";
	cout << "b="<<b<<" ";
	cout << "c="<<c<<" ";
	double determinant=(b*b-4*a*c);
	if(determinant==0){
		cout <<"Both of the roots are same!"<<endl;
		cout <<"x="<<((-b)/2*a)<<endl;
	}
	else if(determinant>0){
		cout << "x1="<<(((-b)+pow(determinant,0.5))/2*a)<<endl;
		cout << "x2="<<(((-b)-pow(determinant,0.5))/2*a)<<endl;
	}
	else{
		cout<<"Roots are complex!";
	}
	return 0;
}
