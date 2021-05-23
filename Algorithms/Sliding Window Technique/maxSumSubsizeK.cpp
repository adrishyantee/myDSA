#include <bits/stdc++.h>
using namespace std;

void maxSubSum(int arr[],int n,int k){
int i=0,j=0,sum=0,ans=0;

    while(j<n){

        sum+=arr[j];
        if (j-i+1 < k){
        j++;
        }
        else if(j-i+1 == k){
            ans=max(ans,sum);
            sum = sum - arr[i];
            j++;
            i++;  
        }
    }
    cout<<ans<<endl;
}

int main(){
    int arr[]={1,5,6,7,8,9};
    maxSubSum(arr,6,2);
    return 0;
}