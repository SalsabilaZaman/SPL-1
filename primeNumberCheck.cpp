#include<iostream>
using namespace std;
#define MAX 1000009
bool isPrime[MAX];

void checkPrime(){
	for(int i=2;i<MAX;i++)
	    isPrime[i]=true;
	    
	for(int i=2;i*i<MAX;i++)
	  if(isPrime[i]==true)
	    for(int j=i*i;j<MAX;j+=i)
	        isPrime[j]=false;
}
void primeGenerator(){
	checkPrime();
	int lowerbound,upperbound;
	cout << "Generate all prime numbers in a given range: "<<endl;
	cout << "Enter lower bound:";
	cin >> lowerbound;
	cout << "Enter upper bound:";
	cin >> upperbound;
	cout << "\nAll the prime numbers from "<< lowerbound << " to "<< upperbound <<"-"<<endl;
	for(int i=lowerbound; i<=upperbound;i++)
	   if(isPrime[i]==true)
	      cout << i << " ";
}
void PrimeChecker(){
	checkPrime();
	int choice;
	cout << "Check if a number is prime or not" <<endl;
	int num;
	cout << "Enter a number:";
	cin >> num;
	if(isPrime[num]==true)
		cout << num <<" is a Prime Number.";
	else
	   	cout << num <<" is not a Prime Number.";	
			
}
