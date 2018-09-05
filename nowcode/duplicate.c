/*
1、判断输入数组有无元素非法
2、从头扫到尾，只要当前元素值与下标不同，就做一次判断,numbers[i]与numbers[numbers[i]]，相等就认为找到了
重复元素，返回true,否则就交换两者，继续循环。直到最后还没找到认为没找到重复元素，返回false
*/
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
bool duplicate(int numbers[], int length, int* duplication) {
        if(length<=0||numbers==NULL)
            return false;
        for(int i=0;i<length;++i)
        {
            if(numbers[i]<0||numbers[i]>length+1)
                return false;
        }
        
        for(int j=0;j<length;++j)
        {
            while(numbers[j]!=j)
            {
                if(numbers[j]==numbers[numbers[j]])
                {
                    *duplication=numbers[j];
                    return true;
                }
                int temp=numbers[j];
                numbers[j]=numbers[temp];
                numbers[temp]=temp;
            }
        }
        return false;
    }
};
