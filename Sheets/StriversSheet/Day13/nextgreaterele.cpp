class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> nge(n, -1);
        stack<int> st; 
        for(int i = 2*n-1;i>=0;i--) {
            
            if(i<n) {
            while(!st.empty() && st.top() <= nums[i]) {
                st.pop(); 
            }
                if(!st.empty()) nge[i] = st.top(); 
            }
            st.push(nums[i%n]);
        }
        return nge; 
    }
};