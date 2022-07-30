// C++ program to check for solutions of diophantine
// equations
#include <bits/stdc++.h>
using namespace std;

//utility function to find the GCD of two numbers
int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

// This function checks if integral solutions are
// possible
bool isPossible(int a, int b, int c)
{
	return (c%gcd(a,b) == 0);
}

//driver function
int main()
{
	int a = 3, b = 6, c = 9;
	isPossible(a, b, c)? cout << "Possible\n" :
						cout << "Not Possible\n";

	return 0;
}
