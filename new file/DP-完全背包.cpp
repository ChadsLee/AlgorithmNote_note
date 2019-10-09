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