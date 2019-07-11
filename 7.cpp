/*
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:

输入: 123
输出: 321
 示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
注意:

假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。
*/

class Solution {
public:
    int reverse(int x) {
        if(x<10 && x>-10)//—9到9之间的数不用逆转
            return x;
        int flag = 0;
        int num = 0;
        long ret = x % 10;
        while(x/10){
            x /= 10;
            num = x % 10;
            ret *= 10;
            if(ret > INT_MAX || ret < INT_MIN)//考虑溢出,用long定义ret,溢出则返回0
                return 0;
            ret += num;
        }
        return ((int)(ret));
    }
};
