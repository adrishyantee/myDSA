/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
       ListNode* dummy=new ListNode(-1);
       dummy->next=head;
       ListNode *fast=dummy, *slow=dummy;
       int k=n;
        while(k--){
            fast=fast->next;
        }
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* todel = slow->next;
        slow->next=slow->next->next;
        delete(todel);
        return dummy->next;
    }
};