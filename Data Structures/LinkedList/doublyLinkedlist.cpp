#include <iostream>
using namespace std;

//make a node class
class node{
    public:
    //these are the attributes given to the class
    int data;
    node* next;
    node* prev;

    //make a constructor of the class to pass a value and also store the default
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

//inserting at head
void insertAtHead(node* &head,int val){
    node* n=new node(val);//making a new node
    n->next=head;//setting the next of new node to head

    if(head!=NULL){//only if the head is not NULL we can set a previous to it
        head->prev=n;
    }

    head=n;//setting the head as the new node
    head->prev=NULL;//setting the previous of the new head to NULL
}

//insertion at Tail
void insertAtTail(node* &head,int val){

    if (head==NULL){//edge case if the doubly linked list is empty
        insertAtHead(head,val);
        return;
    }

    node* n=new node(val);
    node* temp=head;
    //making a temporary node and traversing
    while(temp->next!=NULL){
        temp=temp->next;
    }
    //reaching to the end of the linkedlist
    temp->next=n;//setting the next to new node
    n->prev=temp;//setting the previous of newnode as the previously founded end node
    n->next=NULL;//setting the next of new end to NULL
}

//Displaying the linkedlist
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" -><- ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

//Recursive call for reversing
node* reversedoublylinkedlist(node* &head){//to reverse a doubly linked list
{
    if (head == NULL || head->next == NULL) {
        return head;
    }

    node* nextNode = head->next;//next node is saved
    head->next = head->prev;//a single node's next and previous is interchanged
    node* newHead = reversedoublylinkedlist(nextNode);//recursive call
    nextNode->next = head;//next node's next is set to head
    return newHead;
}
}


//delete the linkedlist at head
void deleteAtHead(node* &head){
    node* todelete=head;
    head=head->next;//head is changed to the next element
    head->prev=NULL; //previous of head is set to NULL

    delete todelete;
}

//deletion of a node at a given position
void deletion(node* &head,int pos){
   
    if(pos==1){//a edge case if the position is 1 then different logic
        deleteAtHead(head);//we will do deletion at head
        return;
    }

    node* temp=head;
    int count=1;
    while(temp!=NULL && count!=pos){//checking the position and traversing until it is reached
        temp=temp->next;
        count++;
    }
    //here it reaches the position
    temp->prev->next=temp->next;//we change the next of the current element's prev to current element's next
    
    if(temp->next!=NULL){//only if the next of current element is not NULL
    temp->next->prev=temp->prev;
    }

    delete temp;
}

int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    display(head);
    insertAtHead(head,6);
    display(head);
    deletion(head,5);
    display(head);
    deletion(head,1);
    display(head);
    deletion(head,4);
    display(head);
    return 0;
}