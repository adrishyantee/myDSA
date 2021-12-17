class LRUCache {
public:
     class Node{
         public:
         int key, val;
         Node* prev;
         Node* next;
         Node(int k, int v){
             key=k;
             val=v;
             prev=NULL;
             next=NULL;
            }
        };
    
       Node* head = new Node(-1,-1);
       Node* tail = new Node(-1,-1);
       map<int,Node*> mp;
    
       int size=0;
       LRUCache(int capacity) {
        size = capacity;  
        tail->prev=head;
        head->next=tail;
        }     
      void deleteNodeandInsertatfirst(Node* address){
         //remove
        address->prev->next=address->next;
        address->next->prev=address->prev;
         //add in front make it MLU
        address->next=head->next;
        address->prev=head;
        address->next->prev=address;
        head->next=address;  
      }
    
     int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;
        Node* address = mp[key];
        int value = address->val;
        deleteNodeandInsertatfirst(address);
         return value;
    }
    
    void put(int key, int value) {
       if(mp.find(key)!=mp.end()){
          Node* address = mp[key];
          address->val = value;
       deleteNodeandInsertatfirst(address);
        }
       else if(size==mp.size()){
           Node* address = tail->prev;
           mp.erase(address->key);
           address->key = key;
           address->val = value;
           mp.insert({key,address});
       deleteNodeandInsertatfirst(address);
        }
        else{
            Node* address = new Node(key,value);
            mp.insert({key,address});
            address->next=head->next;
            address->prev=head;
            address->next->prev=address;
            head->next=address; 
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */