vector<int> ds;
void func(Node* node, int level){
    if(node==NULL)
    return;
    
    if(level==ds.size())
    ds.push_back(node->data);
    func(node->left,level+1);
    func(node->right,level+1);
    return;
}
vector<int> leftView(Node *root)
{
  func(root, 0);
  return ds;// Your code here
}