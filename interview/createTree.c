class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.size()==0||postorder.size()==0)
            return NULL;
        if(inorder.size()!=postorder.size())
            return NULL;
        int root_index=-1;
        vector<int> inL,inR,postL,postR;
        int len=postorder.size();
        TreeNode *root=new TreeNode(postorder[len-1]);
        for(int i=0;i<len;i++)
        {
            if(postorder[len-1]==inorder[i])
            {
                root_index=i;
                break;
            }
        }
        
        for(int j=0;j<root_index;j++)
        {
            postL.push_back(postorder[j]);
            inL.push_back(inorder[j]);
        }
        int k=root_index+1;
        for(;k<inorder.size();k++)
        {
            postR.push_back(postorder[k-1]);
            inR.push_back(inorder[k]);
        }
        
        root->left=buildTree(inL,postL);
        root->right=buildTree(inR,postR);
        return root;
    }
};
