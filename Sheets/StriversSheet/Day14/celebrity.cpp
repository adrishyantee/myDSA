class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>st;
       
       for(int i=0;i<n;i++)
        st.push(i);
        
        while(st.size()>=2){
            int p=st.top();
            st.pop();
            int q=st.top();
            st.pop();
            
            if(M[p][q]==0)
             st.push(p);
             
             else
              st.push(q);
        }
        
        int t=st.top();
        for(int i=0;i<n;i++){
            
            if(i!=t && (M[t][i]==1 || M[i][t]==0))
            return -1;
        }
        return t;
    }
};