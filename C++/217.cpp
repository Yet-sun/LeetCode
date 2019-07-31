/*
给定一个整数数组，判断是否存在重复元素。

如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。

示例 1:

输入: [1,2,3,1]
输出: true
示例 2:

输入: [1,2,3,4]
输出: false
示例 3:

输入: [1,1,1,3,3,4,3,2,4,2]
输出: true
 */

class Solution {
public:
    //方法一：暴力求解，超时
    bool containsDuplicate1(vector<int>& nums) {
        if(nums.size() < 2)
            return false;
        for(int i=0; i<nums.size()-2; ++i){
            for(int j=i+1; j<nums.size()-1; ++j){
                if(nums[i] == nums[j])
                    return true;
            }
        }
        return false;
    }
    
    //方法二：先排序，再比较相邻元素是否重复
    bool containsDuplicate2(vector<int>& nums) {
        if(nums.empty())
            return false;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1])
                return true;
        }
        return false;
    }
    
    //方法二修改：自己实现插入排序，然后比较，效率比上一个好
    bool containsDuplicate3(vector<int>& nums) {
        int len = nums.size();
        if(len < 2)
            return false;
        for(int i=1; i<len; ++i){
            int key=nums[i];
            int j=i-1;  //j不能放在下一层for循环里，要单独取出来
            for(; j>=0; --j){
                if(nums[j] > key)
                    nums[j+1] = nums[j];
                else if(nums[j] == key)
                    return true;
                else
                    break;
            }
            nums[j+1] = key;
        }
        return false;
    }
    
    //方法三：
    //大佬做法：unordered_set，两行代码搞定，但实际上效率很一般
    //用set、map也可以
    bool containsDuplicate4(vector<int>& nums){
        unordered_set<int> unique(nums.begin(), nums.end());
        return unique.size() < nums.size();
    }
};


