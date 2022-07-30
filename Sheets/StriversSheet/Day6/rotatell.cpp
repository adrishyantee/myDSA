class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
            return NULL;
        
        int n=0; 
        ListNode* len = head;
        while(len!=NULL){
            len=len->next;
            n++;
        }
        k=k%n;
        ListNode* temp = new ListNode(-1);
        ListNode* tracker = new ListNode(-1);
        temp->next=head;
        tracker->next=head;
        while(k--){
            temp=temp->next;
        }
        while(temp->next!=NULL){
            tracker=tracker->next;
            temp=temp->next;
        }
        //tracker will have the head
        temp->next = head;
        ListNode* newhead = tracker->next;
        tracker->next = NULL;
        return  newhead;
    }
};