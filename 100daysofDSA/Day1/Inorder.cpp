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


    void Inorder(node* &root){//traverse in inorder style
        if(root==NULL)
        return;

        Inorder(root->left);
        cout<<root->data<<" ";
        Inorder(root->right);
    }

    //iterative
        vector<int> inorderTraversal(node* root) {
        vector<int> ans;
        stack<node*> st;
        
       while(!st.empty() || root!=NULL) {
        if(root!=NULL)
        {
            st.push(root);
            root=root->left;
        }
        else{
            node* node=st.top();
            ans.push_back(node->data);
            root=node->right;
            st.pop();
         }
       }
        return ans; 
    }


int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    Inorder(root);


    return 0;
}