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

int main(){
	int num;
	cout << "Enter a number:";
	cin >> num;
	checkPrime();
	
	if(isPrime[num]==true)
	   cout << "Is a Prime Number.";
	else
	   cout << "Not a Prime Number.";

	return 0;
}
