#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={1,1,1,0,0,0,1,1,1,1,0};
    int n=11;
    int zerocount=0,i=0,ans=0;
    int k=3;

    for(int j=0;j<n;j++){
        if(arr[j]==0)
        zerocount++;
        while(zerocount>k){
            if(arr[i]==0)
            zerocount--;
            i++;
        }
        ans=max(ans,j-i+1);
    }
    cout<<ans<<endl;
    return 0;
}