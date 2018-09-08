class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
     if(data.size()<2)
            return;
        int ans = 0;
        for(int i=0;i<data.size();i++)
            ans ^= data[i];
        int index = splitAtIndex(ans);
        
        for(int i=0; i<data.size();i++)
        {
        	if(isIndexTrue(data[i],index))//分成2组
                *num1 ^= data[i];
            else
                *num2 ^= data[i];
        }
        
    }
    
    int splitAtIndex(int num)//找异或之后这个数字二进制数中最先出现的1的位置
    {
    	int flag = 1;
        int index = 0;
        
        while(!(flag & num))
        {
        	index++;
            flag = flag << 1;
        }
        
        return index;       
    }
    
    bool isIndexTrue(int num,int index)
    {
    	num = num >> index;
        return (num & 1);
    }

};
