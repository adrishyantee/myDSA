#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[]={1,3,6,7,9,12};
    int n=6;
    int k=100;
    bool found=false;

    sort(a,a+n);

    for(int i=0;i<n;i++){
        int l=i+1,h=n-1;
        while(l<h){
            int current=a[i]+a[h]+a[l];
            if(current==k){
            found=true;
            break;
            }
           else if(current<k)
           l++;
           else
           h--;
        }
    }
    cout<<found<<endl;
    return 0;
}