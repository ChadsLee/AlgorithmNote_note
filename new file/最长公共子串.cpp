#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
string LCS(string s1, string s2)
{
	int len1 = s1.size();
	int len2 = s2.size();
	vector<vector<int>> record(len1, vector<int>(len2));//一个二维vector，第二维大小是s2的长度
	int maxlen = 0, maxend = 0;
	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			if (s1[i] == s2[j])
			{
				if (i == 0 || j == 0)
				{
					record[i][j] = 1;
				}
				else
				{
					record[i][j] = record[i - 1][j - 1] + 1;
				}
			}
			else
			{
				record[i][j] = 0;
			}
			if (record[i][j] > maxlen)
			{
				maxlen = record[i][j];
				maxend = i;//若记录i，最后LCS是取s1的子串
			}
		}
	}
	return s1.substr(maxend - maxlen + 1, maxlen);//加1！
}

int main()
{
	string a, b;
	while (cin>>a>>b)
	{
		cout << LCS(a, b) << endl;
	}
	return 0;
}