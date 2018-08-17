class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
       if(pRoot==NULL)
            return true;
       return IsMirror(pRoot->left,pRoot->right);
    }
    bool IsMirror(TreeNode *pLeft,TreeNode *pRight)
    {
        if(pLeft==NULL&&pRight==NULL)
            return true;
        if(pLeft==NULL||pRight==NULL)
            return false;
        if(pLeft->val!=pRight->val)
            return false;
        return (IsMirror(pLeft->left,pRight->right))&&(IsMirror(pLeft->right,pRight->left));
    }

};
