class Solution {
public:
    stack<int> mystack, min_stack;
public:
    void push(int value) {
        mystack.push(value);
        if(min_stack.size()==0)
        {
            min_stack.push(value);
        }
        if(value<min_stack.top())
        {
            min_stack.push(value);
        }
    }
    void pop() {
        if(mystack.top()==min_stack.top())
        {
            mystack.pop();
            min_stack.pop();
        }
        else{
            mystack.pop();
        }
    }
    int top() {
        return mystack.top();
    }
    int min() {
        return min_stack.top();
    }
};
