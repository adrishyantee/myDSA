#include <bits/stdc++.h>
using namespace std;


void maxSubSum(int arr[],int n,int k){
    int sum=0,ans=0;

    for(int i=0;i<k;i++){
        sum+=arr[i];
    }
    ans=sum;
    for(int i=k;i<n;i++){
        sum = sum - arr[i-k]  + arr[i];;
            ans=max(ans,sum);
        }
    cout<<ans<<endl;
}

int main(){

    int arr[]={1,5,6,7,8,9};
    maxSubSum(arr,6,2);
    return 0;
}
