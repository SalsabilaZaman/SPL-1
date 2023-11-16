#include<iostream>
#include<cstdlib>
using namespace std;
#include "digits.cpp"
#include "factorial.cpp"
#include "fibonacci.cpp"
#include "gcd.cpp"
#include "lcm.cpp"
#include "matrixAddition.cpp"
#include "palindromecheck.cpp"
#include "primeFactorization.cpp"
#include "primeNumberCheck.cpp"
#include "matrixMultiply.cpp"
#include "inversionDeterminant.cpp"
#include "matrixPower.cpp"
#include "TransposeMatrix.cpp"
#include  "jacobiEigen.cpp"
#include "expressiontree.cpp"





int main(){
	int a=1;
	while(a!=0){
	system("clear");
	
	int choice;
	cout << "\x1B[36m\n	     Menu  \n";
	cout <<"    ---------------------------\n";
	cout << "\x1B[32m	1.Prime Checker\n";
	cout << "	2.Prime Generator\n";
	cout << "	3.Prime Factorization\n";
	cout << "	4.Digit Manipulation\n";
	cout << "	5.Palindrome Checker\n";
	cout << "        6.GCD Calculator\n";
	cout << "        7.LCM Calculator\n";
	cout << "	8.Fibonacci Sequence Generator\x1B[0m\n";
	
	
	cout << "\n\n\x1B[36m	  Specialization\n";
	cout <<"    ---------------------------\n";
	cout << "\x1B[35m	9.Matrix Addition\n";
	cout << "	10.Matrix Multiplication\n";
	cout << "	11.Matrix Determinant\n";
	cout << "	12.Matrix Inversion\n";
	cout << "	13.Matrix Power Calculation\n";
	cout << "	14.Matrix Transposition\n";
	cout << "	15.Calculate eigenvalue and eigenvectors\n"; 
	cout <<	"	16.Expression Evaluation\x1B[0m\n";
	again:
	cout <<"\nEnter your choice-";
	cin >> choice;
	switch(choice){
		case 1:
			PrimeChecker();
			break;
		case 2:
			primeGenerator();
			break;
		case 3:
			Factorization();
			break;
		case 4:
			DigitsManipulation();
			break;
		case 5:
			palindromeCheck();
			break;
		case 6:
			GCDcalculate();
			break;
		case 7:
			LCMcalculate();
			break;
		case 8:
			fibonacciGenerator();
			break;
		case 9:
			matrixAddition();
			break;
		case 10:
		       matrixMultiply();
		       break;
		case 11:{
			long int deter=calculate_Determinant();
			cout<<endl<<"Determinant of the given matrix="<< deter<<endl;
			break;
		}
		case 12:
			matrixInversion();
			break;
		case 13:
			matrixPower();
			break;
		case 14:
			matrixTranspose();
			break;			       
		case 15:
			eigenValue();
			break;
		case 16:
			expressionEvaluate();
			break;	       
		default:
		       cout << "\x1B[31mWrong Input! Try Again!\x1B[0m";
		       goto again;
	}
	 cout << "\n\nContinue(1) or Exit(0):";
	 cin >> a;
	}
		
}
