#include <iostream>
#include<stack>

using namespace std;

int prec(char c){
    if(c=='^'){
        return 3;
    }
    else if (c=='*'||c=='/'){
        return 2;
    }
    else if(c=='+'||c=='-'){
        return 1;
    }
    else
    return -1;
}

string infixToPostfix(string s){
    stack<char> st;
    string res;

    for(int i=0;i<=s.length();i++){

        if((s[i]>='0' && s[i]<='9'))
        res+=s[i];

        else if (s[i]=='('){
            st.push(s[i]);
        }

        else if(s[i]==')'){

            while(!st.empty() && st.top()!='('){
                res+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        
        else{
            while(!st.empty() && prec(st.top())>prec(s[i])){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    return res;

}

int main(){
    cout<<infixToPostfix("(1-2/4)*(6/7-9)")<<endl;
    return 0;
}