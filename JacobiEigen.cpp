#include<iostream>
#include<climits>
#include<cstdlib>
#include<cmath>
using namespace std;
#define EPS 10e-7
#define MAX 50
int n;
double A[MAX][MAX];
double V[MAX];

void readInput(){
	freopen("JacobiInput.txt","r",stdin);
	cin >> n;
	for(int i=0;i<n;i++)
   	   for(int j=0;j<n;j++)
   	   	cin >> A[i][j];
}

double getMax(double x,double y){
	if(fabs(x)>fabs(y))
		return x
	return max;
}
