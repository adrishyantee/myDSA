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
    vector<vector<int>> verticalTraversal(TreeNode* root)
{
       vector<vector<int>> ans;
        if(root==NULL)
        return ans;
        
        queue<pair<TreeNode*, pair<int, int>>> q;
        map<int,map<int,multiset<int>>> mp;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto it = q.front();
            int row = it.second.first;
            int col = it.second.second;
            mp[col][row].insert(it.first->val);
            if(it.first->left!=NULL)
            q.push({it.first->left,{row+1,col-1}});
            if(it.first->right!=NULL)
            q.push({it.first->right,{row+1,col+1}});
            q.pop();
        }
        
        for(auto m:mp){
            vector<int> val;
            for(auto l:m.second){
                for(auto mul:l.second)
                val.push_back(mul);
            }
            ans.push_back(val);
        }
        return ans;
    }
};