/*
����һ�����������һ��Ŀ��ֵ���ҳ������к�ΪĿ��ֵ����������
����Լ���ÿ������ֻ��Ӧһ�ִ𰸣���ͬ����Ԫ�ز��ܱ��ظ����á�
ʾ��:
���� nums = [2, 7, 11, 15], target = 9
��Ϊ nums[0] + nums[1] = 2 + 7 = 9
���Է��� [0, 1]
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ret;
		for (int i = 0;i<nums.size();i++){
			for (int j = i + 1;j<nums.size();j++){
				if (nums[i] + nums[j] == target){
					ret.push_back(i);
					ret.push_back(j);
					return ret;
				}
			}
		}
		return ret;
    }
};
