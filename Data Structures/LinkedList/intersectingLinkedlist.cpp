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

void intersect(node* &head1, node *head2, int pos){
    node* temp1=head1;//making two temporary nodes to traverse
    node* temp2=head2;

    while(pos!=1){//reaching to that position where the same node has to be made for both
        temp1=temp1->next;
        pos--;
    }
    
    while(temp2->next!=NULL){//we traverse till the end of the linked list
        temp2=temp2->next;
    }
    temp2->next=temp1;//at the end we fix the nest to the node where the linkedlist intersects
}

int intersectioncheck(node* &head1, node* &head2){
    int l1=length(head1);//calculating length for both linkedlist
    int l2=length(head2);

    int d=0;//this is the position where both meets
    node* ptr1;//the long linkedlist pointer
    node* ptr2;//the short linkedlist pointer

    if(l1>l2){//if first linkedlist's length is larger
        d=l1-l2;
        ptr1=head1;//set as required
        ptr2=head2;
    }
    else{//if not or if equal to
        d=l2-l1;
        ptr1=head2;//set as required
        ptr2=head1;
    }

    while(d){//we traverse till that many nodes before the intersection point which are same
        ptr1=ptr1->next;//this helps in traversing in the long linkedlist upto same nodes away from intersection point
        if(ptr1==NULL){
            return -1;
        }
        d--;
    }
    
    while(ptr1!=NULL && ptr2!= NULL){//traversing in both the linkedlist
        if(ptr1==ptr2){//when meets
            return ptr1->data;//returning the data
        }
        ptr1=ptr1->next;//both ptr is moving
        ptr2=ptr2->next;
    }
    return -1;//else not found
}


int main(){
    node* head1=NULL;
    node* head2=NULL;

    insertAtTail(head1,1);
    insertAtTail(head1,2);
    insertAtTail(head1,3);
    insertAtTail(head1,4);
    insertAtTail(head1,5);
    insertAtTail(head1,6);
    insertAtTail(head2,11);
    insertAtTail(head2,12);
    intersect(head1, head2,3);
    display(head1);
    display(head2);
    cout<<intersectioncheck(head1,head2)<<endl;

    return 0;
}