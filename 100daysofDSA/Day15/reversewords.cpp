class Solution {
public:
    string reverseWords(string s) {
        int j=0;
        int n=s.size();
        string res="";
        int i=n-1;
        while(i>=0){
            if(s[i]!=' ' && i>=0){
                j=i;
            while(j>=0 && s[j]!=' ' )
                j--;
            
            int it = j;
            j++;
            while(j<=i){
                res+=s[j];
                j++;
            }
            res+=" ";  
            i=it;
            }
            else
                i--;
        }
        res=res.substr(0, res.size()-1);
        return res;
    }
    
};