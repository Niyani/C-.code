/*遇到这个题，全排列当然可以做，但是时间复杂度为O(n!)。在这里我们自己定义一个规则，对拼接后的字符串进行比较。
排序规则如下：
若ab > ba 则 a 大于 b，
若ab < ba 则 a 小于 b，
若ab = ba 则 a 等于 b；
根据上述规则，我们需要先将数字转换成字符串再进行比较，因为需要串起来进行比较。比较完之后，按顺序输出即可。
*/

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        int length = numbers.size();
        if(length == 0){
            return "";
        }
        sort(numbers.begin(), numbers.end(), cmp);
        string res;
        for(int i = 0; i <　length; i++){
            res += to_string(numbers[i]);
        }
        return res;
    }
private:
    // 升序排序
    static bool cmp(int a, int b){
        string A = to_string(a) + to_string(b);
        string B = to_string(b) + to_string(a);
        return A < B;
    }
    
};
