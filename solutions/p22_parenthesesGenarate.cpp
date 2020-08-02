/*
P22 括号生成

数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

示例：
输入：n = 3
输出：[
       "((()))",
       "(()())",
       "(())()",
       "()(())",
       "()()()"
     ]
思路：
DFS+少量的剪枝，剪枝的条件为：左括号的数目一旦小于右括号的数目，以及，左括号的数目和右括号数目均小于n。
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
		vector<string> res;
        func(res, "", 0, 0, n);
		return res;
    }
	void func(vector<string> &res, string str, int l, int r, int n)
	{
		if (l > n || r > n || r > l) return ;
		if (l == n && r == n)
		{
			res.push_back(str);
			return ;
		}
		func(res, str + '(', l + 1, r, n);
		func(res, str + ')', l, r + 1, n);
		return ;
	}
};

int main()
{
	int n;
	vector<string> result;
	cin >> n;
	Solution s;
	result = s.generateParenthesis(n);
	
	for( vector<string>::iterator itr = result.begin(); itr != result.end(); itr++)
	{
		cout << *itr << endl;
	}
	return 0;
}