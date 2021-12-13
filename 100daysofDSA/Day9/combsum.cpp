class Solution {
public:
    
        
    void findSubsets(int idx, int sum, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans){
        if(idx>=nums.size()){
            return;
        }
        else if(sum==0){
        ans.push_back(ds);
            return;
        }
        else{
                if(sum>=nums[idx]){
                ds.push_back(nums[idx]);
                findSubsets(idx,sum-nums[idx],nums,ds,ans);
                ds.pop_back();
                }
                findSubsets(idx+1,sum,nums,ds,ans);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans; 
        vector<int> ds; 
        findSubsets(0, target, candidates, ds, ans);
        return ans;   
    }
};