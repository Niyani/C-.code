class Solution {
public:
	int evalRPN(vector<string> &tokens) 
	{
		stack<int>store;
		for (auto x : tokens)
		{
			if (x == "+" || x == "-" || x == "*" || x == "/")
			{
				if (store.size() < 2)
				{
					return 0;
				}
				int a = store.top();
				store.pop();
				int b = store.top();
				store.pop();
				int c = 0;
				if (x == "+")
					c = b + a;
				else if (x == "-")
					c = b - a;
				else if (x == "*")
					c = b*a;
				else if (x == "/")
					c = b / a;
				store.push(c);
			}
			else
			{
				store.push(atoi(x.c_str()));
			}
		}
		return store.top();
	}
};
