#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T>0){
        int N,M;
        int count=0;
        cin>>N>>M;
        for(int i=1;i<N;i++){
            for(int j=i+1;j<=N;j++){
            if(((M%i)%j)==((M%j)%i))
            count++;
        }   
    }
    cout<<count<<endl;
    T--;
    }
    return 0;
}