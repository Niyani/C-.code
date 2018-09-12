
//1暴力求解

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int i=0;
        int count=0;
        for(;i<=n;++i)
        {
           int temp = i;
        //如果temp的任意位为1则count++
           while(temp!=0)
           {
              if(temp%10 == 1)
              {
                  count++;
              }
            temp /= 10;
           }
        }
        return count;
    }
};
//2.
/*取第 i 位左边（高位）的数字，乘以 10i−1，得到基础值 a。
取第 i 位数字，计算修正值： 
如果大于 X，则结果为 a+10i−1。
如果小于 X，则结果为 a。
如果等于 X，则取第 i 位右边（低位）数字，设为 b，最后结果为 a+b+1。*/
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
      int count = 0;
      for (int i = 1; i <= n; i *= 10) {
        int a = n / i,b = n % i;
        //之所以补8，是因为当百位为0，则a/10==(a+8)/10，
        //当百位>=2，补8会产生进位位，效果等同于(a/10+1)
        count += (a + 8) / 10 * i + ((a % 10 == 1) ? b + 1 : 0);
      }
     return count;
    }
};
