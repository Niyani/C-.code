bool verifysquenceofbst(vector<int> sequence)
	{
			if (sequence.empty())
				return false;
			int len = sequence.size();
			vector<int> len_left;
			vector<int> len_right;
			//找到左子树，左子树肯定比根的值小
			int i = 0;
			for (; i < len - 1; i++){
				if (sequence[i] < sequence[len - 1])
					len_left.push_back(sequence[i]);
				else
					break;
			}
			//右子树--右子树的值肯定比根的值大
			for (; i < len - 1; i++){
				if (sequence[i] > sequence[len - 1]){
					len_right.push_back(sequence[i]);
				}
				else
					return false;
			}
			//递归
			bool left = true, right = true;
			if (!len_left.empty())
				left = verifysquenceofbst(len_left);
			if (!len_right.empty())
				right = verifysquenceofbst(len_right);
			return left && right;
 		}	
