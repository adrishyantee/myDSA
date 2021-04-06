#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};

class Queue{
    node* front;
    node* back;

    public:
    Queue(){
        front=NULL;
        back=NULL;
    }

    void push(int x){
        node* n=new node(x);

        if (front==NULL){
            back=n;
            front=n;
        }
        back->next=n;
        back=n;
    }

    void pop(){
        if(front == NULL){
            cout<<"Queue underflow"<<endl;
        return;
        }

        node* todelete=front;
        front=front->next;
        delete todelete;   
    }

    int peek(){
        if(front == NULL){
            cout<<"Queue is empty"<<endl;
            return -1;
        }

    return front->data;
    }

    bool empty(){
        if(front == NULL){
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