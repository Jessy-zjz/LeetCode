#include <iostream>
#include <string>
#include<vector>
using namespace std;
using std::string;
/*
给定一个仅包含数字 2 - 9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

示例 :

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
2=abc 3=def 7=pqrs
输入 237
输出  adp adq adr ads aep aeq aer aes afp afq afr afs

说明 :
	尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
*/
#include <string_view>
class Solution {
public:

	__forceinline string_view GetCharMap(char _digit)
	{
		static string_view charMap[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		return charMap[_digit - '0'];
	}

	vector<string> letterCombinations(string digits)
	{
		size_t len = 1;
		for (size_t i = 0; i != digits.size(); ++i)
		{
			if (digits[i] - '0' == 9 || digits[i] - '0' == 7) len = len * 4;
			else if (digits[i] - '0' > 1 && digits[i] - '0' < 9) len = len * 3;
		}
		if (len == 1) return vector<string>();

		vector<string> res;
		res.resize(len);//有效元素的个数为len

		size_t size = 1;
		for (size_t i = 0; i != digits.size(); ++i)
		{
			if (GetCharMap(digits[i]).size() == 0) continue;

			for (size_t j = 0; j != len;)
			{
				for (size_t k = 0; k != GetCharMap(digits[i]).size(); ++k)
				{
					for (size_t m = 0; m != size; ++m)
					{
						res[j].push_back(GetCharMap(digits[i])[k]);
						++j;
					}
				}
			}
			size *= GetCharMap(digits[i]).size();
		}
		return res;
	}
};
int main()
{
	Solution a;
	vector<string> b = a.letterCombinations("23");

	for (size_t i = 0; i != b.size(); ++i)
	{
		cout << b[i] << "\n";
	}
}
