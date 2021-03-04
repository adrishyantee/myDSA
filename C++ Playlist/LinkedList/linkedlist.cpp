#include <iostream>
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

//insertion at head
void insertAthead (node* &head,int val){
    node* n=new node(val);
    n->next=head;
    head=n;
}

//insertion at tail
void insertAtTail (node* &head, int val){
    node* n=new node(val);

//creating temporary memory to take and traverse
    node* temp=head;

//checking for empty linkedlist
    if (head==NULL){
        head=n;
        return;
    }
//traversing till last
    while (temp->next!=NULL){
        temp=temp->next;
    }
    temp -> next=n;//inserting at tail
}

void display(node* head){
    node* temp =head;
    //traversing till the end
    while (temp!=NULL){
        //taking a traversing element and printing the data for that particular node
        cout<<temp->data<<"--> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
//searching through the linked list
bool search(node* head,int key){
node* temp= head;
while(temp!=NULL){
    //traversing through the linked list
    if(temp->data==key){//checking for equality
        return true;
    }
    temp=temp->next;
    //switching to next element
}
return false;
}
int main(){

node* head=NULL; //making an empty linkedlist

insertAtTail(head,1);
insertAtTail(head,2);
insertAtTail(head,3);
display(head);
insertAthead(head,4);
cout<<search(head,0)<<endl;
display(head);
    return 0;
}