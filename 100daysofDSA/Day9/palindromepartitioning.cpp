class Solution {
public:
    
      bool isPalindrome(string s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
    
     void func(int index, string s, vector<string> &cases,  vector<vector<string> > &res) {
        if(index == s.size()) {
            res.push_back(cases);
            return;
        }
        for(int i = index; i < s.size(); ++i) {
            if(isPalindrome(s, index, i)) {
                cases.push_back(s.substr(index, i - index + 1));
                func(i+1, s, cases, res);
                cases.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string> > res;
        vector<string> cases;
        func(0, s,cases, res);
        return res;
        
    }
};