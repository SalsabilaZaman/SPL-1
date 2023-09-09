#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
#define matMAX 100
int matA[matMAX][matMAX];
int matB[matMAX][matMAX];
int matC[matMAX][matMAX];

void multiply(int n,int r,int m,int c){
	int sum=0;
	if(n%2!=0){
	 for(int i=0;i<r;i++)  
	   for(int j=0;j<c;j++){
	     sum=0;	   
	     for(int k=0;k<m;k++)
	     	   sum+=(matA[i][k]*matB[k][j]);	
	     matC[i][j]=sum;	
	}
       }	
	else{
	  for(int i=0;i<r;i++)  
	    for(int j=0;j<c;j++){	   
	      sum=0;
	      for(int k=0;k<m;k++)
	     	   sum+=(matC[i][k]*matB[k][j]);
	    	matA[i][j]=sum;
	    }	
	}

}
void matrixMultiply(){
	bool flag=true;
	srand(time(0));
	for(int i=0;i<matMAX;i++)
	   for(int j=0;j<matMAX;j++)
	      matC[i][j]=0;
	      
	int N,row1,row2,column1,column2;
	cout << "\nWelcome to Matrix Calculator"<<endl;
	cout << "How many matrix you want to multiply-";
	cin >> N;
	cout << "\nEnter Dimensions(Row X Column):" <<endl;
	cout << "Matrix-1:" <<endl;
		cin >> row1 >> column1;
	cout <<"Matrix-1:"<<endl;
	
	for(int i=0;i<row1;i++)
	     for(int j=0;j<column1;j++)
	         matA[i][j]=rand()%10;
	for(int i=0;i<row1;i++){
	     for(int j=0;j<column1;j++)
		 cout << matA[i][j]<<" "; 
	     cout<< endl;
	}     	        
	for(int i=1;i<N;i++){
		cout << "\nMatrix-"<< i+1<<":"<<endl;
		cin >> row2 >> column2;
		if(row2!=column1){
		   cout << "INVALID INPUT!\nTRY AGAIN\n";
		   flag=false;
		   break;
		}
		else{
		  column1=column2;
		  cout <<"Matrix-"<< i+1 <<":"<<endl;
		  for(int j=0;j<row2;j++)
	     		for(int k=0;k<column2;k++)
	        		 matB[j][k]=rand()%10;
	          for(int j=0;j<row2;j++){
	     		for(int k=0;k<column2;k++)
		 		cout << matB[j][k] <<" "; 
	     		cout<< endl;
		  }	 	  	
		  multiply(i,row1,row2,column2);
		}   
	}
	
	if(flag==true){
	  cout <<"\nResultant Matrix="<<endl;
	  for(int i=0;i<row1;i++){
		for(int j=0;j<column2;j++){
		  if(N%2!=0) 
		   cout << matA[i][j] << " ";
		  else
		   cout << matC[i][j] << " ";
		}   
		cout << endl;
	  }
	}  
		   
}

