//moore's voting algo 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count =0; int element;
        for(int i=0;i<nums.size();i++){
            if(count ==0)
                element=nums[i];
            if(element==nums[i])
                count++;
            else
                count--;
        }
        return element;
    }
};