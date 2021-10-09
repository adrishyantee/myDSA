#include <bits/stdc++.h>
using namespace std;

int searchinRotatedArray(int arr[],int key, int left , int right){
    if(left>right){
        return -1;
    }

    int mid=(left+right)/2;
    if(arr[mid]==key){
        return mid;
    }

    if(arr[left]<=arr[mid]){
        if(key>=arr[left]&& key <= arr[mid]){
            return searchinRotatedArray(arr,key,left,mid-1);
        }
        return searchinRotatedArray(arr,key,mid+1,right);
    }
        if(key>=arr[mid]&& key <= arr[right]){
            return searchinRotatedArray(arr,key,mid+1,right);
        }
        return searchinRotatedArray(arr,key,left,mid-1);
}

int main(){
    int arr[]={30,40,50,10,20};
    int idx=searchinRotatedArray(arr,10,0,4);
    if(idx==-1){
        cout<<"Key doesn't exist"<<endl;
    }
    else{
        cout<<"Key exists at :"<<idx<<endl;
    }
    return 0;
}