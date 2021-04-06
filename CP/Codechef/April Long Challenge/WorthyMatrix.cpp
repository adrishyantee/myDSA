#include <bits/stdc++.h>
using namespace std;

#define ll long long int 
const int N=9999;

ll getAvg(ll r1, ll r2, ll c1, ll c2,
           ll dp[N + 1][N + 1])
{
    return (dp[r2][c2] - dp[r2][c1] - dp[r1][c2]
           + dp[r1][c1])/2;
}

bool AvgFound(ll K, ll S, ll grid[N+1])
{
    ll dp[N + 1][N + 1];
 
    for (ll i = 0; i < N; i++)
        for (ll j = 0; j < N; j++)
            dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j + 1]
                               - dp[i][j] + grid[i][j];
    for (ll i = 0; i < N; i++)
        for (ll j = 0; j < N; j++) {
            ll avg = getAvg(i, i + K, j, j + K, dp);
 
            if (avg >= S)
                return true;
        }
    return false;
}

int main(){
    int T;
    cin>>T;
    while(T--){
    ll n,m,K;
    ll count=0,sum=0;

    cin>>n>>m>>K;
    ll arr[n][m];
    
     for (ll i = 0; i < n; i++)
        for (ll j = 0; j < m; j++) 
            cin>>arr[i][j];

    for(ll i=1;i<N;i++)
       if(AvgFound(i,K,arr[])==true)
            count++;
    cout<<count<<endl;
}

return 0;
}