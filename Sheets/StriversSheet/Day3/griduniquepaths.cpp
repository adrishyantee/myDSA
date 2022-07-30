//this is a better solution not a optimised one

class Solution {
public:
         
    int uniquePathshelper(int m, int n, int i, int j, vector<vector<int>> &dp){
     if(i==m-1 && j==n-1)
         return 1;
     else if(i>=m || j>=n)
         return 0;
     else if(dp[i][j]!=-1) return dp[i][j];
     else
       return dp[i][j]=uniquePathshelper(m,n,i+1,j,dp)+ uniquePathshelper(m,n,i,j+1,dp);
          
    }
    int uniquePaths(int m, int n) {
          vector<vector<int>> dp(m,vector<int>(n,-1));
        return uniquePathshelper(m,n,0,0,dp);
    }
};
//get the result- optimised
        int top = n+m-2;
        int below = m-1;
        
        double res = 1;
        for(int i=1;i<=below;i++)
        res*=(top-below+i)/i;

        return round(res);     
    }