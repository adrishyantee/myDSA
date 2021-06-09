#include <bits/stdc++.h>
#define K 1000000007
using namespace std;

long long int binpow(long long int a, long long int b) {
    long long int res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%K;
        a = (a * a)%K;
        b >>= 1;
    }
    return res;
}

int power(long long int x,unsigned int y, int p)
{
	int res = 1;	
	x = x % p; 	

	if(x==0)
	return 0;

	while (y > 0)
	{
		if (y & 1)
			res = (res*x) % p;

		y = y>>1;
		x = (x*x) % p;
	}
	return res;
}


int main(){
    int t;
    cin>>t;

    while(t--){

        long long int N,M;
        cin>>N>>M;

        long long int a = binpow(2,N)-1;
        long long int b= power(a,M,K) ;
        cout<<b<<endl;
    }
    return 0;
}