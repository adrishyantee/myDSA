class Solution {
public:
    bool isValid(string s) {
      stack<char> st;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                st.push(s[i]);
            else{
                if(st.empty())
                    return false;
                else{
                    char val = st.top();
                    if((s[i]==')' && val=='(')||(s[i]==']' && val=='[')||(s[i]=='}' && val=='{'))
                        st.pop();
                    else
                    return false;
                }
            
            }
        }
        if(st.empty())
                return true;
        else
            return false;
    }
};