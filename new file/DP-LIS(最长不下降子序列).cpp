#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 1003;

int A[maxn], dp[maxn];
int main()
{
	int n;
	while (cin>>n)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> A[i];
		}
		int ans = -1;
		for (int i = 1; i <= n; i++)
		{
			dp[i] = 1;
			for (int j = 1; j < i; j++)
			{
				if (A[j]<A[i] && dp[j] + 1 > dp[i])
					dp[i] = dp[j] + 1;
			}
			ans = max(ans, dp[i]);
		}
		cout << ans << endl;
	}
	return 0;
}