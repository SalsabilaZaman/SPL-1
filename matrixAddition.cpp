#include<iostream>
using namespace std;
#define MAX 100

int matA[MAX][MAX]={0};

void matrixAddition(){
	int i,j,k;
	int num,row,column;
	cout << "Enter how many matrix you want to add-";
	cin >> num;
	cout <<"Enter row number:";
	cin >> row;
	cout <<"Enter column number:";
	cin >> column;
	int input;
	
	for(i=0;i<num;i++){
		cout << "Enter Matrix-" << i+1<<" :"<<endl;
		for(j=0;j<row;j++)
		  for(k=0;k<column;k++){
		    cin >> input;
		    matA[j][k]+=input;
		  }      
		   
	}
	cout << "Resultant Matrix-" << endl;
	for(j=0;j<row;j++){
	  for(k=0;k<column;k++)
		cout << matA[j][k] <<" ";
	  cout <<endl;
	}  			 
}

int main(){
	matrixAddition();
	return 0;
}
