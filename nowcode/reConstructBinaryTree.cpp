class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
     int len = vin.size();
        if(len == 0){
            return NULL;
        }
        vector<int> left_pre, right_pre;
        vector<int> left_in, right_in;
        TreeNode *root = new TreeNode(pre[0]);
        int index =-1;
        for(int i=0; i<len; i++){
            if(vin[i] == pre[0]){
                index = i;
                break;
            }
        }
         
        for(int i=0; i<index; i++){
            left_pre.push_back(pre[i+1]);
            left_in.push_back(vin[i]);
        }
        for(int i=index+1; i<len; i++){
            right_pre.push_back(pre[i]);
            right_in.push_back(vin[i]);
        }
         
        //TreeNode* root = new TreeNode(pre[0]);
        root->left = reConstructBinaryTree(left_pre, left_in);
        root->right = reConstructBinaryTree(right_pre, right_in);       
         
        return root;
    }
};
