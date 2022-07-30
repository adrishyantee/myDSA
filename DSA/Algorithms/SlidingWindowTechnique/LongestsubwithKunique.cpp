#include <bits/stdc++.h>
using namespace std;

int longestSubstring(string s,int k){
    int mx=0,i=0,j=0;

    unordered_map<char,int> mp;
    while(i<s.length()){
        mp[s[i]]++;

        if(mp.size()<k)
        i++;
        else if(mp.size()==k){
            mx=max(mx,i-j+1);
            i++;
        }
        else if(mp.size() > k){
            while(mp.size()>k){
            mp[s[j]]--;
            
            if(mp[s[j]]==0)
            mp.erase(s[j]);
            }
            j++;
            }
            i++;
        }
    return mx;
}


int main(){
    string s="abcabcde";
    int k=3;
    cout<<longestSubstring(s,k);
    //ans =6

    return 0;
}