#include<string>
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 210;
int main()
{
	string A;
	string B;
	while (cin>>A>>B)
	{
		int dp[maxn][maxn];
		int len1 = A.length();
		int len2 = B.length();
		for (int i = 0; i <= len1; i++)
		{
			dp[i][0] = i;
		}
		for (int j = 0; j <= len2; j++)
		{
			dp[0][j] = j;
		}
		for (int i = 1; i <= len1; i++)
		{
			for (int j = 1; j <= len2; j++)
			{
				int flag = 1;
				if (A[i-1] == B[j-1]) flag = 0;
				dp[i][j] = min(1 + dp[i][j - 1], dp[i - 1][j] + 1);
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + flag);
			}
		}
		cout << dp[len1][len2] << endl;
	}
	return 0;
}