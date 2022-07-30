 #include <bits/stdc++.h>
 using namespace std;
 
 int search(vector<int>& nums, int target) {
        int l=0, r =nums.size()-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target)
                r=mid-1; 
            else 
                l=mid+1;
        }
        return -1;
    }




        // if(nums.size()==1)
//             return nums[0];
        
//         if(nums.size()==2){
//         if(nums[0]<nums[nums.size()-1])
//          return nums[0];
//         else
//          return nums[1];
//         }
    int findMin(vector<int>& nums) {
        int l=0, r =nums.size()-1;
        if(nums[0]<nums[nums.size()-1])
        return nums[0];
        while(l<=r){
            
            int mid = l+(r-l)/2;
            int next = (mid+1)%nums.size();
            int prev = (mid-1+nums.size())%nums.size();

            if(nums[mid]<=nums[prev] && nums[mid]<=nums[next]){
                return mid;
            }
            if(nums[mid]>=nums[0])
                l=mid+1; 
            else if(nums[mid]<=nums[nums.size()-1])
                r=mid+1;
        }
        return -1;
    }


    int main(){
        return 0;
    }