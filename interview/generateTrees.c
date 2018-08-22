class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        return CreateTree(1,n);
    }
    vector<TreeNode*> CreateTree(int start, int end)
    {
        vector<TreeNode*> res;
        if(start>end)
        {
            res.push_back(NULL);
            return res;
        }
//以i作为分界点获取左右两部分的子树集合
        for(int i=start;i<= end;++i)
        {
            vector<TreeNode*> left=CreateTree(start,i-1);
             vector<TreeNode*> right=CreateTree(i+1,end);
            
            for(TreeNode* left:left)
            {
                for(TreeNode* right:right)
                {//构建以i为值的根节点，添加左右子树，添加到结果中
                    TreeNode* root=new TreeNode(i); //i作为根
                    root->left=left;
                    root->right=right;
                    res.emplace_back(root);
                }
            }
        }
        return res;
    }
};
