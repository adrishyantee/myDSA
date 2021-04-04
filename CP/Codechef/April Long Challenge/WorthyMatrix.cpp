#include <bits/stdc++.h>
using namespace std;


int main(){
    int T;
    cin>>T;
    while(T--){
    int N,M;
    long int K,count=0,max=0;
    cin>>N>>M>>K;
    long int arr[N][M];
    long int narr[N][M];
    for (int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>arr[i][j];
            narr[i][j]=arr[i][j];
        }
    }
    
    for(int i=0;i<N;i++){
        int j=1;
        while(j<M){
            narr[i][j]=arr[i][j-1]+arr[i][j];
            j++;
        }
    }
    
    for (int i=0;i<N;i++){
    for(int j=0;j<M;j++){
            arr[i][j]=narr[i][j];
        }
    }
    
    for(int j=0;j<M;j++){
        int i=1;
        while(i<N){
            narr[i][j]=arr[i-1][j]+arr[i][j];
            i++;
        }
    }
    int m=0,n=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(narr[i][j]>=K){
                n=i;
                m=j;
                break;
            }
        }
    }
    cout<<(N-n)*M+(M-m)*n;
    cout<<count<<endl;
}
    return 0;

}