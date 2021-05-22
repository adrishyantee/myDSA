#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
         int mx=0,i=0,j=0;

    unordered_map<char,int> mp;
    while(i<s.length()){
        mp[s[i]]++;
        
        if(mp.size()==i-j+1){
            mx=max(mx,i-j+1);
            i++;
        }
        else if(mp.size() <i-j+1){
            while(mp.size()<i-j+1){
            mp[s[j]]--;
            
            if(mp[s[j]]==0)
            mp.erase(s[j]);
            j++;
            }
            i++;
        }
        }
    return mx;
}


int main(){
    string s="abcabcde";
    cout<<lengthOfLongestSubstring(s);

    return 0;
}

