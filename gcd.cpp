#include<iostream>
using namespace std;

void GCDcalculate(){
		int n;
		cout << "\nCalculate GCD(Greatest Common Divisor)!" <<endl;
		cout << "How many Number-";
		cin >> n;
		int arr[n];
		for(int i=0;i<n;i++){
		    cout << "Enter Number-" << i+1 << ":";
		    cin >> arr[i];
		}
		int swap;         
		int big=arr[0];     
		 for(int i=1;i<n;i++){
			int remainder=-1;
			int small=arr[i];
		      if(big<small){
		      	swap=big;
			big=small;		      
		        small=swap;
		      }
		     while(remainder!=0){
			 remainder=big%small;
			 big=small;
			 small=remainder;
		     } 
		     if (big==1)
		        break;        
		 }      
		cout << "\nGCD of given "<< n <<" numbers is-"<< big << endl;
}

