#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
#define matMAX 100

int mat_A[matMAX][matMAX]={0};

int inputMatrix(){
	srand(time(0));
	int i,j,k;
	int row,column;
	again:
	cout <<"Enter matrix dimension(Row X Column):";
	cin >> row >> column;
	if(row!=column){
		cout << "Wrong input!It has to be square matrix!\nTry again!!"<<endl;
		goto again;
	}
	cout << "Enter your matrix-\n";
	for(int i=0;i<row;i++)
	   for(int j=0;j<row;j++)
	      mat_A[i][j]=(rand()%4)+1;
	
	cout << "Matrix-A="<< endl;
	for(int i=0;i<row;i++){
	   for(int j=0;j<row;j++)
	     cout << mat_A[i][j]<<" ";
	   cout << endl;
	}	      
	return row;
}	

long int calculate_Determinant(int n){
	double mat_L[n][n],mat_U[n][n];	//LU decomposition
	for(int i=0;i<n;i++)
	   for(int j=0;j<n;j++){
	   	mat_L[i][j]=0;
	   	mat_U[i][j]=mat_A[i][j];
	   }
	for(int i=0;i<n;i++)
	   mat_L[i][i]=1;
	for(int i=0;i<n;i++){
		int pivot=mat_U[i][i];
		for(int j=i+1;j<n;j++){
			if(mat_U[j][i]!=0){
				double div=mat_U[j][i]/pivot;
				mat_L[j][i]=div;
				for(int k=j;k<n;k++)
				
			}
		}
		
	}
	   

}

void main(){
	int num=inputMatrix();
	calculate_Determinant(num);
}
