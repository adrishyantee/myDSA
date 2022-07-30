#include <bits/stdc++.h>
using namespace std;

    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++) sum+=nums[i];
        
        if(sum & 1){
            return false;
        }
        
        bool dp[nums.size()+1][sum/2+1];
        
        //init condition to fill
        for(int i=1;i<sum/2+1;i++) dp[0][i] = false;
        for(int i=0;i<nums.size()+1;i++) dp[i][0] = true;
        //dp 
        for(int i=1;i<=nums.size();i++){
            for(int j=1;j<=sum/2;j++){
                
                //exclude 
                bool ex = dp[i-1][j];
                // include
                
                int rs = j - nums[i-1];
                int in =false;
                if(rs == 0){
                    in = true;   
                }
                else if(rs>-1){ 
                    in = dp[i-1][j-nums[i-1]];
                }
                dp[i][j] = in || ex ;
                
            }
            
        }
        return dp[nums.size()][sum/2];
    }

int main()
{
    vector<int> val = { 50, 100, 50 };
    int sum=100;     
    cout << canPartition(val);
     
    return 0;
}