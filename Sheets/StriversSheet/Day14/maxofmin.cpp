class Solution
{
    public:
    //Function to find maximum of minimums of every window size.

    vector <int> maxOfMin(int arr[], int n)
    {
        vector<int> ans(n,0);
        stack<pair<int,int>> st;
        
        vector<int> leftlimit(n,-1),rightlimit(n,-1);
        
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top().second >= arr[i])
            st.pop();
            
            if(st.empty())
            leftlimit[i]=i;
            else
            leftlimit[i]=i-st.top().first-1;
            
            st.push({i,arr[i]});
        }
        
        while(!st.empty())
        st.pop();
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top().second >= arr[i])
            st.pop();
            
            if(st.empty())
            leftlimit[i]=n-1-i;
            else
            leftlimit[i]=st.top().first-i-1;
            
            st.push({i,arr[i]});
        }
        int windowsize=0;
        for(int i=0;i<n;i++){
            windowsize = leftlimit[i]+rightlimit[i];
            ans[windowsize] = max(arr[i],ans[windowsize]);
        }
        int r=ans[n-1];
        for(int i=n-1;i>=0;i--){
            if(ans[i]==0)
            ans[i]=r;
            else
            r=ans[i];
        }
        return ans;
    }
};