#include<iostream>
using namespace std;
#define matMAX 100

int row,column;
double MAT_A[matMAX][matMAX]={0};
double MAT_B[matMAX][matMAX]={0};
double MAT_C[matMAX][matMAX]={0};

int InputMatrix(){
	srand(time(0));
	int i,j,power;
	cout <<"Enter matrix dimension(Row X Column):";
	cin >> row >> column;
	
	cout << "Enter your matrix-\n";
	for(int i=0;i<row;i++)
	   for(int j=0;j<column;j++){
	      MAT_A[i][j]=(rand()%10)+1;
	      MAT_B[i][j]=MAT_A[i][j];
	    }  
	cout << "Matrix-A="<< endl;
	for(int i=0;i<row;i++){
	   for(int j=0;j<row;j++)
	     cout << MAT_A[i][j]<<" ";
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
	     cout << MAT_A[i][j]<<" ";
	   cout << endl;
	  }
	}
	else if(p%2==0){
	   for(int i=0;i<row;i++){
	     for(int j=0;j<row;j++)
	       cout << MAT_C[i][j]<<" ";
	     cout << endl;
	  }
	}
	else{
	    for(int i=0;i<row;i++){
	      for(int j=0;j<row;j++)
	       cout << MAT_B[i][j]<<" ";
	      cout << endl;
	     }
	}
}

void matrixPower(){
	int p=InputMatrix();
	for(int l=2;l<=p;l++){
	     if(l%2==0){	
		for(int i=0;i<row;i++)
	           for(int j=0;j<column;j++){
	              double sum=0;	   
	   		  for(int k=0;k<row;k++)
	     	             sum+=(MAT_A[i][k]*MAT_B[k][j]);	
	                 MAT_C[i][j]=sum;
	            }
	     }
	     else{
	     	for(int i=0;i<row;i++)
	           for(int j=0;j<column;j++){
	              double sum=0;	   
	   		  for(int k=0;k<row;k++)
	     	             sum+=(MAT_C[i][k]*MAT_A[k][j]);	
	                 MAT_B[i][j]=sum;
	            }
	     }            	
	}
	

	printMatrixPower(p);
}
/*int main(){
	
	matrixPower(power);	
	
}*/
