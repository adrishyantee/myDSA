#include <bits/stdc++.h>
using namespace std;
//Not solved
//BRUTE FORCE SOLUTION

int main(){
    int T;
    cin>>T;
    while(T--){
        int N,E,H,A,B,C,cnt=0,mn=INT_MAX;
        cin>>N>>E>>H>>A>>B>>C;
        for (int k=0;k<min(E,H);k++){
            for(int i=k+1;i<E;i++){
                for (int j=k+1;j<H;j++){
                    cnt+=k+i/2+j/3;
                    if(cnt>=N){
                    int s=C*k+A*i/2+B*j/3;
                    mn=min(s,mn);
                }
                }
            }
        }
        if (mn==0)
        cout<<-1<<endl;
        else
        cout<<mn<<endl;
    }
    return 0;
}