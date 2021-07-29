#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m; cin>>m>>n;

        vector<vector<int>> adj(n);
        vector<int> indeg(n,0);

        for(int i=0;i<m;i++){

        int x,y;
        cin>>x>>y;
// x to y
        adj[x].push_back(y);
        indeg[y]++;
        }

        queue<int> pq;
        for(int i = 0;i<n;i++){
            if(indeg[i]==0){
                pq.push(i);
            }
        }


        int cnt=0;
        while(!pq.empty()){
            cnt++;
            int x = pq.front();
            pq.pop();

            cout<<x<<" ";

            for(int i:adj[x]){
                indeg[i]-=cnt;
                if(indeg[i]==0)
                pq.push(i);
            }
        }

        return 0;

}