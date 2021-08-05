#include <iostream>
using namespace std;
int largestPower(int n, int p)
{
	int x = 0;
	while (n)
	{
		n /= p;
		x += n;
	}
	return x;
}
int main()
{
	int n = 10, p = 3;
	cout << "The largest power of "<< p <<
			" that divides " << n << "! is "<<
			largestPower(n, p) << endl;
	return 0;
}