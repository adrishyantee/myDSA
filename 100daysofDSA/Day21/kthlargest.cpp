class Solution
{
    public:
    int kthLargest(Node *root, int K)
    {
      stack<Node*> st; 
        Node* node = root;
        vector<int> inorder; 
        while(true) {
            if(node != NULL) {
                st.push(node); 
                node = node->left; 
            }
            else {
    
                if(st.empty() == true) 
                    break; 
                node = st.top(); 
                st.pop(); 
                inorder.push_back(node->data); 
                node = node->right; 
            }  
        }
        return (inorder[inorder.size()-1-K+1]);
    }
};