class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
       vector<int> ans;
        if(root==NULL)
        return ans;
        
        queue<pair<Node*, int>> q;
        map<int, Node*> mp;
        q.push({root,0});
        while(!q.empty()){
            if(mp.find(q.front().second)==mp.end())
            mp[q.front().second] = q.front().first;
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
      //Your code here
    }

};