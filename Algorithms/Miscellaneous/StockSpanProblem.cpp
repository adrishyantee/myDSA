#include <bits/stdc++.h>
using namespace std;

//done implementing stack for this seemed easier
vector<int> stockSpan(vector<int> prices){
    vector<int>ans;
    stack<pair<int,int>>s;
    for(auto price:prices){
        int days=1;
        while(!s.empty() and price>=s.top().first){
            days+=s.top().second;
            s.pop();
        }
        s.push({price,days});
        ans.push_back(days);
    }
    return ans;
}

int main(){
    vector<int> a={100,80,60,70,60,75,85};
    vector<int> res=stockSpan(a);
    for(auto i:res)
    cout<<i<<" ";
    cout<<endl;

//BRUTE FORCE SOLUTION:
    // int arr[]={100,80,60,70,60,75,85};
    // int n=7;
    // vector<int> a;
    // for(int i=0;i<n;i++){
    //     int days=0;
    //     for(int j=i;j>=0;j--){
    //         if(arr[i]>=arr[j]){
    //             days++;
    //         }
    //         else{
    //                 break;
    //             }
    //         }
    //         a.push_back(days);
    //     }
    // for(auto i:a)
    // cout<<i<<" ";
    // cout<<endl;
return 0;    
}
