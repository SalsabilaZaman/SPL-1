#include<iostream>
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

int main(){
	long int n;
	int c;
	cout <<"1.Calculate Sum of digits of a given number."<<endl;
	cout <<"2.Calculate Product of digits of a given number."<<endl;
	cout <<"Enter Choice-";
	cin >> c;
	cout << "Enter a number-";
	cin >> n;
	if(c==1)
	   cout << "Sum of Digits-" <<SumOfDigits(n);
	else
	   cout << ProductOfDigits(n);   
		 
	return 0;
}
