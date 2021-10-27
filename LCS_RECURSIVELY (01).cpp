// Import Libraries
#include<iostream>
#include<conio.h>

using namespace std;

// Recursively LCS Function 
int LCS(string x, string y, int m, int n)
{
	// If anyone is zero then, return 0.
	if(m==0 || n==0)
		return 0;
	// If both are equal then, add 1 in diagonal.
	else if(x[m-1] == y[n-1])
		return 1+LCS(x, y, m-1, n-1);
	// If both are not equal then, choose max from left or upper.
	else
		// Use built-in max function
		return max(LCS(x, y, m-1, n), LCS(x, y, m, n-1));
}

int main()
{
	string x,y;
	// Taking Input
	cout << "Enter 1st String: ";
	getline(cin, x);
	cout << "Enter 2nd String: ";
	getline(cin, y);
	
	// Print of length of strings
	int m = x.length();
	cout << endl << "Length of 1st String = " << m << endl;
	
	int n = y.length();
	cout << "Length of 2nd String = " << n << endl;
	
	// Print output
	cout << endl << endl << "LCS of " << x << " and " << y << " = " << LCS(x,y,m,n);
	
	return 0; 
}
