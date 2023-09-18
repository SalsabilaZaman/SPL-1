#include<iostream>
using namespace std;

#define matMAX 100
int row,column;
double mat_A[matMAX][matMAX]={0};
double mat_B[matMAX][matMAX]={0};

int main(){
	srand(time(0));
	int i,j,power;
	cout <<"Enter matrix dimension(Row X Column):";
	cin >> row >> column;
	
	cout << "Enter your matrix-\n";
	for(int i=0;i<row;i++)
	   for(int j=0;j<column;j++){
	      mat_A[i][j]=(rand()%10)+1;
	      mat_B[j][i]=mat_A[i][j];
	    }  
	cout << "Matrix-A="<< endl;
	for(int i=0;i<row;i++){
	   for(int j=0;j<row;j++)
	     cout << mat_A[i][j]<<" ";
	   cout << endl;
	}
	cout << "Transpose of Matrix-A="<< endl;
	for(int i=0;i<row;i++){
	   for(int j=0;j<row;j++)
	     cout << mat_B[i][j]<<" ";
	   cout << endl;
	}
			    
}
