//1
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
//2
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> array;
        ListNode *pNode=head;

      if(pNode != NULL)
        {
            array.insert(array.begin(),head->val);
            if(head->next != NULL)
            {
                vector<int> tempVec = printListFromTailToHead(head->next);
                if(tempVec.size()>0)
                array.insert(array.begin(),tempVec.begin(),tempVec.end());  
            }         
             
        }
        return array;    
        
    }
};
