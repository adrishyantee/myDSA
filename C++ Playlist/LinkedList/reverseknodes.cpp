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

node* reverseK(node* &head,int K){
    //using three pointers for the iterative method
    node* prev=NULL;
    node* curr=head;
    node* nextptr;

    int count=0;
    while(curr!=NULL && count<K){
        nextptr=curr->next;//locating the next value
        curr->next=prev;//switching the next and previous terms


        prev=curr;//shifting the previous to current and at last the head will be stored here
        curr=nextptr;//traversing through the linkedlist
        count++;
    }

    if(nextptr!=NULL){//checking the next pointer is Null or not after reversing of the first 2 nodes
    head->next = reverseK(nextptr,K);//using the recursion for the next head
    }
    return prev;//previous will contain the new head
}


int main(){

node* head=NULL; //making an empty linkedlist

insertAtTail(head,1);
insertAtTail(head,2);
insertAtTail(head,3);
display(head);
insertAthead(head,4);
display(head);

int K=2;
node* newhead=reverseK(head,K);
display(newhead);
return 0;
}