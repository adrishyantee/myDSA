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


//inserting a item in the head
void insertAtHead(node* &head,int val){
    node* n=new node(val);//making a node
    node* temp=head;//using a temp node for traversing

    //checking if the head is Null or not
    if (head==NULL){

        n->next=n;//single item points to itself
        head=n;//setting the head to that item
        return;
    }
    //if inserting at head
    while(temp->next!=head){//traversing until we reach at head
        temp=temp->next;
    }
    temp->next=n;//setting the address of the element to be inserted at the last element before head
    n->next=head;//setting the address of head to the inserted element
    head=n;//setting new head to be the inserted element
}


//inserting a item in the tail
void insertAtTail(node* &head, int val){
    node* n=new node(val);//making a node
    node* temp=head;//using a temp node for traversing
    
    //working if there's no element
    if(head==NULL){//using insertion at head
        n->next=n;//single item points to itself
        head=n;//setting the head to that item
        return;
    }
    
    //working for all other cases
    while(temp->next!=head){//traversing to the last element before head
        temp=temp->next;
    }
    temp->next=n;//setting the address of the element to be inserted at the last element before head 
    n->next=head;//setting the address of head to the inserted element
    //not changing the head
    return;
}

//printing the  circular linked list
void display(node* &head){//take the starting head
    node* temp=head;
    do{
        cout<<temp->data<<" ";//print the values
        temp=temp->next;//traverse through the linked list
    }while(temp!=head);//traverse until the head comes
    cout<<endl;
}

//to delete at head
void deleteAtHead(node* &head){
    node* temp=head;
    while(temp->next!=head){//traversing till the end of the list before head
        temp=temp->next;
    }
    node* todelete=head;  // head to be deleted
    temp->next=head->next; //point the lat element to second element
    head=head->next;//update the head

    delete todelete;//to delete and stop memory leak
}

//delete at any random position
void deletion(node* &head, int pos){
    node* temp=head;
    int count=1;//the count of the position

    if(pos==1){//special edge case
    deleteAtHead(head);
    return;
    }
    //traversing till two steps before of the exact position
    while (count!=pos-1){
        temp=temp->next;
        count++;
    }

    node* todelete = temp->next;//contains the position data in temp->next
    temp->next=temp->next->next;//setting the address of next element to the actual item to delete to the item before the item to delete
    delete todelete;//deleting the element to stop memory leak
    return;
}
int main(){
node* head =NULL;
// insertAtHead(head,1);
// insertAtHead(head,2);
// insertAtHead(head,3);
// display(head);
// insertAtHead(head,4);
// display(head);

insertAtTail(head,5);
insertAtTail(head,2);
insertAtTail(head,3);
display(head);
insertAtHead(head,4);
display(head);

deletion(head,10);
display(head);
}