#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
#define matMAX 100

double mat_A[matMAX][matMAX]={0};
double mat_L[matMAX][matMAX],mat_U[matMAX][matMAX];
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
	      mat_A[i][j]=(rand()%10)+1;
	
	cout << "Matrix-A="<< endl;
	for(int i=0;i<row;i++){
	   for(int j=0;j<row;j++)
	     cout << mat_A[i][j]<<" ";
	   cout << endl;
	}	      
	return row;
}	

long int calculate_Determinant(int n){
		//LU decomposition
	for(int i=0;i<n;i++)
	   for(int j=0;j<n;j++){
	   	mat_L[i][j]=0;
	   	mat_U[i][j]=mat_A[i][j];
	   }
	for(int i=0;i<n;i++)
	   mat_L[i][i]=1;
	for(int i=0;i<n;i++){		//making lower triangle 0
		double pivot=mat_U[i][i];
		if(pivot ==0){
		    for(int j=i+1;j<n;j++)
			   if(mat_U[j][i]!=0){
			   	double swap=mat_U[j][i];
			   	mat_U[j][i]=mat_U[i][i];
			   	mat_U[i][i]=swap;
			   }	
		
		}
		pivot=mat_U[i][i];
		  for(int j=i+1;j<n;j++){
			if(mat_U[j][i]!=0){
				double div=mat_U[j][i]/pivot;
				//mat_U[j][i]=0;
				for(int k=0;k<n;k++){
				   mat_U[j][k]+=(-div)*mat_U[i][k];
				   mat_L[j][k]+=(-div)*mat_L[i][k];
				}	   
			}
		  }
	         
	}
	double determin=1;
	for(int i=0;i<n;i++)
	   determin*=mat_U[i][i];
	 
	
	return determin;
}

void inverseCalculate(int n){

	for(int i=0;i<n;i++){		//making all diagonal elements to 1
		double pivot=mat_U[i][i];
		if(pivot!=1)
		   for(int j=0;j<n;j++){
		   	mat_U[i][j]/=pivot;
		   	mat_L[i][j]/=pivot;
		   }	
	}
	for(int i=n-1;i>=0;i--){		//making lower triangle 0
		double pivot=mat_U[i][i];
		if(pivot ==0){
		    for(int j=i-1;j>=0;j--)
			   if(mat_U[j][i]!=0){
			   	double swap=mat_U[j][i];
			   	mat_U[j][i]=mat_U[i][i];
			   	mat_U[i][i]=swap;
			   }	
		
		}
		pivot=mat_U[i][i];
		  for(int j=i-1;j>=0;j--){
			if(mat_U[j][i]!=0){
				double div=mat_U[j][i]/pivot;
				//mat_U[j][i]=0;
				for(int k=0;k<n;k++){
				   mat_U[j][k]+=(-div)*mat_U[i][k];
				   mat_L[j][k]+=(-div)*mat_L[i][k];
				}	   
			}
		  }
	         
	}
	
	for(int i=0;i<n;i++){
	   for(int j=0;j<n;j++)
	     printf("%7.4lf ",mat_L[i][j]);
	   cout << endl;
	}

}

int main(){
	int num=inputMatrix();
	double ans=calculate_Determinant(num);
	cout<<endl<<"Determinant of the given matrix="<< ans<<endl<<endl;
	cout <<"Inverse Matrix="<<endl;
	inverseCalculate(num);
	return 0;
}
