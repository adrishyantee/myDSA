#include <bits/stdc++.h>
using namespace std;

void maxSubSum(int arr[],int n,int k){
int i=0,j=0;

queue<int> q;

    while(j<n){

        if(arr[j]<0){
        q.push(arr[j]);
        }

        if (j-i+1 < k){
        j++;
        }

        else if(j-i+1 == k){
            if(q.size()!=0)
            cout<<q.front()<<endl;
            else
            cout<<0<<endl;
            
            j++;

            if(q.front()==arr[i])
            q.pop();
            i++;  
        }
    }
}

int main(){
    int arr[]={-1,-5,6,-7,8,-9};
    maxSubSum(arr,6,3);
    return 0;
}