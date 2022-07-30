#include <bits/stdc++.h>
using namespace std;

class Treenode{
    public:
    int val;
    Treenode* left;
    Treenode* right;

Treenode(int data){
    val=data;
    left=NULL;
    right=NULL;
}
};


class Solution {
public:
    vector<int> preorderTraversal(Treenode* root) {
        vector<int> nodes;
        while (root) {
            if (root -> left) {
                Treenode* pre = root -> left;
                while (pre -> right && pre -> right != root) {
                    pre = pre -> right;
                }
                if (!pre -> right) {
                    pre -> right = root;
                    nodes.push_back(root -> val);
                    root = root -> left;
                } else {
                    pre -> right = NULL;
                    root = root -> right;
                }
            } else {
                nodes.push_back(root -> val);
                root = root -> right;
            }
        }
        return nodes;
    }
};

    int main(){
       Treenode* root = new Treenode(1);
       root->left = new Treenode(2);
       root->right = new Treenode(3);

       Solution sol;

       vector<int> ans = sol.preorderTraversal(root);

       for(int i:ans)
       cout<<i<<endl;
        return 0;
    }