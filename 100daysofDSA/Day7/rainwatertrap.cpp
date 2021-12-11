class Solution {
public:
    int trap(vector<int>& height) {
              // to store right max element and left max element for every height
        vector<int> leftMax(height.size()), rightMax(height.size());
        
        // tracking left max and right max in variables and initializing vectors
        int lMax = 0, rMax = 0;
        leftMax[0] = height[0];
        rightMax[height.size()-1] = height[height.size()-1];
        for(int i = 1; i < height.size(); i++){
        leftMax[i] = max(height[i],leftMax[i-1]);
        }
        for(int i = height.size()-2; i >= 0; i--){
         rightMax[i] = max(height[i],rightMax[i+1]);
        }
        
        // calculating total water for every index
        int totalWater = 0;
        for(int i = 0; i < height.size(); i++)
            totalWater += min(rightMax[i],leftMax[i]) - height[i];
        return totalWater;
    }


//optimised solution

//two pointers
class Solution {
public:
    int trap(vector<int>& a) {
        int l=0, r=a.size()-1,leftmax=0, rightmax=0;
        int res=0;
        while(l<=r){
            if(a[l]<=a[r]){
                if(a[l]>=leftmax)
                    leftmax=a[l];
                else
                    res+=leftmax-a[l];
                l++;
            }
            else{
                if(a[r]>=rightmax)
                    rightmax=a[r];
                else
                    res+=rightmax-a[r];
                r--;
            }
        }
        return res;
    }
};