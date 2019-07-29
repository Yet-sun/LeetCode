/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。
 */

class Solution {
public:
    //找的是最长公共前缀，不是最长公共子串，所以由最短的字符串决定最长公共前缀的长度，用最小的串来比较即可
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";
        if(strs.size() == 1)
            return strs[0];
        string min = strs[0];
        string ans = "";
        //找到最短的一个串
        for(int i=1; i<strs.size(); ++i){
            if(strs[i].size() < min.size())
                min = strs[i];
        }
        for(int j=0; j<min.size(); ++j){//依次比较每个串的第一个字符、第二个字符...
            for(int k=0; k<strs.size(); ++k){
                if(min[j] != strs[k][j]){
                    return ans;
                }
            }
            ans += min[j];
        }
        return ans;
    }
};