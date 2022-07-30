#include <bits/stdc++.h>

using namespace std;

const int N=1e5+2;

vector<int> adj[N];

int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<int>> adjm (n+1, vector<int>(n+1,0));

    for(int i=0;i<m;i++){

        int x,y;
        cin>>x>>y;

        adjm[x][y]=1;
        adjm[y][x]=1;
    }
    cout<<"ADJACENCY MATRIX"<<endl;

    for(int i=1;i<n+1;i++){

        for(int j=1;j<n+1;j++){
            cout<<adjm[i][j]<<" ";
        }
        cout<<endl;
    }
    //if there is 1 present we get a edge.

    cout<<endl;
    cin>>m>>n;

    for(int i=0;i<m;i++){

        int x,y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);

    }

    cout<<"Adjacency List"<<endl;

    for(int i=1;i<n+1;i++){
        cout<<i<<"->";
        for(int x:adj[i])
        cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}