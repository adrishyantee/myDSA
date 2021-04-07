#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define k 60

bool checkbit(string s,int st,int e, int n){
    for(int i=0;i<n;i++){
    if(s[i]!='1')
    return false;
    }
    return true;
}

vector<string> DP[k][k];

int main(){
    ll T;
    cin>>T;
    while(T--){
        ll N,M,K;
        cin>>N>>M>>K;
        ll g[N];

        for(int i=0;i<N;i++)
        cin>>g[i];

        ll B[N];

        ll u[M],v[M],d[M];

        for(int i=0;i<M;i++){
            cin>>u[i]>>v[i]>>d[i];
        }


  string str = "";
    for (int len = 0; len <= N; len++) 
    {
        DP[len][0].push_back(str);
        str = str + "0";
    }

    for (int len = 1; len <= N; len++)
    {
        for (int n = 1; n <= len; n++)
        {
            for (string str : DP[len - 1][n])
                DP[len][n].push_back("0" + str);
            for (string str : DP[len - 1][n - 1])
                DP[len][n].push_back("1" + str);
        }
    }

    for (int n = 1,s=1; n <= N,s<=M; n++,s++) 
    {
        for (string str : DP[N][n])
        if(checkbit(str,u[s],v[s],n)==false){

        }
    }
return 0;
}