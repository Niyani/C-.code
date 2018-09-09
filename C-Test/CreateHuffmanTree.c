using namespace std;
template<class W>
struct HuffmanTreeNode
{
	HuffmanTreeNode(const W& weight = W())
	:_pLeft(0)
	, _pRight(0)
	, _pParent(0)
	, _weight(weight)
	{}

	HuffmanTreeNode<W>* _pLeft;
	HuffmanTreeNode<W>* _pRight;
	HuffmanTreeNode<W>* _pParent;
	W _weight;
};
template<class W>
class HuffmanTree
{
	typedef HuffmanTreeNode<W> Node;
public:
	HuffmanTree()
		:_root(NULL)
	{ }


	//仿函数
	struct NodeComp
	{
		bool operator()(const Node* l, const Node* r)
		{
			return l->_weight > r->_weight;
		}
	};

	void CreateTree(const W* w, size_t n, const W& invalid)
	{
		//构建Huffman树
		assert(w);
		priority_queue<Node*, vector<Node*>, NodeComp> minHeap;
		for (size_t i = 0; i < n; ++i)
		{
			if (w[i] != invalid)
			{
				Node* node = new Node(w[i]);
				minHeap.push(node);
			}
				
		}
		while (minHeap.size()>1)
		{
			Node* left = minHeap.top();
			minHeap.pop();
			Node* right = minHeap.top();
			minHeap.pop();

			Node* parent = new Node(left->_weight + right->_weight);
			parent->_pLeft = left;
			parent->_pRight = right;
			left->_pParent = parent;
			right->_pParent = parent;
			minHeap.push(parent);
		}
		_root = minHeap.top();

	}

	~HuffmanTree()
	{
		//释放树的空间
		Destroy(_root);
		_root = NULL;
	}
private:
	void Destroy(Node* root)
	{
		if (root == NULL)
			return;
		Destroy(root->_pLeft);
		Destroy(root->_pRight);
		delete root;
		root = NULL;
	}
	Node* GetRootNode()
	{
		return _root;
	}


private:
	Node* _root;
};
