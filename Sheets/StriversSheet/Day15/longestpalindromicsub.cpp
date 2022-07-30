class Solution {
public:
    
    bool Palindrome(string s){
        if(s.size()<=1)
            return true;
        int i=0,j=s.size()-1;
        while(i<=j){
            if(s[i]!=s[j])
                return false;
            i++;j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n=s.size();
        string ss="";
        for(int i=n;i>=0;i--){
            for(int j=0;j<=(n-i);j++){
                ss = s.substr(j,i);
                if(Palindrome(ss))
                    return ss;                                                                  
            }
        }
        return ss;
    }
};
//but this is giving tle. I need to manage this with dp solution

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        //edge cases
        if (s.empty()) 
            return "";
        if (s.size() == 1)
            return s;
        
        vector<vector<int>> dp(n, vector<int>(n,1));
        for(int i=0;i<n;i++){
            dp[i][i]=1;
            if(i<n-1){
            if(s[i]==s[i+1])
                dp[i][i+1]=1;
            else
                dp[i][i+1]=0; 
            }
        }
        
        int maxi=1;
        int start=0;
        
        for (int i=n-2; i>= 0; i--){
            for (int j=i+1; j<n; j++){
                if(s[i]==s[j] && dp[i+1][j-1]==1){
                    dp[i][j]=1;
                    int size = j-i+1;
                    if(size>=maxi){
                        maxi=size;
                        start=i;
                    }
                }
                else
                 dp[i][j]=0;
            }
        }
        
     return s.substr(start,maxi);
    }
};