#include<iostream>
#include<cstring>
using namespace std;

void palindromeCheck(){
	string str;
	cout <<"\nWelcome to Palindrome Checker"<< endl;
	
	cout <<"Enter number:";
	cin >> str;
	int len=str.size();
	bool result=true;
	for(int i=0;i<=len/2;i++)
		if(str[i]!=str[len-1-i]){
			result=false;
			break;
		}
		      
	if(result==true)
	  cout <<"\nPalindrome!\n";
	else
	  cout <<"\nNot Palindrome!\n";  	

}

