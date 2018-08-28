class AntiOrder {
public:
    int mergeSort(vector<int>& A, vector<int>& temp, int left, int right)
    {
        if (left >= right) return 0;
        int reverseCount = 0;
        int mid = (left + right) >> 1;
        reverseCount += mergeSort(A, temp, left, mid);
        reverseCount += mergeSort(A, temp, mid + 1, right);
        int pos, i, j;
        for (pos = left,i = left, j = mid + 1; j <= right; ++j)
        {
            while (i <= mid && A[i] < A[j])
            {
                temp[pos] = A[i];
                ++pos;
                ++i;
            }
            if (i <= mid) reverseCount += mid - i + 1;
            temp[pos] = A[j];
            ++pos;
        }
        while (i <= mid) temp[pos++] = A[i++];
        memcpy(A.data() + left, temp.data() + left, (right - left + 1) * sizeof(int));
        return reverseCount;
    }
 
    int count(vector<int> A, int n)
    {
        vector<int> temp(n, 0);
        return mergeSort(A, temp, 0, n - 1);
    }
};
