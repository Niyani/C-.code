class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		//二叉树为空，则返回空
		if (pNode == NULL)
			return NULL;
		//节点右孩子存在,一直沿着指向左子结点的指针找到的叶子节点即为下一个节点
		if (pNode->right != NULL)
		{
			pNode = pNode->right;
			while (pNode->left != NULL)
				pNode = pNode->left;
			return pNode;
		}
		//节点不是根节点。如果该节点是其父节点的左孩子，则返回父节点；否则继续向上遍历其父节点的父节点
		while (pNode->next != NULL)
		{
			TreeLinkNode *proot = pNode->next;
			if (proot->left == pNode)
				return proot;
			pNode = pNode->next;
		}
		return NULL;
	}
};
