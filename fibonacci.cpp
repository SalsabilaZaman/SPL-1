#include<iostream>
using namespace std;

long int fibonacci(long int arr[],long int n){
	if (arr[n] !=-1)
	   return arr[n];
	else if(n==0)
	   arr[n]=0;
	else if(n==1)
	   arr[n]=1;
	else
	   arr[n]=fibonacci(arr,n-1)+fibonacci(arr,n-2);     
	return arr[n];
}
int main(){
	long int n;
	cout << "Enter length of your fibonacci sequence-";
	cin >> n;
	long int arr[n];
	for(int i=0;i<n;i++)
	   arr[i]=-1;
	
	fibonacci(arr,n-1);
	for(long int i=0;i<n;i++)
	  cout << arr[i] << " ";
	
	return 0;  
}
