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

//reversing a linkedlist by ITERATIVE METHOD

node* reverse (node* &head){//getting the head of the linkedlist
   //three pointers to be takn for doing this job
    node* prev=NULL;
    node* curr=head;
    node* nextptr;

    while(curr!=NULL){//running until curr comes to last
        nextptr=curr->next;//locating the next value
        curr->next=prev;//switching the next and previous terms


        prev=curr;//shifting the previous to current and at last the head will be stored here
        curr=nextptr;//traversing through the linkedlist

    }
    return prev;
}

//reversing the linkedlist by RECURSIVE METHOD
node* reverseRec(node* &head){
    //base case where the recursion will terminate
    if( head == NULL || head->next==NULL){
        return head;//return the single or no head
    }
      
    node* newhead = reverseRec(head->next);//using the next head to call the recursion
    head->next->next=head;//pointing the next to next head to the current head
    head->next=NULL;//setting head to NULL
     
     return newhead;
}

int main(){

node* head=NULL; //making an empty linkedlist

insertAtTail(head,1);
insertAtTail(head,2);
insertAtTail(head,3);
display(head);
insertAthead(head,4);
display(head);

node* newhead= reverseRec(head);
display(newhead);


  return 0;
}
