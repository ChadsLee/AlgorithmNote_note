#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

const int maxn = 10003;
int A[maxn];
int dp[maxn];

int main()
{
	int k;
	while (cin>>k)
	{
		int flag = 0;
		for (int i = 0; i < k; i++)
		{
			cin >> A[i];
			if (A[i] >= 0)
				flag = 1;
		}
		dp[0] = A[0];
		for (int i = 1; i < k; i++)
		{
			dp[i] = max(A[i], dp[i - 1] + A[i]);
		}
		int n = 0;
		for (int i = 0; i < k; i++)
		{
			if (dp[i] > dp[n])
				n = i;
		}
		int t = 0;
		int b;
		for (int i = n; i >= 0; i--)
		{
			t += A[i];
			if (t == dp[n])
			{
				b = i;
				break;
			}
		}
		if (flag == 0)
		{
			cout << 0 << " " << A[0] << " " << A[k - 1] << endl;
		}
		else
		{
			cout << dp[n] << " " << A[b] << " " << A[n] << endl;
		}
	}
	return 0;
}