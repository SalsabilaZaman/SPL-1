#include <bits/stdc++.h>
using namespace std;

typedef struct node 
{
	string data;
	struct node *left, *right;
} * nptr;

bool isOp(string c) {
    return c == "+" || c == "-" || c == "*" || c == "/" || c == "^";
}
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}
bool isOperand(string token) {
    return !isOp(token) && token != "(" && token != ")";
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

// Function to create new node
nptr newNode(string s)
{
	nptr n = new node;
	n->data = s;
	n->left = n->right = nullptr;
	return n;
}

int p(string op){
	int precedence;
	if(op=="+" || op=="-" )
		precedence=1;
	else if(op=="*" || op=="/" )
		precedence=2;
	else if(op=="(" || op==")" )
		precedence=0;
	else if(op=="^")
		precedence=3;
					
	return precedence;
}

				// Function to build Expression Tree
nptr build(vector<string> s)
{

	stack<nptr> stN;							// Stack to hold nodes
	stack<string> stC;
	nptr t, t1, t2;


	for (int i = 0; i <s.size(); i++) 
	{
		if (s[i] == "(") {
			stC.push(s[i]);
		}

		else if (isOperand(s[i])) 
		{
			t = newNode(s[i]);
			stN.push(t);
		}
		else if (p(s[i]) > 0) 
		{
			while (
				!stC.empty() && stC.top() != "("
				&& ((s[i] != "^" && p(stC.top()) >= p(s[i]))
					|| (s[i] == "^"
						&& p(stC.top()) > p(s[i])))) 
			{

				
				t = newNode(stC.top());
				stC.pop();

		
				t1 = stN.top();
				stN.pop();

				
				t2 = stN.top();
				stN.pop();

				t->left = t2;
				t->right = t1;

				stN.push(t);
			}

			
			stC.push(s[i]);
		}
		else if (s[i] == ")") {
			while (!stC.empty() && stC.top() != "(") 
			{
				t = newNode(stC.top());
				stC.pop();
				t1 = stN.top();
				stN.pop();
				t2 = stN.top();
				stN.pop();
				t->left = t2;
				t->right = t1;
				stN.push(t);
			}
			stC.pop();
		}
	}
	t = stN.top();
	return t;
}

stack<double> st;
double calculation(double a,double b,string op){
	if(op=="+")
		return a+b;
	else if(op=="-")
		return a-b;
	else if(op=="*")
		return a*b;
	else if(op=="/")
		return a/b;
	else if(op=="^")
		return pow(a,b);
	else
		return 0;	
}

void postorder(nptr root)
{
	if (root) 
	{
		postorder(root->left);
		postorder(root->right);
		cout << root->data;
		if(isOperand(root->data))
			st.push(stod(root->data));
		else{
		     double b=st.top();
		     st.pop();
		     double a=st.top();
		     st.pop();
		     double calc=calculation(a,b,root->data);
		     st.push(calc);	
		}	
	}
}

void expressionEvaluate(string expression){
    //string expression;
    //cout << "Enter an arithmetic expression: ";
    //cin >>expression;
    expression="("+expression+")";    

    vector<string> tokens = tokenizeExpression(expression);

    cout << "Tokens: ";
    for (string token : tokens) {
        cout << token << "  ";
    }
    cout << endl;

    nptr root = build(tokens);
    cout <<endl<<"Converted postfix expression-";	
    postorder(root);
    cout<<"\n\nAnswer="<<st.top()<<endl;

}

