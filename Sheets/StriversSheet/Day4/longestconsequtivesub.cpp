class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int finalcount =0;
        for(int i=0;i<nums.size();i++)
            s.insert(nums[i]);
        
        for(int i=0;i<nums.size();i++){
             int count=1;
            if(s.count(nums[i]-1)==0)
            {
                int val =nums[i]+1;
                while(s.count(val)){
                val++;
                count++;
                }
            finalcount= max(count,finalcount);
            }
        }
        
        
      return finalcount;  
        
    }
};