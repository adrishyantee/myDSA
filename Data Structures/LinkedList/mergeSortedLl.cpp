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

//merging two already sorted linkedlist
node* merge(node* &head1,node* &head2){//two linkedlist already sorted is passed

    node* p1=head1;//we take two pointers
    node* p2=head2;

    node* dummyNode=new node(-1);//we set a dummy node from where third ointer will begin
    node* p3 = dummyNode;

    while(p1!=NULL && p2!=NULL){//we traverse till the end
        if(p1->data<p2->data){//if the data in 1st linked list is larger
            p3->next=p1;//we point the third pointer to 1st
            p1=p1->next;

        }
        else{//in this case just the opposite of previous
            p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;//the third pointer is repeatedly moved in each iteration
    }

    while(p1!=NULL){//if one doesnot become null we point the third pointer to that pointer
        p3->next=p1;
        p1=p1->next;
        p3=p3->next;
    }
     while(p2!=NULL){//same for the other
        p3->next=p2;
        p2=p2->next;
        p3=p3->next;
    }

    return dummyNode->next;//we return from the next of the dummy linked list
}


//recursive way to merge two sorted linkedlist
node* mergeRecursive(node* &head1,node* &head2){

    if(head1==NULL){//test case to terminate recursive call
        return head2;
    }

    if(head2==NULL){//same for another one
        return head1;
    }

    node* result;//head of the small linkedlists formed from each recursive call are stored in result
    if(head1->data < head2->data){//for placing the element in current position depending on their value if data in 1st linked list is more
        result=head1;//starting from first linked list
        result->next=mergeRecursive(head1->next,head2);//calling again and again
    }
    else{//just the opposite case
        result=head2;
        result->next=mergeRecursive(head1,head2->next);
    }
    return result;//returning the head of the new joined linked list formed
}



int main(){

node* head1=NULL; //making an empty linkedlist
node* head2=NULL;
int arr[5]={1,3,4,6,7};
int brr[2]={2,5};
for (int i=0;i<5;i++){
insertAtTail(head1,arr[i]);
}
for(int i=0;i<2;i++){
insertAtTail(head2,brr[i]);
}
display(head1);
display(head2);
node* newhead=mergeRecursive(head1,head2);
display(newhead);
    return 0;
}
