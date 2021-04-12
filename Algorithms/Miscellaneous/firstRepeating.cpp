#include <bits/stdc++.h>
#include <set>
using namespace std;

int firstRepeated(int arr[], int n) {
        //code here
        set<int>s;
        int index=-1;
        for(int i=n-1;i>=0;i--){
            if(s.find(arr[i])!=s.end())
            index=i;
            else
            s.insert(arr[i]);
        }
        return index;

    }
    int main(){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<firstRepeated(arr,n);
    }