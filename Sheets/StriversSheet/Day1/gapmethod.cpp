//make to make perfect
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr1 ={1,2,5,8,10};
    vector<int> arr2 ={3,5,7,9,11};
    
    int gap = (arr1.size()+arr2.size())/2;

    while(gap >= 1 ){
            int i=0,j=i+gap;
            int flag=0, flag1=0;

        while(j < arr2.size() && flag1==0){


            if(i>=arr1.size() && flag==0){
            i-=arr1.size();
            flag=1;
            }

            if(j>=arr1.size()&& flag1==0){
            j-=arr1.size();
            flag1=1;
            }

            if(flag == 0 && flag1==0 && arr1[i]>arr1[j])
              swap( arr1[i], arr1[j]);
            if(flag == 0 && flag1==1 && arr1[i]>arr2[j])
                swap(arr1[i], arr2[j]); 
            if(flag == 1 && flag1 == 1 && arr2[i]>arr2[j])
                swap( arr2[i], arr2[j]); 

            i++;
            j++;

        }
        gap/=2;

    }

    for(auto i:arr1){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i:arr2){
        cout<<i<<" ";
    }
    return 0;
}