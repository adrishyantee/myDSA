// C++ program to find (a^b) mod m for a large 'a'
#include<bits/stdc++.h>
using namespace std;

// Iterative Function to calculate (x^y)%p in O(log y)
unsigned int power(unsigned int x, unsigned int y,
								unsigned int p)
{
	unsigned int res = 1;	 // Initialize result

	x = x % p; // Update x if it is more than or
				// equal to p

	while (y > 0)
	{
		// If y is odd, multiply x with result
		if (y & 1)
			res = (res*x) % p;

		// y must be even now
		y = y>>1; // y = y/2
		x = (x*x) % p;
	}

    //iterative process, fermat little's theorem
    //O(logn)
	return res;
}

unsigned int Calculate(unsigned int A, unsigned int B,
					unsigned int C, unsigned int M)
{
	unsigned int res, ans;

	// Calculate B ^ C (mod M - 1)
	res = power(B, C, M-1);

	// Calculate A ^ res ( mod M )
	ans = power(A, res, M);

	return ans;
}

// Driver program to run the case
int main()
{ // M must be be a Prime Number
	unsigned int A = 3, B = 9, C = 4, M = 19;

	cout << Calculate(A, B, C, M);

	return 0;
}
