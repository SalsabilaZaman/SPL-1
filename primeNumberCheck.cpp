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
void primeGenerator(int lowerbound, int upperbound){
	cout << "All the prime numbers from "<< lowerbound << " to "<< upperbound <<"-"<<endl;
	for(int i=lowerbound; i<=upperbound;i++)
	   if(isPrime[i]==true)
	      cout << i << " ";
}
int main(){
	checkPrime();
	int choice;
	cout << "1.Check if a number is prime or not" <<endl;
	cout << "2.Generate all prime numbers in a given range "<<endl;
	cin >> choice;
	switch(choice){
		case 1:int num;
		       cout << "Enter a number:";
		       cin >> num;
		       if(isPrime[num]==true)
	   			cout << "Is a Prime Number.";
		       else
	   			cout << "Not a Prime Number.";	
			break;
		case 2:int lowerbound,upperbound;
		       cout << "Enter lower bound:";
		       cin >> lowerbound;
		       cout << "Enter upper bound:";
		       cin >> upperbound;
		       primeGenerator(lowerbound,upperbound);
	
	} 
	

	return 0;
}
