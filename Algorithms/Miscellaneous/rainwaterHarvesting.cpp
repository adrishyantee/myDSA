//we use two pointer approach

#include <bits/stdc++.h>
using namespace std;

int main(){
    int height[]={0,1,0,2,1,0,1,3,2,1,2,1};
    int n=12;
    int l=0,r=n-1;
    int leftmax=0,rightmax=0;
    int water=0;


    while(l<=r){
    if(height[l] <= height[r]){

        if(leftmax <= height[l])
        leftmax = height[l];
        else
        water+=leftmax-height[l];


        l++;
    }
    else{
        if(rightmax <= height[r])
        rightmax = height[r];
        else
        water+=rightmax-height[r];

        r--;
    }
}

    cout<<water<<endl;

    return 0;
}
