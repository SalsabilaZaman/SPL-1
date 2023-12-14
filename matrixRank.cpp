#include<iostream>
#include<cstdlib>
using namespace std;
#define matMAX 100
int n;
int row,column;
double matrix_A[matMAX][matMAX]={0};

void inputMatrix(){
	srand(time(0));
	int i,j,k;
	
	cout <<"Enter matrix dimension(Row X Column):";
	cin >> row >> column;
	cout << "Enter your matrix-\n";
	for(int i=0;i<row;i++)
	   for(int j=0;j<column;j++)
	      matrix_A[i][j]=(rand()%10)+1;
	
	cout << "Matrix-A="<< endl;
	for(int i=0;i<row;i++){
	   for(int j=0;j<column;j++)
	     cout << matrix_A[i][j]<<" ";
	   cout << endl;
	}	      
}
void findEchelon(){
	for(int i=0;i<row;i++){
		double pivot=matrix_A[i][i];
		for(int j=i+1;j<row;j++)
		    if(matrix_A[j][i]!=0){
			double div=matrix_A[j][i]/pivot;
			for(int k=0;k<column;k++)
			   matrix_A[j][k]+=(-div)*matrix_A[i][k];
		    }
		
	}
}
void Calculaterank(){
	int rank=row;
	for(int i=0;i<row;i++){
		bool allZero=true;
		for(int j=0;j<column;j++)
		   if(matrix_A[i][j]!=0)
		   	allZero=false;
		if(allZero)
			rank--;   	
	}
	cout <<"Rank="<<rank<<endl;
}	
int main(){
	inputMatrix();
	findEchelon();
	Calculaterank();
}
