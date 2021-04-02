#include <bits/stdc++.h>
using namespace std;

#define n 100 //we are redefining a length of the array stack

class Stack{
    int* arr; //we are using pointer to the array
    int top; //we will use this to keep the index of the top element

    public:

    Stack(){// this is the stack constructor
        arr=new int[n];//an array is created dynamically
        top=-1;//index of top set to -1
    }

    void push(int x){//this function helps to push an element inside the array used as a stack
        if(top==n-1){//checking if top reaches the end of the array
            cout<<"Stack Overflow"<<endl;
        }
        top++;//if not then move it to the top of the stack
        arr[top]=x;//enter the element at the top
    }

    void pop(){// this function is to remove the top element of the stack
               //  though it doesnot work like that but shifts the top index to the previous index of it
        if (top==-1){//if the stack is empty
            cout<<"No element to pop"<<endl;
            return;
        }
        top--;
    }
    int Top(){// this shows the topmost element of the stack
        if(top==-1){
            cout<<"No element found"<<endl;
            return -1;
        }
        return arr [top];

    }
    bool empty(){//checks if the stack is empty
        return top==-1;
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
    cout<<st.empty()<<endl;

    return 0;
}