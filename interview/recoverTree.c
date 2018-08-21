class Solution {
public:
    void recoverTree(TreeNode *root) {
        if(root==NULL)
            return;
        Traverse(root);
        swap(p->val,q->val);
    }
    void Traverse(TreeNode *root)
    {
        if(root==NULL)
            return ;
        Traverse(root->left);
        if(pre&&(pre->val>root->val))
        {
            if(!p)
                p=pre;
            q=root;
        }
        pre=root;
        Traverse(root->right);
    }
private:
    TreeNode *pre=NULL;
    TreeNode *p=NULL;
    TreeNode *q=NULL;
    
};
