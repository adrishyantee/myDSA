class Solution {
public:
        
    void findSubsets(int idx, int sum, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans){
       if(sum==0){
       ans.push_back(ds);
            return;
        }
         for(int i=idx ;i<nums.size();i++){
            if(i==idx || nums[i]!=nums[i-1])
            {
                if(sum>=nums[i]){
                ds.push_back(nums[i]);
                findSubsets(i+1, sum - nums[i],nums,ds,ans);
                ds.pop_back();     
              }
             else
             break;
            }
           
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans; 
        vector<int> ds; 
        findSubsets(0, target, candidates, ds, ans);

        return ans;    
    }
};