#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            auto pt=mp.find(target-nums[i]);
            if(pt!=mp.end())
                return{mp[target-nums[i]],i};
            mp[nums[i]]=i;
        }
        return {-1,-1};
    }
};

int main(){
    Solution s;
    vector<int> nums{2,4,7,11};
    vector<int> ans=s.twoSum(nums,9);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}