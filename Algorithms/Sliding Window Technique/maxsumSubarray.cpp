#include <bits/stdc++.h>
using namespace std;


void maxSubSum(int arr[],int n,int k,int x){
    int sum=0,ans=0;

    for(int i=0;i<k;i++){
        sum+=arr[i];
    }

    if(sum<x){
        ans=sum;
    }
    for(int i=k;i<n;i++){
        sum = sum - arr[i-k];
        sum = sum +arr[i];

        if(sum<x){
            ans=max(ans,sum);
        }
    }
    cout<<ans<<endl;
}

int main(){

    int arr[]={1,5,6,7,8,9};
    maxSubSum(arr,6,3,20);
    cout<<endl;
    return 0;
}
