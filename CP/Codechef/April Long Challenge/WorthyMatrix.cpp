#include <bits/stdc++.h>
using namespace std;
#define ll long long int


ll min(ll a ,ll b){
    return (a<b)?a:b;
}

int main(){
    int T;
    cin>>T;

    while(T-- !=0){
    ll n,m,k;
    

    cin>>n>>m>>k;
    double arr[n+1][m+1];
    
    for (ll i = 0; i <= n; i++){
        for (ll j = 0; j <= m; j++) {
            if(i==0 || j==0){
                arr[i][j=0];
            }
            else
            cin>>arr[i][j];
            }
        }
    for(ll i=0;i<=n;i++){
        double pre = 0;
        for(ll j=0; j<=m;j++){
            arr[i][j]+=pre;
            pre = arr[i][j];
        }
    }
    for(ll j=0;j<=m;j++){
        double pre =0;
        for(ll i=0; i<=n;i++){
            arr[i][j]+=pre;
            pre=arr[i][j];
        }
    }
    ll mini = min(m,n);
    ll ans=0;
    for(ll len=1;len<=mini;len++){
        for(ll i=len;i<=n;i++){
            for(ll j=len;j<=m;j++){
                if((arr[i][j]+arr[i-len][j-len]-arr[i][j-len]-arr[i-len][j])/(len*len) >=k)
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    }
return 0;
}