class Solution {
public:
     int  NumberOf1(int n) {
         int num=1;
         int count=0;
         while(num!=0)
         {
            if((num&n)!=0)
            {
                 count++;
            }
            num<<=1;
         }
         return count;
     }
};
