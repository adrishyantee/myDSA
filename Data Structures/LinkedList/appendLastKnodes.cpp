#include <iostream>
using namespace std;

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
void insertAthead(node* &head,int val){
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


//find the length of the linkedlist
int length(node* &head){
    int l=0;
    node* temp=head;
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    return l;
}

//append k nodes
node* lastkappend(node* &head,int k){
    node* newTail;//taking two nodes one is newTail and one is newHead
    node* newHead;
    node* tail=head;//by tail pointer we will traverse through the linked list

    int l=length(head);//finding the length of the linkedlist
    int count=1;//for getting the position
    k=k%l;//using this if linked list has length less than that of the nodes

    while(tail->next!=NULL){//we traverse with the help of the tail
        if(count==l-k){//we count till we reach l-k pos
        newTail=tail;//shift the tail to this
        }
        if(count==l-k+1){//next one will be our new head
            newHead=tail;//we set the new head
        }
        tail=tail->next;//traversing
        count++;  
    }
    newTail->next=NULL;//after the loop we set the newTail to point to NULL
    tail->next=head;//and the connect the last element's next to the previous head
    return newHead;//we return the newhead
}


int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    display(head);
    display(head);
    node* newhead=lastkappend(head,3);
    display(newhead);

    return 0;
}