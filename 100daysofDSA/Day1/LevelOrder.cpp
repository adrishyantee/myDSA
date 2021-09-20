//this will be done using bfs using queue

#include <bits/stdc++.h>
using namespace std;


class node{//we create a node class

    public:
    int data;
    node* left;
    node* right;

    node(int val){//we define a constructor so that we can set the default values.
        data=val;
        left=NULL;
        right=NULL;
    }
};
void Levelorder(node* &root){//traverse in post order style
    if(root == NULL){
        return;
    }
    queue<node*> q;//make a queue
    q.push(root);//push the root
    q.push(NULL);//and the null to mark first level

    while(!q.empty()){//until que is empty print first element and push its child into the queue
        node* node=q.front();
        q.pop();
        if(node!=NULL){
            cout<<node->data<<" ";
            if(node->left)
            q.push(node->left);
            if(node->right)
            q.push(node->right);
        }
        else if(!q.empty()){//if somehow the queue has 
        // NULL push it back again at the end but when there
        //  will be no elements this wont happen so at last
        //   the loop will end
            q.push(NULL);
        }
    }
    }

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    Levelorder(root);

    return 0;
}