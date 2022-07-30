class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int  best_sum = INT_MIN;
      int current_sum = 0;
      for (int x:nums){
        current_sum = max(x, current_sum + x);
        best_sum = max(best_sum, current_sum);
        }
    return best_sum;
    }
};