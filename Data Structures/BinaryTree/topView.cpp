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

void topView(node * root) {
        queue<pair<int,node*>> q;
        q.push(make_pair(0,root));
        map<int,node*> ans;

        for(auto i=q.front();!q.empty();q.pop(),i=q.front()){
            if(!i.second) 
            continue;

            ans.insert(i);
            q.push(make_pair(i.first+1,i.second->right));
            q.push(make_pair(i.first-1,i.second->left));
        }
        for(auto i:ans) cout<<i.second->data<<" ";
    }


int main(){//we connect root to its left and left to its left and left to its right and so on...
    node* root =new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->right->left=new node(6);
    root->left->right=new node(5);
    root->right->right=new node(7);
    topView(root);
    return 0;
}