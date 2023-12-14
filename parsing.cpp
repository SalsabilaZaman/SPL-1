#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<char> operands;

void intialize(){
	operands.push_back("+");
	operands.push_back("-");
	operands.push_back("*");
	operands.push_back("/");
	operands.push_back("^");
}
bool ifValid(string input){
	int len=input.size();
	int equal=input.find("=");
	if(equal!=-1 && equal!=len-1){
		for(auto i:operands)
			if(input[0]==i)
	}
	else
		return false;
			

}
int main(){
	string input;
	cin >> input;
	bool valid=ifValid(input);
	
	return 0;
}
