#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        long long D,d,P,Q;
        cin>>D>>d>>P>>Q;
        long long ans=0;
        long long n=(long long)D/d;
        long long i=0;
        ans=d*(n*P+(n*(n-1)*Q)/2);
        if(D%d!=0)
        ans+=(P+n*Q)*(long long)(D%d);
        cout<<ans<<endl;
    }

    return 0;

}