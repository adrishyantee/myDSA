/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->val == val)
       return root;
   
    // Key is greater than root's key
    if (root->val < val)
       return searchBST(root->right, val);

    // Key is smaller than root's key
    return searchBST(root->left, val); 
    }
};