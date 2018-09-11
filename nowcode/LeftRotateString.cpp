////1
class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(str.length() <= n)
              return str;
        int len = str.size();        
        reverse(str,0,n-1);
        reverse(str,n,len-1);
        reverse(str,0,len-1);
        return str;
    }
    void reverse(string &strstr,int start,int end)
    {
        while(start<end)
        {
            char temp = strstr[start];
            strstr[start] = strstr[end];
            strstr[end] = temp;
            start++;
            end--;
        }
        return;
    }
};
////2
class Solution {
public:
    /*str.substr(pos, n)返回一个字符串，包含s中从下标pos开始的n个字符*/
    string LeftRotateString(string str, int n) {
         int len = str.length();
         if(len <= n) 
              return str;
         n %= len; 
         str += str;
         return str.substr(n,len);
    }
};
