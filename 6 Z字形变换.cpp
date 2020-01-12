/*
将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
比如输入字符串为 "L E E T C O D E I S H I R I N G" 行数为 3 时，排列如下：
L   C   I   R
E T O E S I I G
E   D   H   N
L E E T /C O D E /I S H I /R I N G （输入）
L C I R /E T O E  S I I G /E D H N（输出）
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

请你实现这个将字符串进行指定行数变换的函数：
string convert(string s, int numRows);
示例 1:
输入: s = "LEETCODEISHIRING", numRows = 3
输出 : "LCIRETOESIIGEDHN"
示例 2 :
	输入 : s = "LEETCODEISHIRING", numRows = 4
	输出 : "LDREOEIIECIHNTSG"
	L E E T C O/ D E I S H I /R I N G
	0 1 2 3 4 5  6 7 8 9 0 1 2 3 4 5
	L D R /E O E I I E C I H N T S G
	解释 :
	L     D     R
	E   O E   I I
	E C   I H   N
	T     S     G
	如果numRow=5
	L				I
	E			E	S			G
	E		D		H		N
	T	O			I	I
	C				R
	L E E T C O D E/I S H I R I N G
	L I E E S G E D H N T O I I C R
	3-4 4-6 5-8 2N-2
	通过简单的数学归纳，发现可以通过numRows进行分段，每段的元素个数为2*numRows-2
	之后先输出每段的第一个数字，之后输出每段的第二个，最后一个，第三个，倒数第二个，直至结束即为输出结果，
	用left和right指向第一段的头尾，即left=0 ,right=2*numRows-3

*/
//输入: s = "LEETCODEISHIRING", numRows = 4
//输出 : "LDREOEIIECIHNTSG"
//L E E T C O / D E I S H  I  /  R  I  N  G
//0 1 2 3 4 5   6 7 8 9 10 11   12  13 14 15
//L D R //E O E I I E C I H N T S G
//n=4 duanSize=2*n-2=6
//left =0 right =duanSize-1=5
//下一段的开始和结尾就是 left+duanSize=6 right+duanSize=11
//解释 :
//L     D     R		?
//E   O E   I I	
//E C   I H   N
//T     S     G

#include <string>
#include <iostream>
using namespace std;
using std::string;
class Solution {
public:
	string convert(string s, int numRows)
	{
		if (numRows == 1) return s;
		int duanSize = 2 * numRows - 2;
		int left = 1, right = duanSize - 1;
		int duanNum = (s.size() + duanSize - 1) / duanSize; //向上取整的写法
		string res;
		for (int i = 0; i < duanNum; ++i)
		{
			res.push_back(s[i * duanSize]);
		} //将每段的第一个元素先输出
		while (left < right)
		{
			for (int i = 0; i < duanNum; ++i)
			{
				if(left + i * duanSize < s.size())
				res.push_back(s[left   + i*duanSize]);
				if (right + i * duanSize < s.size())
				res.push_back(s[right + i*duanSize]);
			}
			left++;
			right--;
		}
		if (left == right)
		{
			for (int i = 0; i < duanNum; ++i)
			{
				if (left + i * duanSize < s.size())
					res.push_back(s[left + i * duanSize]);
			}
		}
		return res;

	}
};

int main()
{
	Solution a;
	std::cout << a.convert("LEETCODEISHIRING", 5 );

}