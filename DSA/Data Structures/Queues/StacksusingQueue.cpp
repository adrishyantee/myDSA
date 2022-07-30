#include <bits/stdc++.h>
using namespace std;

// the push operation will be costly in this case
class Stack{

    int N;  //making two queues and size
    queue<int> q1;
    queue<int> q2;

    public:
    Stack(){
        N=0;//makes an empty stack.
    }
    
    //the push function which pushes the value into the stack
    void push(int val){

        q2.push(val);//as we push into the q2 first
        N++;//we increase the size by 1

        while(!q1.empty()){//then transfer all the values of q1 to q2 if present
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp=q1;//then we tranfer back all the elements back to q1
        q1=q2;
        q2=temp;
    }

    //this is the pop function to take out the topmost element
    void pop(){
        q1.pop();//q1 will contain the elements in reverse order
        N--;//we will decrease the size by 1
    }

    //to get the topmost value of the stack
    int Top(){
    return q1.front();
    }

    //to get the size of the stack
    int size(){
    return N;
    }

};
int main(){
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.Top()<<endl;
    st.pop();
    st.pop();
    st.pop();
    return 0;
}