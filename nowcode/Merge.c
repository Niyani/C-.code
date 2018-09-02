class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* list=NULL;
        if(pHead1==NULL&&pHead2==NULL)
            return NULL;
        if(pHead1==NULL)
            return pHead2;
        if(pHead2==NULL)
            return pHead1;
        if(pHead1->val<pHead2->val)
        {
            list=pHead1;
            list->next=Merge(pHead1->next,pHead2);
        }
        else{
            list=pHead2;
            list->next=Merge(pHead1,pHead2->next);
        }
        return list;
    }
};
