// Dynamic Programming C++ implementation to find
// minimum number of deletions and insertions
#include <bits/stdc++.h>

using namespace std;

// Returns length of length common subsequence
// for str1[0..m-1], str2[0..n-1]
int lcs(string str1, string str2, int m, int n)
{
	int L[m + 1][n + 1];
	int i, j;

	// Following steps build L[m+1][n+1] in bottom
	// up fashion. Note that L[i][j] contains
	// length of LCS of str1[0..i-1] and str2[0..j-1]
	for (i = 0; i <= m; i++) {
		for (j = 0; j <= n; j++) {
			if (i == 0 || j == 0)
				L[i][j] = 0;

			else if (str1.at(i - 1) == str2.at(j - 1))
				L[i][j] = L[i - 1][j - 1] + 1;

			else
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}

	// L[m][n] contains length of LCS
	// for X[0..n-1] and Y[0..m-1]
	return L[m][n];
}

// function to find minimum number
// of deletions and insertions
void printMinDelAndInsert(string str1, string str2)
{
	int m = str1.size();
	int n = str2.size();

	int len = lcs(str1, str2, m, n);

	cout << "Minimum number of deletions = " << (m - len)
		<< endl;

	cout << "Minimum number of insertions = " << (n - len)
		<< endl;
}

// Driver Code
int main()
{
	string str1 = "heap";
	string str2 = "pea";

	// Function Call
	printMinDelAndInsert(str1, str2);
	return 0;
}
