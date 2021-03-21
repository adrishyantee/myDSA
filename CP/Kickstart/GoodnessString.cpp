#include <bits/stdc++.h>
using namespace std;


int goodness(string S,int N){
    int g=0;
    for(int i=0;i<N/2;i++)
        {
           if(S[i]==S[N-i-1])
           continue;
           else
           g++;
        }
        return g;
}
int main(){
    int T; cin>>T;
    for(int t=1;t<=T;t++){
        int N,K,g;
        string S;
        cin>>N>>K;
        cin>>S;
        g=goodness(S,N);
        if(g==K){
            cout<<"Case #"<<t<<": "<<"0"<<endl;
            continue;
        }
        else if (g<K){
            int G,count=0;
            for (int i=0;i<N;i++){
                if(S[i]==S[N-i-1]){
                    S[i]=(char)(S[i]+1);
                    count++;
                }
                G=goodness(S,N);
                if(G==K)
                break;
            }
            cout<<"Case #"<<t<<": "<<count<<endl;
        }
        else{
            int G,count=0;
            for(int i=0;i<N;i++){
                if(S[i]!=S[N-i-1]){
                    S[i]=S[N-i-1];
                    count++;
                }
                G=goodness(S,N);
                if(G==K)
                break;
            }
            cout<<"Case #"<<t<<": "<<count<<endl;
        }
        
    }
    return 0;
}
