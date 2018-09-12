/*建一个临时数组，第一次循环是奇数就放进去，第二次循环放偶数*/

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int>::iterator it;
        vector<int> array_temp;
 
        for(it=array.begin();it!=array.end();it++)
        {
            if((*it&0x1)==1)
               array_temp.push_back(*it);
            
                
        }
        for(it=array.begin();it!=array.end();it++)
        {
            if((*it&0x1)==0)
               array_temp.push_back(*it);
            
                
        }
        array=array_temp;
        
    }
};
