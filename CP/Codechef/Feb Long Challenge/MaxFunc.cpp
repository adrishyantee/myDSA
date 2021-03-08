#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T>0){
        int n;
        cin>>n;
        long long int arr[n];
        for(int i =0;i<n;i++)
        {
            cin>>arr[i];
        }
        long long int Max=arr[0];
        long long int Min=arr[0];
        for(int i=0;i<n;i++){ 
            if (arr[i]>=Max)
            Max=arr[i];
            if(arr[i]<=Min)
            Min=arr[i];
        }
        T--;
    cout<<2*(Max-Min)<<endl;; 
    }
      return 0;
}