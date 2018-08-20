class Solution {
public:
    int max_res;
    int maxPathSum(TreeNode *root) {
        max_res=INT_MIN;
        maxSum(root);
        return max_res;
        
    }
    
    int maxSum(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        int leftMaxPath=max(0,maxSum(root->left));
        int rightMaxPath=max(0,maxSum(root->right));
        max_res=max(max_res,root->val+leftMaxPath+rightMaxPath);
        return max(leftMaxPath,rightMaxPath)+(root->val);
    }
};
