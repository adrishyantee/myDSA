#include <bits/stdc++.h>
using namespace std;

class node{//make a node class for connecting each node to each other
    public:
    int data;
    node* left;
    node* right;

    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

 int maxLevelSum(node* root) {
      if(root==NULL)
          return 0;
        
        queue<node*>q;
        
        q.push(root);
        q.push(NULL);

        int k=0,level=0;
        int mx=INT_MIN;
        int sum=0;
        
        while(!q.empty()){
            node* node = q.front();
            q.pop(); 
          
            if(node!=NULL){
                sum+=node->data;               
            
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            else if(node==NULL){
                if(sum>mx){
                    mx=sum;
                    k=level+1;
                }
                sum=0;
                level++; 
            if (!q.empty()){
                q.push(NULL);
                } 
            }      
        }
        return k;
    }



int main(){//we connect root to its left and left to its left and lrft to its right and so on...
    node* root =new node(1);
    root->left =new node(2);
    root->right=new node(3);

    cout<<maxLevelSum(root);
    return 0;
}