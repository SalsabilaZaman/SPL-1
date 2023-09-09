#include<iostream>
using namespace std;

double fibonacci(double arr[],long int n){
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
void fibonacciGenerator(){
	long int n;
	cout << "\nEnter length of your fibonacci sequence-";
	cin >> n;
	double arr[n+1];
	for(int i=0;i<=n;i++)
	   arr[i]=-1;
	
	fibonacci(arr,n);
	for(long int i=0;i<=n;i++)
	  printf("%.0lf  ",arr[i]);
}
