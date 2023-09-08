#include<iostream>
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
	for(int i=0;i<matMAX;i++)
	   for(int j=0;j<matMAX;j++)
	      matC[i][j]=0;
	      
	int N,row1,row2,column1,column2;
	cout << "How many matrix you want to multiply-";
	cin >> N;
	cout << "Enter Dimensions(Row X Column):" <<endl;
	cout << "Matrix-1:" <<endl;
		cin >> row1 >> column1;
	cout <<"Enter Matrix-1:"<<endl;
	
	for(int i=0;i<row1;i++)
	     for(int j=0;j<column1;j++)
	        cin >> matA[i][j];
	        
	for(int i=1;i<N;i++){
		cout << "Matrix-"<< i+1<<":"<<endl;
		cin >> row2 >> column2;
		if(row2!=column1){
		   cout << "INVALID INPUT!\n\nTRY AGAIN\n";
		   break;
		}
		else{
		  column1=column2;
		  cout <<"Enter Matrix-"<< i+1 <<":"<<endl;
		  for(int j=0;j<row2;j++)
	     		for(int k=0;k<column2;k++)
	        		cin >> matB[j][k];	  	
		  multiply(i,row1,row2,column2);
		}   
	}
	
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

