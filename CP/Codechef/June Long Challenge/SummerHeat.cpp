#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int a,b,X,Y;
        cin>>a>>b>>X>>Y;
        int ans=X/a+Y/b;
        cout<<ans<<endl;
    }

    return 0;
}