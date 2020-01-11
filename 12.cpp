/*
�������ְ������������ַ��� I�� V�� X�� L��C��D �� M��

�ַ�          ��ֵ
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
���磬 �������� 2 д�� II ����Ϊ�������е� 1��12 д�� XII ����Ϊ X + II �� 27 д��  XXVII, ��Ϊ XX + V + II ��
ͨ������£�����������С�������ڴ�����ֵ��ұߡ���Ҳ�������������� 4 ��д�� IIII������ IV������ 1 ������ 5 ����ߣ�����ʾ�������ڴ��� 5 ��С�� 1 �õ�����ֵ 4 ��ͬ���أ����� 9 ��ʾΪ IX���������Ĺ���ֻ�������������������

I ���Է��� V(5) �� X(10) ����ߣ�����ʾ 4 �� 9��
X ���Է��� L(50) �� C(100) ����ߣ�����ʾ 40 �� 90��
C ���Է��� D(500) �� M(1000) ����ߣ�����ʾ 400 �� 900��
����һ������������תΪ�������֡�����ȷ���� 1 �� 3999 �ķ�Χ�ڡ�
ʾ�� 1:
	����: 3
	��� : "III"
ʾ�� 2 :
	���� : 4
	��� : "IV"
ʾ�� 3 :
	���� : 9
	��� : "IX"
ʾ�� 4 :
	���� : 58
	��� : "LVIII"
	���� : L = 50, V = 5, III = 3.
ʾ�� 5 :
	���� : 1994
	��� : "MCMXCIV"
	���� : M = 1000, CM = 900, XC = 90, IV = 4
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using std::string;
class Solution {
public:
	string intToRoman(int num) {
		string s;

		std::pair<int, const char*> array[] = {
			{1000, "M"},
			{900, "CM"} ,
			{500, "D"},
			{400, "CD"},
			{100, "C"},
			{90, "XC"},
			{50, "L"},
			{40, "XL"},
			{10, "X"},
			{9, "IX"},
			{5, "V"},
			{4, "IV"},
			{1, "I"},
		};
		
		while (num != 0)
		{
			for (int i = 0; i != 13; ++i)
			{
				if (num >= array[i].first)
				{
					num -= array[i].first;
					s += array[i].second;
					break;
				}
			}
		}

		return s;

	}
};
int main()
{
	Solution a;
	std::cout << a.intToRoman(46);
}