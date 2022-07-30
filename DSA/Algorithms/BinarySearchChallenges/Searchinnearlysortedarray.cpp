#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a;
    int s;
    for(int i=0;i<n;i++){
        cin>>s;
        a.push_back(s);
    }
    int x;
    cin>>x;

    int l=0,r=n-1;
    while(l<=r){
        int mid=l+(r-l)/2;

        if(a[mid]==x){
        cout<<true;
        break;
        }

        else if(mid-1>=l && a[mid-1]==x) {
        cout<<true;
        break;
        }
        else if(mid+1<=r && a[mid+1]==x) {
        cout<<true;
        break;
        }
        else {
            if(a[mid]>x)
            r=mid-2;
            else
            l=mid+2;
        }
    }
    return 0;
}