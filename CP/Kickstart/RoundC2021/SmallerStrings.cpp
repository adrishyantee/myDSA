#include <bits/stdc++.h>
using namespace std;

int power(long long x, unsigned int y, int p)
{    int res = 1;
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

int LexicoLesserStrings(string s,int K)
{
	int count = 0;
	int len;

	len = s.size();
	for (int i = 0; i < len; i++) {
        if((s[i]-'a')<=K)
		count += ((s[i] - 'a')* (power(26, len - i - 1,100000007)));
        else
        count += (K* (power(26, len - i - 1,100000007)));
	}

	return count;
}

int main(){
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
        int N, K;
        cin>>N>>K;

        string S,r;
        cin>>S;
        if(S.length()%2==0)
        r = S.substr(0,S.length()/2-1);
        cout<<"Case #"<<t<<": "<<LexicoLesserStrings(r, K)<<endl;
        }
    return 0;
}