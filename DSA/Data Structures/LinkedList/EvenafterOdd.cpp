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

//putting all even integers after odds in a series of consecutive numbers
void evenAfterOdd(node* &head){//getting the head of the linked list which starts from an odd integer
    node* odd=head;//start
    node* even=head->next;//the second is an even
    node* evenStart=even;//the first even number found

    while(odd->next!=NULL && even->next!=NULL){//traversing till the end of the linkedlist
        odd->next=even->next;//the odds are linked to odds skipping the evens
        odd=odd->next;//traversing
        even->next=odd->next;//evens are linked to evens skipping odds
        even=even->next;//traversing
    }
    if(odd->next==NULL){//if the odd points to null 
        even->next=NULL;//point the end of evens to NULL
    }
    odd->next=evenStart;//point the end of odd to start of even
}


int main(){

node* head=NULL; //making an empty linkedlist

insertAtTail(head,1);
insertAtTail(head,2);
insertAtTail(head,3);
insertAtTail(head,4);
insertAtTail(head,5);
insertAtTail(head,6);
display(head);
evenAfterOdd(head);
display(head);
    return 0;
}
