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
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head=l1, *temp=nullptr;
    int carry=0;
    while(l1!=NULL && l2!=NULL){
       int sum=(l1->val+l2->val+carry);
        l1->val=sum%10;;
        carry=sum/10;
        temp=l1;
        l1=l1->next;
        l2=l2->next;
    }
    if(l1==NULL && l2!=NULL){
        temp->next=l2;
    }
      
    while(l1!=NULL){
        int sum=(l1->val+carry);
        l1->val=sum%10;
        carry=sum/10;
         temp=l1;
        l1=l1->next;
      
    }
    while(l2!=NULL){
        int sum=(l2->val+carry);
        l2->val=sum%10;
        carry=sum/10;
         temp=l2;
        l2=l2->next;
      
    }
    if(carry>0){
        ListNode* last = new ListNode(-1);
        last->val=carry;
        temp->next=last;
        last->next=NULL;
    }
    return head;
  }
};