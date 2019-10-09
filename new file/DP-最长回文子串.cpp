#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<string>
using namespace std;

const int maxn = 5003;
char s[maxn];
int dp[maxn][maxn];
int main()
{
	while (cin.get(s,maxn))
	{
		char S[maxn];
		int P[maxn] = { 0 };
		int l = strlen(s);
		int k = 0;
		for (int i = 0; i < l; i++)
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
			{
				S[k] = s[i] + 32;
				P[k] = i;
				k++;
			}
			else if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9')
			{
				S[k] = s[i];
				P[k] = i;
				k++;
			}
		}
		//以上为了解决大小写空格标点
		int len = strlen(S);
		memset(dp, 0, sizeof(dp));
		int ans = 1;
		int left=0,right=0;
		for (int i = 0; i < len; i++)
		{
			dp[i][i] = 1;
			if (i < len - 1)
			{
				if (S[i] == S[i + 1])
				{
					dp[i][i + 1] = 1;
					if (ans < 2)
					{
						ans = 2;
						left = i;
						right = i+1;
					}
				}
			}
		}
		//状态转移方程
	
		for (int L = 3; L <= len; L++)
		{
			for (int i = 0; i + L - 1 < len; i++)
			{
				int j = i + L - 1;
				if (S[i] == S[j] && dp[i+1][j-1] ==1)
				{
					dp[i][j] = 1;
					if (ans < L)
					{
						ans = L;
						left = i;
						right = j;
					}
				}
			}
		}
		left = P[left];
		right = P[right];
		for (int i = left; i <= right; i++)
			cout << s[i];
		cout << endl;
	}
	return 0;
}