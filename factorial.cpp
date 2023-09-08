#include<iostream>
using namespace std;

long int factorial(long int arr[],int n){
	if(arr[n]!=-1)
	    return arr[n];
	else if(n==0)
	    arr[n]=1;     
	else
	   arr[n]=(n+1)*factorial(arr,n-1);
	return arr[n];   
}

void factorialGenerator(){
	int n;
	cout << "Enter the number you want to factorial!-";
	cin >> n;
	long int arr[n];
	for(int i=0;i<n;i++)
	   arr[i]=-1;
	
	factorial(arr,n-1);   
	
	for(int i=0;i<n;i++)
	   cout << arr[i] << " ";
}
