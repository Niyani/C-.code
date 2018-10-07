/*
模拟堆栈操作：将原数列依次压栈，栈顶元素与所给出栈队列相比，如果相同则出栈，
如果不同则继续压栈，直到原数列中所有数字压栈完毕。
检测栈中是否为空，若空，说明出栈队列可由原数列进行栈操作得到。否则，说明出栈队列不能由原数列进行栈操作得到。
*/


class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.empty()||popV.empty()||pushV.size()!=popV.size())
            return false;
        stack<int> s;
        int i=0,j=0;
        for(i=0;i<pushV.size();++i)
        {
            s.push(pushV[i]);
            while(!s.empty()&& s.top()==popV[j])
            {
                s.pop();
                ++j;
            }
        }
        if(s.empty())
           return true;
        return false;
    }
};
/////////////////////////////////////////////////////////////////

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size()==0)
            return false;
        vector<int> stack;
        for(int i=0,j=0;i<pushV.size();)
        {
            stack.push_back(pushV[i++]);
            while(j<popV.size() && stack.back()==popV[j])
            {
                stack.pop_back();
                j++;
            }
        }
        return stack.empty();
    }
};
//两种写法
