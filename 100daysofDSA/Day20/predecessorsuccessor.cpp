void findSuc(Node* root, Node*& suc, int key){
    while(root){
            if(key >= root->key) 
            root = root->right;
            else{
                suc = root;
                root= root->left;
            }
        }
}
void findPre(Node* root, Node*& pre, int key){
    while(root){
            if(key <= root->key) 
            root = root->left;
            else{
                pre = root;
                root= root->right;
            }
        }
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
findPre(root,pre,key);
findSuc(root,suc,key);
}