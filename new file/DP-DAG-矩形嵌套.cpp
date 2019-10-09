#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

const int maxn = 1003;
const int INF = -1;

int G[maxn][maxn] = { INF };
int x[maxn];
int y[maxn];
int dp[maxn];

int num;
int DP(int i)
{
	if (dp[i] > 0) return dp[i];
	for (int j = 0; j < num; j++)
	{
		if (G[i][j] != INF)
		{
			dp[i] = max(dp[i], DP(j) + 1);
		}
	}
	return dp[i];
}

int main()
{
	int N;
	while (cin >> N)
	{
		while (N--)
		{
			memset(dp, 0, sizeof(dp));
			memset(G, INF, sizeof(G));
			cin >> num;
			for (int i = 0; i < num; i++)
			{
				int t1, t2;
				cin >> t1 >> t2;
				if (t1 < t2)
				{
					x[i] = t1;
					y[i] = t2;
				}
				else
				{
					x[i] = t2;
					y[i] = t1;
				}
				for (int j = 0; j < i; j++)
				{
					if (x[j] < x[i] && y[j] < y[i])
						G[j][i] = 1;
					if (x[i] < x[j] && y[i] < y[j])
						G[i][j] = 1;
				}
			}
			int ans = 0;
			
			for (int i = 0; i < num; i++)
			{
				int t = DP(i);
				ans = (ans > t) ? ans : t;
			}
			cout << ans << endl;
		}
	}
}