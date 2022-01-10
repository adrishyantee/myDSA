//PATH SUM
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return false;
        
        if (root->val == targetSum && root->left ==  NULL && root->right == NULL)
        return true;
        
        return(hasPathSum(root->left,targetSum-root->val)|| hasPathSum(root->right,targetSum-root->val));
    }
};


//property check

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
     if(root==NULL)
     return true;
     if(root->left==NULL && root->right==NULL)
     return true;
     
     bool a = isSumProperty(root->left);
     bool b = isSumProperty(root->right);
     if(a && b)
     {
         if(root->left==NULL && root->data==root->right->data)
         return true;
         if(root->right==NULL && root->data==root->left->data)
         return true;
         if(root->left!=NULL && root->right!=NULL && root->data == root->left->data+root->right->data)
         return true;
         
     }
     return false;// Add your code here
    }
    
};