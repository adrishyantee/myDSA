/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    string itos(int val){
        ostringstream str1;
	str1 << val;
	string s = str1.str();
    return s;
    }
    int stoi(string s){
    stringstream str(s);
	int x = 0;
	str >> x;
    return x;
    }

    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(root==NULL)
            return "N";
        // we will use a level order traversal and store the string 
        string s="";
        queue<TreeNode*> q;
        q.push(root);
        s+=itos(root->val)+',';
        
        
        while(!q.empty()){
            int size = q.size();
           
            for(int i=0;i<size;i++){
                TreeNode *node = q.front(); 
                q.pop(); 
                if(node->left!=NULL){
                q.push(node->left);
                s+=itos(node->left->val)+',';
                }
                else if(node->left==NULL)
                s+="N,";
                if(node->right!=NULL){
                 q.push(node->right);
                 s+=itos(node->right->val)+',';
                 }
                else if(node->right==NULL)
                s+="N,";
            } 
        }
        cout<<s<<endl;
        return s;  
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data == "N")
            return NULL;
        
        string s=""; 
        int k=0;
        while(data[k]!=',' && k<data.size()){
            s+=data[k];
            k++;
        }
        k++;
        
        TreeNode* root= new TreeNode(stoi(s));
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty() && k<data.size()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* node = q.front(); 
                q.pop();
                
                //for left
                string s="";
                
                while(data[k]!=',' && k<data.size()){
                s+=data[k];
                k++;
                }                
                if(s!="N"){
                    node->left=new TreeNode(stoi(s));
                    q.push(node->left);
                 }
                else if(s=="N")
                node->left=NULL;
                k++;                
                if(k>=data.size())
                    break;
                
                //for right
                s="";
                
                while(data[k]!=',' && k<data.size()){
                s+=data[k];
                k++;
                }                 
                
                
                if(s!="N"){
                node->right=new TreeNode(stoi(s));
                q.push(node->right);
                }
                else if(s=="N")
                node->right=NULL;  
                k++;
                
                if(k>=data.size())
                    break;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));