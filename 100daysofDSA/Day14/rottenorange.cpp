class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
     queue<pair<int,int>> q;
      int count = 0;
      int m=grid.size(), n=grid[0].size();
     for(int i=0;i<m;i++){
         for(int j=0;j<n;j++){
            if(grid[i][j]==2)
                q.push({i,j});
            if(grid[i][j]==1)
                count++;
      }
     } 
        
    //edge cases
    if(count == 0)
        return 0;
    if(q.empty())
        return -1;
        
        
    int a = q.size(),k=0;
    while(!q.empty()){
        pair<int,int> place = q.front();
        a--;
        int i=place.first, j= place.second;
        if(i-1>=0 && grid[i-1][j]==1)
        {
            grid[i-1][j]=2;
            q.push({i-1,j});
        }
        if(i+1<m && grid[i+1][j]==1)
        {
            grid[i+1][j]=2;
            q.push({i+1,j});
        }
        if(j-1>=0 && grid[i][j-1]==1)
        {
            grid[i][j-1]=2;
            q.push({i,j-1});
        }
        if(j+1<n && grid[i][j+1]==1)
        {
            grid[i][j+1]=2;
            q.push({i,j+1});
        }
        q.pop();
        if(a==0){
        a=q.size();
        count-=a;
        k++;   
        }
    }
    if(count==0)
        return k-1;
    else
        return -1;
    }
};