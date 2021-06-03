#include <bits/stdc++.h>
using namespace std;

int main(){
    long long T;
    cin>>T;
    while(T>0){
        long long a,b,c,d,K;
        cin>>a>>b>>c>>d>>K;
        int d = (K%2-(abs(d-b)%2)+abs(c-a)%2)%2;
        if(d==0)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    T--;
    }
    return 0;
}