#include <bits/stdc++.h>
using namespace std;


const int N  = 1e+5 +2;
bool vis[N];

vector<int> adj [N];

int main(){

    for (int i=0;i<N;i++){
        vis[i]=false;
    }

    int n,m;
    cin>>n>>m;

    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        
    adj[x].push_back(y);
    adj[y].push_back(x);
    }

    for(int i = 1;i<N;i++){
        if(!vis[i]){

    queue<int> q;

    q.push(i);
    vis[i]=true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<endl;

        vector<int>:: iterator it;

        for(it=adj[node].begin();it!=adj[node].end();it++){
            if(!vis[*it]){
                vis[*it]=true;
                q.push(*it);
            }
          }
        }
      }
    }

 
 return 0;
}