#include<iostream>
using namespace std;
#define matMAX 100

int row,column;
double mat_A[matMAX][matMAX]={0};
double mat_B[matMAX][matMAX]={0};
double mat_C[matMAX][matMAX]={0};

int inputMatrix(){
	srand(time(0));
	int i,j,power;
	cout <<"Enter matrix dimension(Row X Column):";
	cin >> row >> column;
	
	cout << "Enter your matrix-\n";
	for(int i=0;i<row;i++)
	   for(int j=0;j<column;j++){
	      mat_A[i][j]=(rand()%10)+1;
	      mat_B[i][j]=mat_A[i][j];
	    }  
	cout << "Matrix-A="<< endl;
	for(int i=0;i<row;i++){
	   for(int j=0;j<row;j++)
	     cout << mat_A[i][j]<<" ";
	   cout << endl;
	}
	
	cout << "Raise to the power of-";
	cin >> power;
	
	return power;		    
}
void printMatrixPower(int p){
	if(p==1){
	  for(int i=0;i<row;i++){
	   for(int j=0;j<row;j++)
	     cout << mat_A[i][j]<<" ";
	   cout << endl;
	  }
	}
	else if(p%2==0){
	   for(int i=0;i<row;i++){
	     for(int j=0;j<row;j++)
	       cout << mat_C[i][j]<<" ";
	     cout << endl;
	  }
	}
	else{
	    for(int i=0;i<row;i++){
	      for(int j=0;j<row;j++)
	       cout << mat_B[i][j]<<" ";
	      cout << endl;
	     }
	}
}

void matrixPower(int p){
	
	for(int l=2;l<=p;l++){
	     if(l%2==0){	
		for(int i=0;i<row;i++)
	           for(int j=0;j<column;j++){
	              double sum=0;	   
	   		  for(int k=0;k<row;k++)
	     	             sum+=(mat_A[i][k]*mat_B[k][j]);	
	                 mat_C[i][j]=sum;
	            }
	     }
	     else{
	     	for(int i=0;i<row;i++)
	           for(int j=0;j<column;j++){
	              double sum=0;	   
	   		  for(int k=0;k<row;k++)
	     	             sum+=(mat_C[i][k]*mat_A[k][j]);	
	                 mat_B[i][j]=sum;
	            }
	     }            	
	}
	

	printMatrixPower(p);
}
int main(){
	int power=inputMatrix();
	matrixPower(power);	
	
}
