/*

给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

示例：

给定数组 nums = [-1, 0, 1, 2, -1, -4]，
满足要求的三元组集合为：
[
	[-1, 0, 1],
	[-1, -1, 2]
]

*/
#include <iostream>
#include <string>
#include<vector>
#include <algorithm> //排序需要的头文件

using namespace std;
using std::string;

/*
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		std::sort(nums.begin(), nums.end());//排序
		vector<vector<int>> res;
		/ *	res[0].push_back(i);
			res[0].push_back(j);
			res[0].push_back(k);* /
		if (nums.size() < 3) return res;
		int count = 0;
		for (int i = 0; i < nums.size() - 2; ++i)
		{
			for (int j = i + 1; j < nums.size() - 1; ++j)  
			{
				for (int k = j + 1; k < nums.size(); ++k)
				{
					if (nums[i] + nums[j] + nums[k] == 0)
					{
						res.push_back(std::vector<int>());
						res[count].push_back(nums[k]);
						res[count].push_back(nums[j]);
						res[count].push_back(nums[i]);
						count++;
						break;
					}
					while (k < nums.size() - 1 && nums[k] == nums[k + 1]) k++;
				}
				while (j < nums.size() - 2 && nums[j] == nums[j + 1]) j++;
			}
			while (i < nums.size() - 3 && nums[i] == nums[i + 1]) i++;
		}
		return res;
	}
}; z*/
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.size() < 3) return res;
		sort(nums.begin(), nums.end());   //排序
		for (vector<int>::iterator it = nums.begin(); it != nums.end() - 2;) { //it指向nums的第一个元素 
			int tmp = *it;
			if (tmp > 0) break; 
			int target = 0 - tmp; //保证target>=0
			vector<int>::iterator left = it + 1;
			vector<int>::iterator right = nums.end() - 1;
			while (left < right) {
				if (*right < 0) break; //排序是从小到大，两数相加为正数则右边的数一定是正数
				if (*left + *right < target) {
					int v = *left;
					while (left != right && *left == v) left++; //跳过相等的元素
				}
				else if (*left + *right > target) {
					int v = *right;
					while (left != right && *right == v) right--;//跳过相等的元素
				}
				else {
					vector<int> tmp_res{ tmp,*left,*right };
					res.push_back(tmp_res);
					int v = *left;
					while (left != right && *left == v) left++;//跳过相等的元素
					v = *right;
					while (left != right && *right == v) right--;//跳过相等的元素
				}
			}
			while (it != nums.end() - 2 && *it == tmp) it++;//跳过相等的元素
		}
		return res;  
	}
};

int main()
{
	Solution a;
	vector<int> b = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
	vector<vector<int>> c = a.threeSum(b);

	for (int i = 0; i != c.size(); ++i)
	{
		cout << "[";
		for (int j = 0; j != c[i].size(); ++j)
			cout << c[i][j] << ", ";
		cout << "]\n";
	}

}