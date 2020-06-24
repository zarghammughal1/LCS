#include<iostream>
#include<conio.h>

using namespace std;

// LCS Function
int LCS(string x, string y, int m, int n)
{
	// Make 2-d Array
	int L[m+1][n+1];
	int i, j;
	for(i=0 ; i<=m ; ++i)
	{
		for(j=0 ; j<=n ; ++j)
		{
			// If anyone is zero then, retrun 0.
			if(i==0 || j==0)
				L[i][j] = 0;
			// if both are equal then, add 1 in diagonal.
			else if(x[i-1] == y[j-1])
				L[i][j] = L[i-1][j-1] + 1;
			// if both are not equal, then choose max from left or upper.
			else
				// use built-in max function.
				L[i][j] = max(L[i-1][j], L[i][j-1]);
		}
	}
	return L[m][n];
}

int main()
{
	string x,y;
	cout << "Enter 1st String: ";
	getline(cin, x);
	cout << "Enter 2nd String: ";
	getline(cin, y);
	
	int m = x.length();
	cout << endl << "Length of 1st String = " << m << endl;
	
	int n = y.length();
	cout << "Length of 2nd String = " << n << endl;
	
	cout << endl << endl << "LCS of " << x << " and " << y << " = " << LCS(x,y,m,n);
	
	return 0;
}
