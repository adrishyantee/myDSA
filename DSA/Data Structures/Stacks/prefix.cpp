#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int prefixEvaluation(string s){//pass the string expression
    stack <int> st;//make a stack
    for (int i=s.length()-1;i>=0;i--){//traverse from the end ie, left to right
        if(s[i]>='0' && s[i]<='9')//if its a number ie, an operand
        st.push(s[i]-'0');//put it in stack
        else{//if not
            int op1=st.top();//take out first two of the top values and store as operands
            st.pop();
            int op2=st.top();
            st.pop();
            switch(s[i])//this is an operator so we take different cases for each
            {
                case '+':
                st.push(op1+op2);
                break;
                case '-':
                st.push(op1-op2);
                break;
                case '*':
                st.push(op1*op2);
                break;
                case '/':
                st.push(op1/op2);
                break;
                case '^':
                st.push(pow(op1,op2));
                break;
            }
        }
    }
    return st.top();//there will be one value in the stack and its the result.
}

int main(){
    cout<<prefixEvaluation("-+7*45+20");
    return 0;
}