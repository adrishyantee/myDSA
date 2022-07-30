class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {

        
        int n=image.size();
        int m=image[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int initial = image[sr][sc];
        image[sr][sc]=newColor;
        visited[sr][sc]=true;
        
        while(!q.empty()){
            
            int size=q.size();
            for(int k=0;k<size;k++){
                int ini=q.front().first;
                int inj=q.front().second;
              
                q.pop();
                
                int val=1;
                int i=ini,j=inj;
                
                for(int s=0;s<4;s++){
                    if(s%2==0)
                        i+=val;
                    else
                        j+=val;
                     if(i>=0 && i<n && j>=0 && j<m && image[i][j]==initial && !visited[i][j]){
                    image[i][j]=newColor;
                    q.push({i,j});
                    visited[i][j]=true;
                     }
                    if(s==1)
                    val=-1;
                    i=ini,j=inj;
                }
            }
            
        }
        
        return image;
    }
};