class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nextptr;
        
        while(curr!=NULL){
            nextptr=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextptr;          
            
        }
        return prev;    
    }
    
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!= NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow; 
    }
    
    
    bool isPalindrome(ListNode* head) {
        if(head==NULL && head->next==NULL)
            return true;
        
        ListNode* slow = middleNode(head);
        slow->next=reverseList(slow->next);
        slow=slow->next;
        
        ListNode* dummy = head;
        while(slow!=NULL){
            if(slow->val!=dummy->val)
                return false;
            
            dummy=dummy->next;
            slow=slow->next;
        }
        return true;
    }
};