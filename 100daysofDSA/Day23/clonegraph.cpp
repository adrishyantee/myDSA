/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    void dfs(Node *node, Node* newhead, vector<Node*> &visited){
        
        visited[newhead->val]=newhead;
        
        
        for(int i=0;i<node->neighbors.size();i++){
        if(visited[node->neighbors[i]->val]==NULL){
                Node* temp = new Node(node->neighbors[i]->val);
                newhead->neighbors.push_back(temp);
                dfs(node->neighbors[i],temp,visited);
                
            }
            else{
                newhead->neighbors.push_back((visited[node->neighbors[i]->val]));
            }
    }
    }
    
    
    
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        
        vector<Node*> visited(101,NULL);
        
        Node* newhead = new Node(node->val);
        visited[node->val]=newhead;
        for(int i=0;i<node->neighbors.size();i++){
            if(visited[node->neighbors[i]->val]==NULL){
                Node* temp = new Node(node->neighbors[i]->val);
                newhead->neighbors.push_back(temp);
                dfs(node->neighbors[i],temp,visited);
                
            }
            else{
                newhead->neighbors.push_back((visited[node->neighbors[i]->val]));
            }
            
        }
        return newhead;
    }
};