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

    void Preorder(node* &root){//traverse in prorder style
        if(root==NULL)
        return;

        cout<<root->data<<" ";
        Preorder(root->left);
        Preorder(root->right);
    }

//Iterative preorder

    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> ans;
    //     stack<TreeNode*> st;
        
    //     if(root!=NULL)        
    //     st.push(root);
        
    //     while(!st.empty()){
    //         TreeNode* node = st.top();
    //         st.pop();
    //         ans.push_back(node->val);
    //         if(node->right)
    //             st.push(node->right);
    //         if(node->left)
    //             st.push(node->left);
    //         }
    //     return ans;
    // }



int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    Preorder(root);

    return 0;
}