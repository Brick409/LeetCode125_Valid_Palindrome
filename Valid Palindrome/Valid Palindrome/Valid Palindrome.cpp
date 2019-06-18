// Valid Palindrome.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <malloc.h>
#include <ctype.h>
using namespace std;
/*
125题目：给定一个字符串，只看其中的数字和字母，
	忽略大小写，判断这个字符串是否为回文串。
Example 1:
Input: "A man, a plan, a canal: Panama"
Output: true

Example 2:
Input: "race a car"
Output: false
*/

class Solution {
public:
	bool isPalindrome(string s) {
		int left = 0;
		int right = s.size()-1;

		if (s.empty()||s.size()==1)
		{
			return true;
		}
		while (left<right)
		{
			if (isalpha(s[left]) == 0 && isdigit(s[left])==0)
			{
				left++;
			}else if (isalpha(s[right]) == 0 && isdigit(s[right]) == 0)
			{
				right--;
			}
			else
			{
				//此时left和right指向的元素都是字母和数字
				//通过字母或数字+32-'a'然后对32求余的方式，全部转化后进行比较
				//ascall码中对应 'a'= 97  'A'= 65  '0'=48
				if ((s[left] + 32 - 'a')%32 == (s[right] + 32 -'a')%32)
				{
					left++;
					right--;
				}
				else
					return false;
			}
		}

		return true;
	}
};

int main()
{
	string str = "A man, a plan, a canal: Panama";

	if (Solution().isPalindrome(str))
	{
		cout << str <<endl<<"is  a valid Palindrome"<<endl;
	}
	else
		cout << str << endl << "is not a valid Palindrome"<< endl;

    std::cout << "Hello World!\n"; 
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
