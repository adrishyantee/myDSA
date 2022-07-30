class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return NULL;
        Node* temp =head;
        //step 1 link to the new nodes
        while(temp!=NULL){
            Node* dummy = new Node(temp->val);
            dummy->next = temp->next;
            temp->next=dummy;            
            temp=temp->next->next;
        }
        
        //step 2 link to the randoms
        Node* it = head;
        while(it!=NULL){
            it->next->random=it->random==NULL? NULL:it->random->next ;
            it=it->next->next;
        }
        //step 3 reorder the links
        Node* dummy = head->next;
        Node* newhead = dummy;
        Node* p1=head, *p2=head->next->next;
        while(true){
            p1->next=p2;
            if(p2==NULL)
                break;
            dummy->next=p2->next;
            p1=p1->next;
            p2=p2->next->next;
            dummy=dummy->next;
        }
        return newhead;
    }
};