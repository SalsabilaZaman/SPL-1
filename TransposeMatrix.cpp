#include<iostream>
using namespace std;

#define matMAX 100

double MATRIX_A[matMAX][matMAX]={0};
double MATRIX_B[matMAX][matMAX]={0};

void  matrixTranspose(){
	int row,column;
	srand(time(0));
	int i,j,power;
	cout <<"Enter matrix dimension(Row X Column):";
	cin >> row >> column;
	
	cout << "Enter your matrix-\n";
	for(int i=0;i<row;i++)
	   for(int j=0;j<column;j++){
	      MATRIX_A[i][j]=(rand()%10)+1;
	      MATRIX_B[j][i]=MATRIX_A[i][j];
	    }  
	cout << "Matrix-A="<< endl;
	for(int i=0;i<row;i++){
	   for(int j=0;j<row;j++)
	     cout << MATRIX_A[i][j]<<" ";
	   cout << endl;
	}
	cout << "Transpose of Matrix-A="<< endl;
	for(int i=0;i<row;i++){
	   for(int j=0;j<row;j++)
	     cout << MATRIX_B[i][j]<<" ";
	   cout << endl;
	}
			    
}
