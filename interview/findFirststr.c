char FindFirstCharAppearOnce(char* pString)
{
    if (NULL == pString)    //输入不合法
        return 0;
    const int tableSize=256;
    int hashTable[tableSize];
    for (int i = 0; i < tableSize; i++)
         hashTable[i] = 0;
    //从头开始遍历，确定字符串中每个字符出现的次数
    char* pHashKey = pString;
    while (*(pHashKey) != '\0')
        hashTable[*(pHashKey++)]++;
    //找到字符串中只出现一次的那个字符
    pHashKey = pString;
    while (*pHashKey != '\0')
    {
        if (hashTable[*pHashKey] == 1)
            return *pHashKey;
         pHashKey++;
    }
     //如果这个字符串的每个字符都至少出现两次
     return 0;
}
int main()
{
   char* pstring = "abcdab";
   char ret=FindFirstCharAppearOnce(pstring);
   cout << "字符串"<<pstring << "中第一个只出现一次的字符是：";
   cout << ret << endl;
   system("pause");
   return 0;
}
