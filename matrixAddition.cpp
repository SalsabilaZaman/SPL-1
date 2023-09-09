#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
#define matMAX 100

int mat_A[matMAX][matMAX]={0};

void matrixAddition(){
	srand(time(0));
	int i,j,k;
	int num,row,column;
	cout <<"\nWelcome to Matrix Calculator!"<<endl;
	cout << "Enter how many matrix you want to add-";
	cin >> num;
	cout <<"Enter row number:";
	cin >> row;
	cout <<"Enter column number:";
	cin >> column;
	int input;
	
	for(i=0;i<num;i++){
		cout << "\nEnter Matrix-" << i+1<<" :"<<endl;
		for(j=0;j<row;j++){
		  for(k=0;k<column;k++){
		    //cin >> input;
		    input=rand()%10;
		    cout << input <<" ";
		    mat_A[j][k]+=input;
		  }
		  cout << endl;
	 	}        
		   
	}
	cout << "\nResultant Matrix=" << endl;
	for(j=0;j<row;j++){
	  for(k=0;k<column;k++)
		cout << mat_A[j][k] <<" ";
	  cout <<endl;
	}  			 
}

