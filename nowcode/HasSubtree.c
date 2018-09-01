class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        int res=0;
        if(pRoot1!=NULL && pRoot2!=NULL){
            if(pRoot1->val==pRoot2->val){
                 //找到相同结点后判断是否含有相同结构
                res=compare_tree(pRoot1,pRoot2);
            }
            if(!res){//在左子树中查找相同结点
                res=HasSubtree(pRoot1->left,pRoot2);
            }
            if(!res){//在右子树中找相同结点
                res=HasSubtree(pRoot1->right,pRoot2);
            }
        }
        return res;
    }
    //递归判断结构是否相同，直到将pRoot2所有结点完全判断
    bool compare_tree(TreeNode* pRoot1, TreeNode* pRoot2){
          if(pRoot2 == NULL){
              return true;
          }
          if(pRoot1 == NULL){
              return false;
          }
          if(pRoot1->val == pRoot2->val){
             return compare_tree(pRoot1->left,pRoot2->left) && compare_tree(pRoot1->right,pRoot2->right);
          }
        return false;
    }
};
