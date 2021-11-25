class Solution {
public:
 
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        if(nums.size()<4)
            return {};
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        vector<vector<int>> ans;
        
        
        for(int i=0;i<n;i++){
             
            for(int j=i+1;j<n;j++){
                int front =j+1,back=n-1;
                int target1=target-nums[i]-nums[j];
                 
                while(front < back){
                   
                    int sum = nums[front]+nums[back];
                    if(sum<target1) front++;
                    else if(sum>target1) back--;
                    else{
                         vector<int> v;
                         v.push_back(nums[i]);
                         v.push_back(nums[j]);
                         v.push_back(nums[front]);
                         v.push_back(nums[back]);
                         ans.push_back(v);    //put in hashtable
                    
                    while(front<back && nums[front]== v[2])front++;
                    while(front<back && nums[back]== v[3])back--;
                    }
                }
                while(j+1<n && nums[j+1]==nums[j])j++;
                
            }
              while(i+1<n && nums[i+1]==nums[i])i++;
        }
        
        return ans;
    }
};