// A C++ program to demonstrate
// working of Chinise remainder
// Theorem
#include <bits/stdc++.h>
using namespace std;

// Returns modulo inverse of a
// with respect to m using
// extended Euclid Algorithm.
int inv(int a, int b, int* x, int* y)
{
	
	// Base Case
	if (a == 0)
	{
		*x = 0, *y = 1;
		return b;
	}
	
	// To store results of recursive call
	int x1, y1;
	int gcd = inv(b % a, a, &x1, &y1);

	// Update x and y using results of recursive
	// call
	*x = y1 - (b / a) * x1;
	*y = x1;


    int res = (*x % b + b) % b;
	return res;
}

// k is size of num[] and rem[]. Returns the smallest
// number x such that:
// x % num[0] = rem[0],
// x % num[1] = rem[1],
// ..................
// x % num[k-2] = rem[k-1]
// Assumption: Numbers in num[] are pairwise coprime
// (gcd for every pair is 1)
int findMinX(int num[], int rem[], int k)
{
	// Compute product of all numbers
	int prod = 1;
	for (int i = 0; i < k; i++)
		prod *= num[i];

	// Initialize result
	int result = 0;

	// Apply above formula
	for (int i = 0; i < k; i++) {
		int pp = prod / num[i];
        int x,y;
		result += rem[i] * inv(pp, num[i],&x,&y) * pp;
	}

	return result % prod;
}

// Driver method
int main(void)
{
	int num[] = { 3, 4, 5 };
	int rem[] = { 2, 3, 1 };
	int k = sizeof(num) / sizeof(num[0]);
	cout << "x is " << findMinX(num, rem, k);
	return 0;
}
