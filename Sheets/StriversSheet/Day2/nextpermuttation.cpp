class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i=n-2,j=n-1;
        while (i>=0 && nums[i]>=nums[i+1]) 
           i--;        
        if(i>=0){
             while (nums[i]>=nums[j]) 
               j--;
         swap(nums[j],nums[i]);
        }
        reverse(nums.begin()+i+1,nums.end());
    }
};