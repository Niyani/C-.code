class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    if(numbers.empty())
		return 0;
	std::sort(numbers.begin(),numbers.end());
	int middle = numbers[numbers.size()/2]; //取中间的数，可能是目标数，也可能不是。需要进行下列判断
 
	int times = 0; //出现的次数
	for(int i = 0; i < numbers.size(); ++i)  //统计出现的次数
	{
		if(numbers[i] == middle)
			++times;
	}
	return times>numbers.size()/2?middle:0;
    }
};
