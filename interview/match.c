class Solution {
public:
    bool match(char* str, char* pattern)
    {
    if(str==NULL||pattern==NULL)
        return false;
     return matchcore(str,pattern);
    }
    bool matchcore(char* str,char* pattern)
    {//有效性检验：str到尾，pattern到尾，匹配成功
        if(*str=='\0'&&*pattern=='\0')
            return true;
        //pattern先到尾，匹配失败
        if(*str!='\0'&&*pattern=='\0')
            return false;
        if(*(pattern+1)=='*')
        {
            if(*str==*pattern||(*pattern=='.'&&*str!='\0'))
                return matchcore(str+1,pattern)||matchcore(str,pattern+2);
            else
                return matchcore(str,pattern+2);
        }
        if(*str==*pattern||(*pattern=='.'&&*str!='\0'))
            return matchcore(str+1,pattern+1);
        return false;
    }
};
