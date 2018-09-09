class Solution {
public:
     /*其实虽然有一个乘积最小的限制，但是题目要求是排过序的，还是递增排序，所以头尾相加是最快的方法，
     第一组遇到的和sum相等的值就一定是乘积最小的（和相同，差越大，乘积就越小），大了就大值往前移动，小了就小值往后移动，
     一定要注意在中间有一个return，不然就会把所有和为sum的值打印出来。*/
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> tmp;
        int i,j;
        int len=array.size();
        for(i=0,j=len-1;i<len&&j>i;)
        {
            if(array[i]+array[j]==sum)
            {
                tmp.push_back(array[i]);
                tmp.push_back(array[j]);
                return tmp;
            }
            else if(array[i]+array[j]>sum)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return tmp;
    }
};
