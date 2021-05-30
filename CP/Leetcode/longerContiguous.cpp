#include <bits/stdc++.h>
using namespace std;

bool checkZeroOnes(string s) {
        int count1=0,count0=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                count1++;
            }
            if(s[i]=='0'){
                count0++;
            }
        }

        cout<<count1<<" "<<count0<<endl;
        if(count1-count0 > 0)
            return true;
        else
            return false;
    }

    int main(){
        string s= "011000111";
        if(checkZeroOnes(s))
        cout<<"true";
        else
        cout<<"false";
        return 0;
    }