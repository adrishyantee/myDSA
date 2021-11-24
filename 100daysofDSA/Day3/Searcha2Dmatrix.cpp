class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m=matrix.size();
        int n=matrix[0].size();
        
            
        int i=0;
        int j=n-1;
        
        while(i>=0 && i<m && j>=0 && j<n){
            
            if(target == matrix[i][j])
                return true;
            
            else if(target > matrix[i][j])
                i++;
            else if(target < matrix[i][j])
                j--;
        }
        return false;  
    }
};