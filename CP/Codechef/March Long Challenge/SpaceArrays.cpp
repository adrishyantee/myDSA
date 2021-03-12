#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        long int N;
        cin>>N;
        long int arr[N];
        for(long int i=0;i<N;i++){
            cin>>arr[i];
        }

        sort(arr,arr+N);

    long int ans=0,temp=0;
    for (long int i=0;i<N;i++){
        if(i+1<arr[i]){
        temp = 1;
        break;
        }
    //very good solution of the problem at one step, to store number of moves done
    ans=ans+(i+1-arr[i]);
    }
    if(temp==1){
        cout<<"Second"<<endl;
        }
    else{
        if(ans%2==1)
        {
            cout<<"First"<<endl;
        }
        else{
            cout<<"Second"<<endl;
        }
    }
    }
    return 0;
}