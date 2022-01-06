class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        if(root==NULL)
        return ans;
        
        queue<pair<Node*, int>> q;
        map<int, Node*> mp;
        q.push({root,0});
        while(!q.empty()){
            mp[q.front().second]= q.front().first;
            if(q.front().first->left!=NULL)
            q.push({q.front().first->left,q.front().second-1});
            if(q.front().first->right!=NULL)
            q.push({q.front().first->right,q.front().second+1});
            q.pop();
        }
        
        for(auto m:mp){
            ans.push_back(m.second->data);
        }
        return ans;
        // Your Code Here
    }
};