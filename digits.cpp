#include<iostream>
#include<cstring>
using namespace std;

long int SumOfDigits(long int n){
	long int sum=0;
	while(n!=0){
		sum+=(n%10);
		n/=10;	
	}	
	return sum;
}

long int ProductOfDigits(long int n){
	long int product=1;
	while(n!=0){
		product*=(n%10);
		n/=10;	
	}	
	return product;
}


void digitsReversal(string str){
	int len=str.size();
	char swap;
	cout <<"\nGiven Number-"<< str<<endl;
	for(int i=0;i<=len/2;i++){
		swap=str[i];
		str[i]=str[len-1-i];
		str[len-1-i]=swap;
	}	
	cout <<"\nReversed Number-"<< str<<endl;	
}
void DigitsManipulation(){
	string str;
	long int n;
	int c;
	cout <<"\n1.Calculate Sum of digits of a given number"<<endl;
	cout <<"2.Calculate Product of digits of a given number"<<endl;
	cout <<"3.Reverse the digits of a number"<< endl;
	cout <<"\nEnter Choice-";
	cin >> c;
	if(c==1){
	   cout << "Enter a number-";
	   cin >> n;
	   cout << "Sum of Digits-" << SumOfDigits(n);
	}
	else if(c==2){
	   cout << "Enter a number-";
	   cin >> n;
	   cout << "Product of Digits-" << ProductOfDigits(n);   
	}
	else{
	    cout << "Enter a number-";
	    cin >> str;
	    digitsReversal(str);
	}    
}
