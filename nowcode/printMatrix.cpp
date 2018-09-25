class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
      int row=matrix.size();//行数
        int col=matrix[0].size();//列数
        vector<int> result;
        int circle=((row<col?row:col)-1)/2+1;//圈数
       for(int i=0;i<circle;i++)
        {
           //从左向右打印
            for(int j=i;j<col-i;++j)
                result.push_back(matrix[i][j]);
           //从上往下的每一列数据
            for(int k=i+1;k<row-i;++k)
                result.push_back(matrix[k][col-1-i]);
            //判断是否会重复打印(从右向左的每行数据)
            for(int m=col-i-2;(m>=i)&&(row-i-1!=i);m--)
                result.push_back(matrix[row-i-1][m]);
            //判断是否会重复打印(从下往上的每一列数据)
            for(int n=row-i-2;(n>i)&&(col-i-1!=i);n--)
                result.push_back(matrix[n][i]);
        }
        return result;
    }
};
