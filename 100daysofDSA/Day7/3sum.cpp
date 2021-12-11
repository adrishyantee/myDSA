class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       
       vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        
        if(nums.size()<=2)
          return ans;
       int i=0;
       while(i<nums.size()-2) {
          if(i==0 || (i>0 &&nums[i-1]!=nums[i])){
           int low = i+1 , high = nums.size()-1;
           int tofind = 0-nums[i];
           while(low<high){         
               if(nums[low]+nums[high] == tofind){
               ans.push_back({nums[i],nums[low],nums[high]});
                   while(low<high && nums[low+1]==nums[low]) low++;
                   while(low <high &&  nums[high-1]==nums[high]) high--;
                   low++;
                   high--;
               }
               else if (nums[low]+nums[high] < tofind)
                   low++;
               else
                   high--;
              }  
            }
           i++;
           
       }
        return ans;
    }
};