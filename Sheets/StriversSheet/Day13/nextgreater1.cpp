class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size(); 
        
        vector<int> nge(10001, -1);
        vector<int> ans;
        stack<int> st; 
        for(int i =n-1;i>=0;i--) {
            
            while(!st.empty() && st.top() <= nums2[i]) {
                st.pop(); 
            }
            
            if(!st.empty())
                 nge[nums2[i]] = st.top();
            else
                nge[nums2[i]] =-1;
            
            st.push(nums2[i]);
        }
        
        for(int i=0;i<nums1.size();i++){
            ans.push_back(nge[nums1[i]]);
            
        }
        return ans; 
    }
};