 #include <bits/stdc++.h>
 using namespace std;



int minSubSize(int arr[], int n,int x){
    int sum = 0, minlen = n+1, start=0,end=0;

    while(end<n){
        while(sum <= x && end <n){
            sum+=arr[end++];
        }

        while(sum > x && start <n){
            if(end-start < minlen){
                minlen = end - start;
            
            }
            sum-=arr[start];
            start++;
        }
    }
    return minlen;
}
 int main(){
     int arr[]={1,4,45,6,10,19};
     int minlen = minSubSize(arr,6,51);
     if(minlen==6+1){
         cout<<"No such subarray exists"<<endl;
     }
     else{
     cout<<endl;
     }

     return 0;
 }