class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode* pFast=pListHead;
        ListNode *pSlow=pListHead;
        if(pListHead==NULL||k<0)
           return NULL;
        while(k--)
        {
            if(pFast==NULL)
                return NULL;
            pFast=pFast->next;
        }
        while(pFast)
        {
            pFast=pFast->next;
            pSlow=pSlow->next;
        }
        return pSlow;
    }
};
