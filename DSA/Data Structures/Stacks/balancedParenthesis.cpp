#include <iostream>
#include<stack>
using namespace std;

bool isValid(string s){
    stack<char> st;

    for(int i=0;i<s.length();i++){
        char a=s[i];

        if(a=='{' || a=='[' || a=='(')
        st.push(a);

        else if (a==')'){
            if(!st.empty() && st.top()=='('){
                st.pop();
            }
            else{ 
            return false;
        }
        }
        else if (a=='}'){
            if(!st.empty() && st.top()=='{'){
                st.pop();
            }
            else 
            return false;
        }
         else if (s[i]==']'){
            if(!st.empty() && st.top()=='['){
                st.pop();
            }
            else 
            return false;
        }
    }

    if(!st.empty())
      return false;
    else 
      return true;
}

int main(){
    string s="({[]})";
    if(isValid(s)){
        cout<<"Valid string"<<endl;
    }
    else
    cout<<"Invalid string"<<endl;
    return 0;
}
