class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        sort(input.begin(),input.end());
        vector<int> r;
        if(k>input.size())
        {
            return r;
        }
        for(int i=0;i<k;++i)
        {
            r.push_back(input[i]);
        }
        return r;
    }
};
