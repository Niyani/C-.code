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
//////////////////////////////////////////////////////
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
       if(pHead==NULL)
            return NULL;
        ListNode* pRe=NULL;
        ListNode* pNext=NULL;
        while(pHead!=NULL)
        {
            //先用next保存head的下一个节点的信息，保证单链表不会因为失去head节点的原next节点而就此断裂
            pNext=pHead->next;
            //保存完next，就可以让head从指向next变成指向pre了
            pHead->next=pRe;
             //head指向pre后，就继续依次反转下一个节点
            //让pre，head，next依次向后移动一个节点，继续下一次的指针反转
            pRe=pHead;
            pHead=pNext;
        }
        return pRe;
    }
};
