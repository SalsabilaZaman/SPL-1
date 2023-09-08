#include<iostream>
using namespace std;
#define MAX 1000009
int smallestPrimeFactor[MAX];

void smallestPrimeFinder(){
	int i,j;
	for(i=1;i<MAX;i++)
	   smallestPrimeFactor[i]=i;
	for(i=4;i<MAX;i+=2)
	   smallestPrimeFactor[i]=2;
	for(i=3;i*i<MAX;i++)
	   if(smallestPrimeFactor[i]==i)
	      for(j=i*i;j<MAX;j+=i)
	          smallestPrimeFactor[j]=i;  	  

}

void primeFactorization(int num){
	smallestPrimeFinder();
	int i;
	cout <<"\nPrime Factorization of "<< num <<"-" << endl;
	for(i=num;i>1;){
		cout << smallestPrimeFactor[i];
		i=i/smallestPrimeFactor[i];
		if(i!=1)
		  cout <<" X ";
	}
}
void Factorization(){
	int num;
	cout << "Enter a number: ";
	cin >> num;
	
	primeFactorization(num);
	
}
