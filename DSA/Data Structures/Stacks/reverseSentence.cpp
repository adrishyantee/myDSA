#include <iostream>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

void reverseSentence(string s){// the function to reverse the sentence
        stack<string> st;
        string word="";// the temporary word set to null

        for(int i=0;i<s.length();i++){
            if(s[i]== ' '){//if space found then push in the stack and clear the word variable
            st.push(word);
            word="";
            }
            else
            word+=s[i];//keep on adding the characters to make the word
        }
        st.push(word);

        while(!st.empty()){//until the stack becomes empty
            cout<<st.top()<<" ";//print the stack's top element each time
            st.pop();//keep on poppin the last element
        }
        cout<<endl;
    }

int main(){

    string s="Hey, how are you doing?";
    reverseSentence(s);
    
}
