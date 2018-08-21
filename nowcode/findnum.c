class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
       int row=array.size();
        int col=array[0].size();
        
        for(int i=row-1,j=0;i>=0&&j<col;)
        {
            if(target==array[i][j])
                return true;
            if(target<array[i][j])
            {
                i--;
                continue;
            }
            if(target>array[i][j])
            {
                j++;
                continue;
            }
        }
        return false;
    }
};
