//1在中序遍历时使用静态变量保存前驱节点，如果当前节点小于前驱节点，则该树不是BST。代码实现如下：
bool isBST(Node* root)
{
     static Node *prev = NULL;
 
     // 中序遍历这棵树，并保存前驱节点至prev中
     if (root)
     {
          if (!isBST(root->left))
               return false;
 
          // 检测节点值的合法性
          if (prev != NULL && root->key <= prev->key)
               return false;
 
          prev = root;
 
          //右子树
          return isBST(root->right);
     }
 
     return true;
}
//2限定了子树节点的值得范围，从而每个节点只需遍历一次。节点值的初始范围可限定为TNT_MIN以及TNT_MAX
class Solution {
public:
    bool isBSTUtil(TreeNode *root, int min, int max)
{
    if(root == NULL)
        return true;
    if(root->val < min || root->val > max)
        return false;
    return isBSTUtil(root->left, min, root->val - 1) && isBSTUtil(root->right, root->val + 1, max);
}

bool isValidBST(TreeNode *root)
{
    return isBSTUtil(root, INT_MIN, INT_MAX);
}
  
};
