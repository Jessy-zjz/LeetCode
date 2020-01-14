/*
#include <iostream>
#include <string>
#include<vector>
#include <algorithm> 
using namespace std;
using std::string;

/ *
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1， - 4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
* /
/ *
创建int s[2]；
s[0]=nums[0] s[1]=nums[1] s[2]=nums[2];
思路：类似昨天三数之和等于0的情况，这次只需要判断三个数和target的值是否更接近即可
排序，用left和right双指针的方法，用i指向第一个，left指向nums[i+1] right指向nums[nums.size()-1]
如果nums[i]+nums[left]+nums[right]<taget left++
如果nums[i]+nums[left]+nums[right]>taget right--
每个循环里再判断三数之和与target是否更接近，如果更接近，保存在string res中（替换）
* /
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) //-4,-1,1,,2,
	{
		if (nums.size()<3) return 0;
		sort(nums.begin(), nums.end());   //排序
		int res = nums[0] +nums[1]+nums[2] ;
		int flag = abs(res - target);
		for (vector<int>::iterator it = nums.begin(); it != nums.end() - 2;) 
		{
			int tmp = *it;
			vector<int>::iterator left = it + 1;
			vector<int>::iterator right = nums.end() - 1;
			while (left < right)
			{
				//abs是绝对值
				if (abs(*left + *right + *it - target) < flag)
				{
					res = *it + *left + *right;
					flag = abs( *it + *left + *right-target);
				}

				if (*left + *right + *it == target)  return target;
				else if (*left + *right + *it < target)
				{
					int v = *left;
					while (left != right && *left == v) 
						left++;
				}
				else if (*left + *right + *it > target)
				{
					int v = *right;
					while (left != right && *right == v) 
						right--;
				}
			}
	    while (it != nums.end() - 2 && *it == tmp) it++;//跳过相等的元素
		}
		return res;
	}
};
/ *
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target)
	{
		if (nums.size() < 3) return 0;
		sort(nums.begin(), nums.end());   //排序
		int res = nums[0] + nums[1] + nums[2];
		int flag = abs(res - target);
		for (vector<int>::iterator it = nums.begin(); it != nums.end() - 2; ++it)
		{
			vector<int>::iterator left = it + 1;
			vector<int>::iterator right = nums.end() - 1;
			while (left < right) {
				//abs是绝对值
				if (abs(*left + *right + *it - target) < flag)
				{
					res = *it + *left + *right;
					flag = abs(*it + *left + *right - target);
				}

				if (*left + *right + *it == target)  return target;
				else if (*left + *right + *it < target)  left++;
				else if (*left + *right + *it > target)  right--;
			}
		}
		return res;
	}
};* /
int main()
{
	Solution a;
	vector<int> b = {-1,2,1,-4};  //-3 0 1 2
	cout << a.threeSumClosest(b, 1);
}*/