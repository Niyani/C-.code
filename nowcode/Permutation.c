class Solution {
public:
    vector<string> Permutation(string str) 
    {
        vector<string> result;   //创建字符串数组
        int len = str.length();  //求出字符串长度，作为参数传递控制循环次数
        if(!len) 
            return result;  //当输入为空时，直接返回
        Permutations(result, str, 0, len);
        return result;
    }
    
    void Permutations(vector<string>&result, string str,int index, int len)
    {
     //当索引指向字符串尾部时，将str压入数组   
     if (index == len){ 
            result.push_back(str);
            return;
        }
        for (int i = index; i < len; ++i) {
            if (i!=index && str[i]== str[index]) 
                continue;// 保证当输入多个重复字符时，不会重复计算
            swap(str[i],str[index]);//每一次，交换从第index位以后的一个元素
            Permutations(result, str, index+1, len);
        }
    }
};
