class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) 
	{
		vector<vector<int> >res;

		if (pRoot == NULL)
			return res;
		queue<TreeNode*>q;
		q.push(pRoot);

		while (!q.empty())
		{
			vector<int>vec;
			const int size = q.size();
			for (int i = 0; i < size; i++)
			{
				TreeNode *tmp = q.front();
				q.pop();
				vec.push_back(tmp->val);

				if (tmp->left != NULL)
					q.push(tmp->left);
				if (tmp->right != NULL)
					q.push(tmp->right);
			}
			res.push_back(vec);
		}
		return res;
	}

};
