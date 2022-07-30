class Solution {
public:
    void permutation (int idx, int n, vector<int> &nums, vector<vector<int>> &ans){
        if(idx==n){
        ans.push_back(nums);
        return;
    }
    for(int i=idx;i<n;i++){
            swap(nums[idx],nums[i]);
            permutation(idx+1,n,nums,ans);
            swap(nums[idx],nums[i]);//need to swap bavk for next iteration
        }
    }
     vector<vector<int>> permute(vector<int>& nums) {
     vector<vector<int>> ans;
     int n=nums.size();
        
        permutation(0,n,nums,ans);
        return ans;
    }
};