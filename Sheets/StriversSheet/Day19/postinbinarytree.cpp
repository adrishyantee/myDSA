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
    
    TreeNode* build(vector<int>& postorder, vector<int>& inorder,int &index,int start,int end)
    {
        if(start>end)
            return NULL;
        int curr=postorder[index];
        index--;
        TreeNode* node=new TreeNode(curr);
        
        if(start==end)
            return node;

        int pos = start; 
        while(inorder[pos] != curr) 
            pos++;
        
        node->right=build(postorder,inorder,index,pos+1,end);
        node->left=build(postorder,inorder,index,start,pos-1);
        return node;
  
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int length=postorder.size();
    int index=length-1;
      TreeNode* node=build(postorder,inorder,index,0,length-1);
        return node;   
    }
};