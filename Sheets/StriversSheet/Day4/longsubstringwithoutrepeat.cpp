class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=0;
        set<char> st;
        int n=s.size();
        
        int l=0,r=0;
        while(r<n){
            if(st.count(s[r])==0){
                   st.insert(s[r]);
               }
             else{
                 while(st.count(s[r])!=0 && r>l){
                     st.erase(s[l]);
                         l++;
                    }
                 }
                 st.insert(s[r]);
                 len=max(len,r-l+1);
                 r++;
        }
               
       return len;
    }
};