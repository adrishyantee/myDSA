class Solution {
public:
    bool hasCycle(ListNode *head) {
   ListNode* slow=head;//a slow pointer going one step
   ListNode* fast=head;//a fast pointer going two steps

    while(fast!=NULL && fast->next!=NULL){//the fast pointer should not be NULL and it must not point to NULL
        slow=slow->next;//goes 1 step
        fast=fast->next->next;// goes two step

        if(fast==slow){//the place where both the pointers reaches at same point
            return true;// returning true for this case
        }
    }
    return false;//else no cycle
}
};