#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
/*
const int maxn = 101;
const int maxv = 1003;
int dp[maxv];
int w[maxn];
int c[maxn];
int main()
{

	int V;
	while (cin>>V)
	{
		int n;
		cin >> n;
		memset(dp, 0, sizeof(dp));
		memset(w, 0, sizeof(w));
		for (int i = 1; i <= n; i++)
		{
			cin >> w[i];
		}
		for (int i = 1; i <= n; i++)
		{
			for (int v = V; v >= w[i]; v--)
			{
				dp[v] = max(dp[v], dp[v - w[i]] + w[i]);
			}
		}
		cout << V - dp[V] << endl;

	}




	int T, M;
	while (cin>>T>>M)
	{
		memset(dp, 0, sizeof(dp));
		memset(w, 0, sizeof(w));
		for (int i = 1; i <= M; i++)
		{
			cin >> w[i] >> c[i];
		}
		for (int i = 1; i <= M; i++)
		{
			for (int v = T; v >= w[i]; v--)
			{
				dp[v] = max(dp[v], dp[v - w[i]] + c[i]);
			}
		}
		cout << dp[T] << endl;
	}


	return 0;
}

*/

/*
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

typedef long long LL;
const LL maxn = 10003;
const LL maxv = 28;
LL dp[maxn];
LL w[maxv];

int main()
{
	LL V, N;
	while (cin>>V>>N)
	{
		memset(dp, 0, sizeof(dp));
		memset(w, 0, sizeof(w));
		dp[0] = 1;
		for (LL i = 1; i <= V; i++)
		{
			cin >> w[i];
		}
		for (LL i = 1; i <= V; i++)
		{
			for (LL v = w[i]; v <= N; v++)
			{
				dp[v] = dp[v] + dp[v - w[i]];
			}
		}
		printf("%lld\n", dp[N]);
	}
	return 0;
}
*/

/*
多重背包
*/
const int maxv = 103;
int dp[maxv];
int C,N,M;
int p[maxv];
int h[maxv];
int c[maxv];
vector <int>t;
int main()
{
	int C;
	while (cin>>C)
	{
		while (C--)
		{
			while (cin>>N>>M)
			{
				memset(dp, 0, sizeof(dp));
				for (int i = 1; i <= M; i++)
				{
					cin >> p[i] >> h[i] >> c[i];
				}
				for (int i = 1; i <= M; i++)
				{
					if (N < c[i] * p[i])//完全背包
					{
						for (int v = p[i]; v <= N; v++)
						{
							dp[v] = max(dp[v], dp[v - p[i]] + h[i]);
						}
					}
					else
					{
						t.clear();
						for (int k = 1; k < c[i]; k <<= 1)
						{
							t.push_back(k);
							c[i] -= k;
						}
						t.push_back(c[i]);
						for (int k = 0; k < t.size(); k++)
						{
							for (int v = N; v >= p[i] * t[k]; v--)
							{
								dp[v] = max(dp[v], dp[v - p[i] * t[k]] + h[i] * t[k]);
							}
						}
						
					}
				}
				cout << dp[N] << endl;

			}
		}
	}
	return 0;
}