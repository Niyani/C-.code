/*1.rotateArray[mid] >rotateArray[high]:
like：[x,x,x,6,x,x,2]，此时最小数字一定在mid的右边。
low = mid + 1
2.rotateArray[mid] ==rotateArray[high]:
此时最小数字不好判断在mid的右边还是左边。一个个试，high=high-1
或low = low + 1
3.rotateArray[mid] <rotateArray[high]:
like：[x,x,x,4,x,x,6]，此时最小数字一定在mid的左边。
high = mid - 1*/

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int low=0;
        int high=rotateArray.size()-1;
        int mid;
        while(low<high)
        {
            mid=low+(high-low)/2;
            if(rotateArray[mid]>rotateArray[high])
            {
                low=mid+1;
            }
            else if(rotateArray[mid]<rotateArray[low])
            {
                high=mid;
            }
            else
                high=high-1;
        }
        return rotateArray[low];
    }
};
