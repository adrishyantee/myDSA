#include <iostream>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

void reverseSentence(string s){
        stack<string> st;
        string word="";

        for(int i=0;i<s.length();i++){
            if(s[i]== ' '){
            st.push(word);
            word="";
            }
            else
            word+=s[i];
        }
        st.push(word);

        while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
        }
        cout<<endl;
    }

int main(){

    string s="Hey, how are you doing?";
    reverseSentence(s);
    
}
