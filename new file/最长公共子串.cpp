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
	vector<vector<int>> record(len1, vector<int>(len2));//һ����άvector���ڶ�ά��С��s2�ĳ���
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
				maxend = i;//����¼i�����LCS��ȡs1���Ӵ�
			}
		}
	}
	return s1.substr(maxend - maxlen + 1, maxlen);//��1��
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