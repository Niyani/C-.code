class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> array;
        ListNode *pNode=head;
        while(pNode)
        {
            array.push_back(pNode->val);
            pNode=pNode->next;
        }
        reverse(array.begin(),array.end());
        return array;
        
    }
};
