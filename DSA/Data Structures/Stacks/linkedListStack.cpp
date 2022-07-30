//We have to do the insert and delete from the head to take 0(1)

#include <bits/stdc++.h>
using namespace std;


//make a node class
class node{
    public:
    //these are the attributes given to the class
    int data;
    node* next;

    //make a constructor of the class to pass a value and also store the default
    node(int val){
        data=val;
        next=NULL;
    
    }
};

//to push a value inside a stack
void push(node* &top,int val){
    node* newnode = new node (val);//a node is created
    newnode->next=top;//the newnode is pointed to the top
    top=newnode;//top is pointed to the newnode
}

//to display a stack from top to bottom
void display(node* &top){
    node* temp=top;
    if(top==NULL){//if there is no stack
        cout<<"Empty"<<endl;
        return;
    }
    while(temp!=NULL){//tranversing from the top till bottom
        cout<<temp->data<<" ";//printing the top and then the bottom
        temp=temp->next;
    }
    cout<<endl;
}

//to get the topmost value
int Top(node* &top){
    if(top==NULL){//if the stack is empty
    cout<<"Stack is empty"<<endl;
    return -1;
    }
    return top->data;//print the top data
}

//to pop out the top value
void pop(node* &top){
    node* temp=top;
    if(top==NULL){//if it doesnot have anything
        cout<<"Nothing is there"<<endl;
        return;
    }
    top=top->next;//shift the top
    free(temp);//free the space because its not needed
}

int main(){
    node* top=NULL;
    push(top,2);
    push(top,3);
    push(top,10);
    display(top);
    cout<<Top(top)<<endl;
    pop(top);
    display(top);
}