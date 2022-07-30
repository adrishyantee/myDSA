#include <bits/stdc++.h>
using namespace std;

//we consider the pop operation costly

class Stack{//making a class for stack

    int N;  
    queue<int> q1;//using two queues
    queue<int> q2;

    public:
    Stack(){//stack constructor
        N=0;
    }


    //pushing a data into the stack
    void push(int val){
        q1.push(val);//just putting into one stack
        N++;//increasing the size of the stack

    }

   //for popping out the last data
    void pop(){
        if(q1.empty()){//if the stack is empty
            return;
        }
        while(q1.size() != 1){//until last element we pop out
            q2.push(q1.front());//and keep adding the elements to a different queue
            q1.pop();//popping out
        }

        q1.pop();//after this we have only one element left so we pop out that
        N--;//decrease the size by one

        queue<int> temp=q1;//and transfer all elements to other queue
        q1=q2;
        q2=temp;

    }

    //to get the topmost element from the stack we have to implement the same logic as pop
    int Top(){
        if(q1.empty()){//if stack is empty
            return -1;
        }
        while(q1.size() != 1){
            q2.push(q1.front());
            q1.pop();
        }
        int topval=q1.front();//we reach to the last element which we need to show
        q2.push(topval);//this element is again pushed back to the q2 just like others

        queue<int> temp=q1;//then both of the queues are interchanged
        q1=q2;
        q2=temp;
       
       return topval;
    }

    //returning the size of the stack
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