#include <bits/stdc++.h>
using namespace std;

int power(long long x, unsigned int y, int p)
{
    int res = 1;  
    x = x % p;
  
    if (x == 0) return 0; 
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
    int T;
    cin>>T;
    while (T--)
    {
        int N;
        cin>>N;
        int ans = power(2,N-1,1000000007);
        cout<<ans<<endl;
    }
    return 0; 
}