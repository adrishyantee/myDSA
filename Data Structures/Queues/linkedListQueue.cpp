#include <bits/stdc++.h>
using namespace std;

class node{//make a node class just like linkedlist
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};

class Queue{//we also make a class queue to use
    node* front;
    node* back;

    public:
    Queue(){//we set the constructor
        front=NULL;
        back=NULL;
    }

    //for pushing a data
    void push(int x){
        node* n=new node(x);//making a new node

        if (front==NULL){//if front is NULL we set them to new node
            back=n;
            front=n;
        }
        back->next=n;//else we change the back only and keep on changing
        back=n;
    }

    //the pop operation
    void pop(){
        if(front == NULL){//if queue is empty
            cout<<"Queue underflow"<<endl;
        return;
        }

        node* todelete=front;//we store the 1st element
        front=front->next;//change the front pointer
        delete todelete;  //freeing the space 
    }

    //to get the data at the front
    int peek(){
        if(front == NULL){//if queue is empty
            cout<<"Queue is empty"<<endl;
            return -1;
        }

    return front->data;//return the data at the front node
    }

    //checking if the queue is empty
    bool empty(){
        if(front == NULL){//if front points to NULL the linkedlist is empty
            return true;
        }
        return false;
    }
};

int main(){
    Queue q;
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);

    q.pop();
    q.pop();
    q.pop();

    cout<<q.peek()<<endl;

    q.pop();
    q.pop();
    
    cout<<q.empty()<<endl;

}