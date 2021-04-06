#include <bits/stdc++.h>
#include <stack>
using namespace std;

//queue class is created
class Queue{
    stack<int> s1;
    stack<int> s2;
public:
 
    //push operation which adds element to the stack
    void push(int x){
        s1.push(x);
    }

    //function to pop the 1st element which enetered
    void pop(){
        if(s1.empty() && s2.empty()){//if stacks are empty
            cout<<"Queue is empty\n";
            return;
        }

        if(s2.empty()){//checking whether the stack 2 is empty
            while(!s1.empty()){//if not traversing until stack 1 is empty
                s2.push(s1.top());//pushing the top of st 1 to stack 2 so as to reverse
                s1.pop();
            }
        }
        s2.pop();//the top element will be the front most element in the queue

        while(!s2.empty()){//reentering all the lements of stack 2 back to 1
                s1.push(s2.top());
                s2.pop();
            }
    }

    //to get the frontmost element
    int peek(){
        if(s1.empty() && s2.empty()){//if stacks are empty
            cout<<"Queue is empty\n";
            return -1;
        }

        if(s2.empty()){//checking whether the stack 2 is empty
            while(!s1.empty()){//if not traversing until stack 1 is empty
                s2.push(s1.top());//pushing the top of st 1 to stack 2 so as to reverse
                s1.pop();
            }
        }
        int topval= s2.top();
        return topval;//the top element will be the front most element in the queue

       while(!s2.empty()){//reentering all the lements of stack 2 back to 1
                s1.push(s2.top());
                s2.pop();
            }
    }

    //to check if the stack is empty
    bool empty(){
        if(s1.empty() && s2.empty())//have to check for both stacks only then its empty
        return true;
        else
        return false;
    }
};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    return 0;  
}