#include <bits/stdc++.h>
using namespace std;


string A[100][100],B[100][100],C[100][100];
int row,column;

int main(){
	cout <<"Enter row and column:";
	cin >> row>>column;
	
	cout<<endl<<"Enter your 1st Matrix:"<<endl;
	for(int i=0;i<row;i++)
		for(int j=0;j<column;j++)
			cin >>A[i][j];
	cout<<endl<<"Enter your 2nd Matrix:"<<endl;
	for(int i=0;i<row;i++)
		for(int j=0;j<column;j++)
			cin >>B[i][j];		
	for(int i=0;i<row;i++)
		for(int j=0;j<column;j++)
			C[i][j]=A[i][j]+B[i][j];
	cout <<endl<<"Answer="<<endl;
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++)		
			cout << C[i][j]<<" ";
		cout<<endl;
	}		
	return 0;
}
