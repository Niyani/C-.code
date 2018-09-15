/*
出现的字符 和 它的出现的次数 是一种对应关系，自然联想到 哈希表的 key-value 这种对应，或者应用关联容器 map，可以很方便的解决这个问题。

map 容器中，它的一个元素 就是一组（key，value）对应的数据
*/
class Solution
{
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
         vec.push_back(ch);
        mapdata[ch]++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
    vector<int>::iterator it;
        for(it=vec.begin();it!=vec.end();it++)
        {
            if(mapdata[*it]==1)
                return *it;
        }
        return '#';
    }
    map<char,int>mapdata;
    vector<int> vec;

};
