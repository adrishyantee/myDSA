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
    
      TreeNode* build(vector<int>& preorder, vector<int>& inorder,int&index, int start,int end)
    {
        if(start>end)
            return NULL;
        
        int curr=preorder[index];
        index++;
        
        TreeNode* node = new TreeNode(curr);
        
        if(start==end)
            return node;
        
        
        int pos = start; 
        while(inorder[pos] != curr) 
            pos++;
    
        node->left=build(preorder,inorder,index,start,pos-1);
        node->right=build(preorder,inorder,index,pos+1,end);
        
        
        return node;
  
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        vector<int> inorder=preorder;
        sort(inorder.begin(),inorder.end());
         int end=preorder.size()-1;
      int index=0;
      TreeNode* node=build(preorder,inorder,index,0,end);
        return node;
        
    }
};