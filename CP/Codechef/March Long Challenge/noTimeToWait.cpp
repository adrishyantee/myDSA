#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,H,x,T,c=0;
    cin>>N>>H>>x;
    for (int i=0;i<N;i++){
        cin>>T;
        if(x+T>=H){
        c++;
        break;
        }
    }
    if (c==0)
    cout<<"NO";
    else
    cout<<"YES";

    return 0;
}