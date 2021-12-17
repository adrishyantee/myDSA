class Node{
         public:
         int key, val, count;
         Node* prev;
         Node* next;
         Node(int k, int v){
             key=k;
             val=v;
             prev=NULL;
             next=NULL;
             count=1;
            }
        };

class List{
    public:
    int size; 
    Node *head; 
    Node *tail; 
    
    List() {
        head = new Node(0, 0); 
        tail = new Node(0,0); 
        head->next = tail;
        tail->prev = head; 
        size = 0;
    }
    
    void add(Node* address){
        address->next=head->next;
        address->prev=head;
        address->next->prev=address;
        head->next=address; 
        size++;
        
    }
    void sub(Node* address){
        address->next->prev=address->prev;
        address->prev->next=address->next;
        size--;
    }
};
class LFUCache {
public:
         
     map<int,Node*> mp;
     map<int,List*>freq;
     int maxSize;
     int minfreq;
    
     
    
    LFUCache(int capacity) {
    maxSize=capacity;
    minfreq=1;
    }
    
    void updatefreqList(Node* address){
        //delete from previous list add in another list
        freq[address->count]->sub(address);
        (address->count)++;
        if(freq.find(address->count)!=freq.end())
           freq[address->count]->add(address);
        else{
            List* list = new List();
            list->add(address);
            freq.insert({address->count,list});
        }
        if((freq[minfreq]->size)==0){
            minfreq++;
        }
    }
    int get(int key) {
       if(mp.empty())
           return -1;
       else if(mp.find(key)!=mp.end()){
           Node* address = mp[key];
           int value = address->val;

           
           updatefreqList(address); 
           return value;
       }
       else
            return -1;
    }
    
    void put(int key, int value) {
        if(maxSize==0)
            return;
        if(mp.find(key)!=mp.end()){
          Node* address = mp[key];
          address->val = value;
          updatefreqList(address);
        }
         else if(maxSize==mp.size()){
             //get the minifrequency list
           List* list = freq[minfreq];
           Node* address = list->tail->prev;
           //delete from the list
           list->sub(address);
           mp.erase(address->key);
             
           address->key = key;
           address->val = value;
           address->count=1;
           mp.insert({key,address});
           freq[1]->add(address); 
            minfreq=1;
        }
        else{
            Node* address = new Node(key,value);
            mp.insert({key,address});
            List* newlist;
            if(freq.find(1)==freq.end())
            newlist = new List();
            else
            newlist = freq[1];
            newlist->add(address);
            freq.insert({1,newlist});
            minfreq=1;
        }
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */