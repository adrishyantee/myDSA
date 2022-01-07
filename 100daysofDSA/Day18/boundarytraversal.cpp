class Solution {
public:


    void traversalright(Node* root, stack<int> &s){
        
        if(root==NULL)
        return;
        
        if(root->left==NULL && root->right==NULL)
        return;
        
        s.push(root->data);
        if(root->right!=NULL){
        traversalright(root->right,s);
        }
        else if(root->left!=NULL){
        traversalright(root->left, s);
        }
    }

    void leafnodes(Node* root, vector<int> &ans){
        if(root==NULL)
        return ;
        
        leafnodes(root->left,ans);
        if(root->right==NULL && root->left==NULL)
        {
            ans.push_back(root->data);
            return;
        }
        leafnodes(root->right,ans);
    }

    void traversalleft(Node* root, vector<int> &ans){
        
        if(root==NULL)
        return;
        
        if(root->left==NULL && root->right==NULL)
        return;
        
        ans.push_back(root->data);
        
        if(root->left!=NULL){
        traversalleft(root->left, ans);
        }
        else if(root->right!=NULL){
        traversalleft(root->right, ans);
        }
        
    }
    vector <int> boundary(Node *root)
    {
       vector<int> ans;
       if(root==NULL)
       return ans;
       traversalleft(root, ans);
       leafnodes(root,ans);
       stack <int> s;
       traversalright(root, s);
       while(s.size()>1){
          ans.push_back(s.top());
          s.pop();
      }
       return ans;
      
    }
};