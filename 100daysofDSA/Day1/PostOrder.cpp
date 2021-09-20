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

    void Postorder(node* &root){//traverse in post order style
        if(root==NULL)
        return;

        Postorder(root->left);
        Postorder(root->right);
        cout<<root->data<<" ";
    }

    //iterative process
    //     vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> ans;
    //     stack<TreeNode*> st;
    //     TreeNode* last = NULL;
        
    //     while(root!=NULL || !st.empty()){
            
    //         if(root!=NULL){
    //             st.push(root);
    //             root=root->left;
    //         }
    //         else{
    //             TreeNode* node = st.top();
    //             if(node->right!=NULL && last != node->right){
    //                root=node->right;
    //             }
    //             else{
    //                 ans.push_back(node->val);
    //                 last=node;
    //                 st.pop();
    //             }
    //         }
    //     }
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
    Postorder(root);

    return 0;
}