#include <bits/stdc++.h>
using namespace std;


//needs to be corrected
int main(){

    int k;
    cin>>k;
    vector<vector<int>>a(k);

    for(int i=0;i<k;i++){
        int size;
        cin>>size;

        a[i]=vector<int>(size);
        for(int j=0;i<size;j++){
            cin>>a[i][j];
        }
    }

    vector<int> idx(k,0);

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    for(int i=0;i<k;i++){
        pq.push({a[i][0],i});
    }

    vector<int> ans;

    while(!pq.empty()){
        pair<int,int> x=pq.top();
        pq.pop();

        if(idx[x.second]+1 < a[x.second].size()){
            pair<int,int> p;
            p.first=a[x.second][idx[x.second]+1];
            p.second=x.second;

            pq.push(p);
            }

        idx[x.second]+=1;
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}