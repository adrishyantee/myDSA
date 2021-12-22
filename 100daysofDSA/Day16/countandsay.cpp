class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        string a = countAndSay(n-1);
        
        vector<pair<char,int>> v;
        string newa="";
        v.push_back({a[0],1});
        int j=0;
        for(int i=1;i<a.size();i++){
            if(a[i]==a[i-1])
                v[j].second++;
          else{
              v.push_back({a[i],1});  
              j++;
          }
        }
        
        for(auto i:v)
            newa = newa +  ((char)(i.second + '0'))+ i.first;
        
        return newa;
    }
};