#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T>0){
        long int N,M;
        long int count=0;
        cin>>N>>M;

        vector<long int> mod(N+1,1);
        for(long int a=2;a<=N;a++){
            long int x=M%a;
            count+=mod[x];
            for(long int b=x;b<=N;b+=a){
                mod[b]++;
            }
        }  
    cout<<count<<endl;
    T--;
    }
    return 0;
}