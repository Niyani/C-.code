struct FileInfo
{
	FileInfo(unsigned char ch=0)
		:_ch(ch)
		, _count(0)
	{}

	FileInfo operator+(FileInfo& f)
	{
		FileInfo tmp(*this);
		tmp._count = this->_count + f._count;
		return tmp;
	}

	bool operator >(const FileInfo& f)const
	{
		return this->_count > f._count;
	}
	bool operator !=(const FileInfo& f) const
	{
		return this->_count != f._count;
	}
	
	unsigned char _ch;//有效字符
	long long _count;//字符出现的次数
	string _code;//字符的编码
};

template<class W>
class FileCompress
{
public:
	FileCompress()
	{
		for (int i = 0; i < 256; i++)
		{
			_info[i]._ch = i;
			_info[i]._count = 0;
		}
	}

	bool Compress(const char* filename)
	{
		//打开文件，统计文件字符出现的次数
		long long charCount = 0;
		assert(filename);
		FILE* fin = fopen(filename, "rb");
		assert(fin);

		char* ch = new char[1024];
		while (1)
		{
			size_t readSize = fread(ch, 1, 1024, fin);
			if (0 == readSize)
				break;
			for (size_t i = 0; i < readSize; ++i)
			{
				_info[ch[i]]._count++;
				charCount++;
			}
		}

		//生成对应的huffman 编码
		CreateHuffmanCode();
		
		FILE* fwout = fopen("File.hzp", "w");
		assert(fwout);
		//压缩之前写解压缩需要用到的信息
		WriteComFileHead(fwout, filename);

		//压缩文件---用每个字符的编码重新改写文件
		fseek(fin, 0, SEEK_SET);
		char in = 0;
		int index = 0;
		char* fwCompress = new char[1024];
		int writeSize = 0;
		for (;;)
		{
			size_t readSize = fread(ch, 1, 1024, fin);
			if (0 == readSize)
				break;
			
			for (size_t i = 0; i < readSize; ++i)
			{
				string& code = _info[ch[i]]._code;
				for (size_t j = 0; j < code.length(); ++j)
				{
					in = in << 1;
					if (code[j] == '1')
					{
						in |= 1;
					}
					if (++index == 8)
					{
						fwCompress[writeSize++] = in;
						if (writeSize == 1024)
						{
							fwrite(fwCompress, 1, 1024, fwout);
							writeSize = 0;
						}
						in = 0;
						index = 0;
					}
				}

			}
		}
		if (index<8&&index>0)
		{
			in = in << (8 - index);
			fwCompress[writeSize++] = in;
		}
		fwrite(fwCompress, 1, writeSize, fwout);
		fclose(fin);
		fclose(fwout);

		delete[] ch;
		delete[] fwCompress;
		return true;

	}

	void CreateHuffmanCode()
	{
		HuffmanTree<FileInfo> hft;
		FileInfo invalid;
		hft.CreateTree(_info, 256, invalid);//建huffman树
		_CreateHuffmanCode(hft.GetRootNode());//得到huffman 编码
	}

	void _CreateHuffmanCode(HuffmanTreeNode<FileInfo>* root)
	{
		if (root == NULL)
			return;
		_CreateHuffmanCode(root->_pLeft);
		_CreateHuffmanCode(root->_pRight);

		if (root->_pLeft == NULL&&root->_pRight == NULL)
		{
			HuffmanTreeNode<FileInfo>* cur = root;
			HuffmanTreeNode<FileInfo>* parent = cur->_pParent;
			string& code = _info[cur->_weight._ch]._code;
			while (parent)
			{
				if (parent->_pLeft == cur)
				{
					code += '0';
				}
				else if (parent->_pRight == cur)
				{
					code += '1';
				}
				cur = parent;
				parent = cur->_pParent;
			}
			reverse(code.begin(), code.end());
		}
	}
