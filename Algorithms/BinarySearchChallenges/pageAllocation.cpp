#include <bits/stdc++.h>
using namespace std;


bool isPossible(vector<int> arr,int n, int m, int min){
    int studentsRequired=1,sum=0;

    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum>min){
            cout<<sum<<endl;
            studentsRequired++;
            sum=arr[i];
            if(studentsRequired > m){
                return false;
            }
        }
    }
    return true;
}

int allocateMinimumPages(vector<int>arr, int n, int m){
    int sum=0;
    if(n<m){
        return -1;
    }

    for(int i=0;i<n;i++){
        sum+=arr[i];
    }

    int start = *max_element(arr.begin(), arr.end()),end=sum,ans =-1;

    while(start<=end){
        int mid=start+(end-start)/2;
        if(isPossible(arr,n,m,mid)){
            ans=mid;
            end=mid-1;
        }
        else{
        start=mid +1;
        }
    }

    return ans;
}
int main(){
    vector<int> arr={1,4,4};
    cout<<allocateMinimumPages(arr,3,3)<<endl;
    return 0;
}