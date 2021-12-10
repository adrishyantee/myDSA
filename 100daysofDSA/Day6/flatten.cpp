    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //smaller number - l1 and larger as -l2
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode* p1 = (l1->val>l2->val)?l2:l1;
        ListNode* p2 = (l1->val>l2->val)?l1:l2;
        
        ListNode* temp=nullptr, *head = p1;
        while(p1!=NULL && p2!=NULL){
            if(p1->val > p2->val){
            temp->next=p2;              
            ListNode* t=p2;
            p2=p1;
            p1=t;
            }

            else{
             temp=p1;
             p1=p1->next;
            } 
        } 
        if(p1==NULL)
        temp->next=p2;
        else if(p2==NULL)
        temp->next=p1;
        return head;
    }

    ListNode *flatten(ListNode *root){
        ListNode* topvalue = root;
        while(topvalue->next!=NULL){
            ListNode* topvalue = sideways;
            topvaluenext = topvalue->next->next;
            topvalue = mergeTwoLists(topvalue, topvalue->next)
            topvalue->next = topvaluenext;
        }
        return topvalue;
    }