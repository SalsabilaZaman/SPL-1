#include<iostream>
using namespace std;

int gcd(int x,int y){
	int max=x,min=y;
	int remainder=-1;
	if(y>x){
		max=y;
		min=x;
	}
	while(remainder!=0){
		remainder=max%min;
		max=min;
		min=remainder;
	}	
	return max;
}

void LCMcalculate(){
		int n;
		int input;
		cout << "\nCalculate LCM(Least Common Multiple)!" <<endl;
		cout << "How many Numbers-";
		cin >> n;
		int arr[n];
		for(int i=0;i<n;i++){
		    again:
		    cout << "Enter Number-" << i+1 << ":";
		    cin >> input;
		    if(input==0){
		       cout <<"Invalid Input!"<<endl;
		       goto again;
		    }
		    else
		       arr[i]=input;   
		}      
		int lcm=arr[0];     
		for(int i=1;i<n;i++)
			lcm=(lcm*arr[i])/gcd(lcm,arr[i]);      
	     
		cout << "\nLCM of given "<< n <<" numbers is-"<< lcm << endl;
}

