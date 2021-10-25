#include<iostream>
#include<conio.h>
#include<cstring>

using namespace std;

// LCS Function
// LCS is the algoithum use to find similar string patterns the application major coomon of LCS is plagrisum chacker
string LCS(string x, string y, int m, int n)
{
	// Make 2-d Array
	int L[m+1][n+1];
	for(int i=0 ; i<=m ; ++i)
	{
		for(int j=0 ; j<=n ; ++j)
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
	int k = L[m][n];
	char array[k+1];
	while(m>0 && n>0)
	{
		// If both are same
		if(x[m-1]==y[n-1])
		{
			// Put in result
			array[k-1] = x[m-1];
			// Decrement all variables
			--m;
			--n;
			--k;
		}
		else if(L[m][n-1] < L[m-1][n])
			--n;
		else
			--m;
	}
	return array;
}

int main()
{
	string x = "BDCABA";
	string y = "ABCBDAB";
	
	cout << "1st String = " << x << endl;
	cout << "2nd String = " << y << endl << endl;
	
	int m = x.length();
	cout << "Length of 1st string = " << m;
	
	int n = y.length();
	cout << endl << "Length of 2nd string = " << n << endl;
	
/*	string x,y;
	cout << "Enter 1st String: ";
	getline(cin, x);
	cout << "Enter 2nd String: ";
	getline(cin, y);
	
	int m = x.length();
	cout << endl << "Length of 1st String = " << m << endl;
	
	int n = y.length();
	cout << "Length of 2nd String = " << n << endl;
*/
	cout << endl << endl << "LCS String = " << LCS(x,y,m,n);
	
	return 0;
}
