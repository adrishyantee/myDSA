#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj,int s,vector<bool>& vis){
    vis[s] = true;
    for(int i=0; i<adj.size(); i++)
    if(!vis[i] && adj[s][i] == 1)
    dfs(adj,i,vis);
}
void make_graph(vector<vector<int>>& adj,int V){
    cout<<"Enter the elements of the adjacency matrix : \n";
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
            int n;
            cin>>n;
            adj[i][j] = n;
        }
    }
}

int main(){
    int V;
    cout<<"Enter the number of vertices : ";
    cin>>V;
    int ans = 0;

    vector<vector<int>> adj(V,vector<int> (V,0));
    make_graph(adj,V);
    vector <bool> visited(V,false);
    for(int i=0; i<V; i++)
    if(!visited[i]){
    dfs(adj,i,visited);
    ans++;
    }
    if(ans > 1)
    cout<<"The graph is disconnected\n";
    else
    cout<<"The graph is connected\n";
    cout<<"No of connected components:"<<ans<<endl;
    return 0;
}

 
