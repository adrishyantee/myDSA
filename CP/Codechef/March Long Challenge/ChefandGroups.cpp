#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;

    for(int i=0;i<T;i++){
        int c=0,p=0; 
        long int count=0;
        string S;
        long int N;
        cin>>S;
        N=S.length();

        for(long int j=0;j<N;j++){
        if(S[j]=='0')
        count++;
        }
        if(count==N)
        cout<<0<<endl;
        else        
            if(S[0]=='0'){
                for (long int i=0;i<N;i++){
                    if(S[i]=='0'&& S[i+1]=='1')
                    c++;
                    else
                    continue;
            }
            cout<<c<<endl;
            }
            if(S[0]=='1'){
                for (long int i=1;i<N;i++){
                    if(S[i]=='0' && S[i+1]=='1')
                    p++;
                    else
                    continue;
            }
            cout<<p+1<<endl;;
    }
    }
    return 0;
}