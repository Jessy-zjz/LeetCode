/*
#include <iostream>
#include <string>
#include<vector>
using namespace std;
using std::string;
/ *
给定一个仅包含数字 2 - 9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

示例 :

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

说明 :
	尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
* /
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> res;
		string charMap[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

		if (digits.size() == 0) return res;

		if (digits.size() == 1)
		{
			for (size_t i = 0; i != charMap[digits[0] - '0'].size(); ++i)
			{
				std::string str;
				str.push_back(charMap[digits[0] - '0'][i]);
				res.push_back(str);
			}
			return res;
		}

		char current = digits.back();
		digits.pop_back();
		vector<string> restRes = letterCombinations(digits);

		for (size_t j = 0; j != restRes.size(); ++j)
		{
			for (size_t k = 0; k != charMap[current - '0'].size(); ++k)
			{
				res.push_back(restRes[j] + charMap[current - '0'][k]);
			}
		}

		return res;
	}
};
int main()
{
	Solution a;
	vector<string> b = a.letterCombinations("45623");

	for (size_t i = 0; i != b.size(); ++i)
	{
		cout << b[i] << "\n";
	}
}

*/
