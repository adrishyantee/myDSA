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


//display elements
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
//make a cycle at a position
void makeCycle(node* &head,int pos){
    node* temp=head;//make a temporary node for traversing
    node* startNode;// to store the node at the given position from where the cycle is to be started
    int count =1;
    while (temp->next!=NULL){
        if(count==pos)//checking the current position if matches then does the following
            startNode=temp;//stores the node from where cycle is to be started

        temp=temp->next;//traversing
        count++;
    }
    temp->next=startNode;//stores the address of the startNode to the last element of the linked list
}

//to detect whether the linkedlist has a cyle
bool detectCycle(node* &head){
    node* slow=head;//a slow pointer going one step
    node* fast=head;//a fast pointer going two steps

    while(fast!=NULL && fast->next!=NULL){//the fast pointer should not be NULL and it must not point to NULL
        slow=slow->next;//goes 1 step
        fast=fast->next->next;// goes two step

        if(fast==slow){//the place where both the pointers reaches at same point
            return true;// returning true for this case
        }
    }
    return false;//else no cycle
}

void removeCycle(node* &head){
    node* slow=head;//a slow pointer going one step
    node* fast=head;//a fast pointer going two steps
    
    do{
        slow=slow->next;//from the head moves one step
        fast=fast->next->next;//from the head moves one step
    }while(slow!=fast);//until both comes at same point

    fast=head;//shift one of the pointers here, fast one to the head
    while(slow->next!=fast->next){
        slow=slow->next;//both the pointers are moved by one step
        fast=fast->next;
    }
    slow->next=NULL;//point the last of the cycle to NULL

}

int main(){

node* head=NULL; //making an empty linkedlist

insertAtTail(head,1);
insertAtTail(head,2);
insertAtTail(head,3);
insertAtTail(head,5);
insertAtTail(head,9);
insertAtTail(head,10);
display(head);
makeCycle(head,2);
cout<<detectCycle(head)<<endl;
removeCycle(head);
cout<<detectCycle(head)<<endl;
display(head);
    return 0;
}