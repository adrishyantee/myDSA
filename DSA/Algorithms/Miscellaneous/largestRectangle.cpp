#include <bits/stdc++.h>
using namespace std;

int getMaxArea(int arr[],int n){
    stack<int> st;
    int ans=0,i=0;
    arr[n]=0;

    while(i<n){
        while(!st.empty() && arr[st.top()]>arr[i]){
            int h=arr[st.top()];
            st.pop();
            if(st.empty()){
                ans=max(ans,h*i);
            }
            else{
                int len=i-st.top()-1;
                ans=max(ans,h*len);
            }
        }
            st.push(i);
            i++;
            }
return ans;
}

int main(){

int a[]={2,1,5,6,2,3};

//NAIVE APPROACH

    // int ans=0;
    int n = 6;
    // for(int i=0;i<n;i++){
    //     int minh=INT_MAX;

    //     for(int j=i;j<n;j++){
    //         minh=min(a[j],minh);
    //         int len=j-i+1;
    //         ans=max(ans,len*minh);

    //     }

    // }
    // cout<<ans<<endl;
    cout<<getMaxArea(a,n)<<endl;
    return 0;
}