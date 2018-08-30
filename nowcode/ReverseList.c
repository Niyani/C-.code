class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
       ListNode* p1=NULL;
       ListNode* p2=pHead;
        ListNode* p3=pHead->next;
        while(p2!=NULL)
        {
            p2->next=p1;
            p1=p2;
            p2=p3;
            if(p3!=NULL)
            {
                p3=p3->next;
            }
        }
        return p1;
    }
};
