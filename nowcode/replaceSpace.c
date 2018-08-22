class Solution {
public:
	void replaceSpace(char *str,int length) {
        int count=0;
       char *ptr=str;
        while(*ptr!='\0')//得到空格的个数
        {
            if (*ptr==' ')
          {
            count++;
          }
          ptr++;
        }
        int newsize=length+2*count;//替换后的字符串长度
        str[newsize]='\0';//给新字符串末尾设置结束标志，不能省略
        char *end=str+length-1;
        char *finish=str+newsize-1;
        while(end!=finish)
        {
            if(*end!=' ')
            {
                 *finish--=*end--;
            }
            else 
            {
                *finish--='0';
                *finish--='2';
                *finish--='%';
                end--;
            }
        }
	}
};
