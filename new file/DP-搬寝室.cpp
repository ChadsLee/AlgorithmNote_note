#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
const int maxn = 2003;
const int INF = 0x7fffffff;
int dp[maxn][maxn];
int list[maxn];

int main()
{
	int n, k;
	while (cin>>n>>k && n!=0 && k!=0)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> list[i];
		}
		sort(list + 1, list + 1 + n);
		for (int i = 1; i <= n; i++)
		{
			dp[0][i] = 0;
		}
		for (int i = 1; i <= k; i++)
		{
			for (int j = 2 * i; j <= n; j++)
			{
				if (j > 2 * i)
					dp[i][j] = dp[i][j - 1];
				else
				{
					dp[i][j] = INF;
				}
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 2] + (list[j] - list[j - 1]) * (list[j] - list[j - 1]));
			}
		}

		cout << dp[k][n]<<endl;
	}
	return 0;
}
