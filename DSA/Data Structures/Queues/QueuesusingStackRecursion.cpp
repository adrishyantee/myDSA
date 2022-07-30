#include <bits/stdc++.h>
#include <stack>
using namespace std;

//queue class is created
class Queue{
    stack<int> s1;

public:
 
    //push operation which adds element to the stack
    void push(int x){
        s1.push(x);
    }

    //function to pop the 1st element which enetered
    void pop(){

        int x = s1.top();//store the top element
        s1.pop();//pop out to get the next element

        if(s1.empty()){//if the stack is empty
            return;//return the front most element
        }
        pop();//store the frontmost element to the peak;
        s1.push(x);//store in the stack in the original order
        return;//returning the frontmost element
    }

    //to get the frontmost element
    int peek(){

        int x = s1.top();//store the top element
        s1.pop();//pop out to get the next element
        if(s1.empty()){
            s1.push(x);//if the stack is empty
            return x;//return the front most element
        }
        int item = peek();//store the frontmost element to the peak;
        s1.push(x);//store in the stack in the original order
        return item;//returning the frontmost element

    }

    //to check if the stack is empty
    bool empty(){
        if(s1.empty())//have to check for both stacks only then its empty
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
    q.push(5);
    q.push(6);
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    return 0;  
}