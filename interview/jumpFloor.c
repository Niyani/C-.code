class Solution {
public:
    int jumpFloor(int number) {
        if(number<=0)
            return -1;
        if(number==1||number==2)
            return number;
        return jumpFloor(number-1)+jumpFloor(number-2);
    }
};
/*假设，一级台阶，有f(1)种方法，二级有f(2)种，以此类推，n级有f(n)种方法。

可以看出，f(1)=1;f(2)=2。

那么，假设n级台阶，那么第一步就有两种情况，跳一步，跟跳两步。

情况一：跳一步，那么接下去的就是f(n-1)；

情况二：跳两步，那么接下去的就是f(n-2)。

所以总数是f(n)=f(n-1)+f(n-2)。

*/
