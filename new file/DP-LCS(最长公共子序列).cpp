#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
const int maxn = 103;
char A[maxn];
char B[maxn];
int dp[maxn][maxn];

int main()
{
	while (scanf("%s%s",A+1,B+1)!=EOF)
	{
		int lenA = strlen(A + 1);
		int lenB = strlen(B + 1);
		for (int i = 0; i <= lenA; i++)
		{
			dp[i][0] = 0;
		}
		for (int j = 0; j <= lenB; j++)
		{
			dp[0][j] = 0;
		}
		for (int i = 1; i <= lenA; i++)
		{
			for (int j = 1; j <= lenB; j++)
			{
				if (A[i] == B[j])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;//之所以从1开始，要保证i-1最小为0
				}
				else
				{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		cout << dp[lenA][lenB] << endl;
	}
	return 0;

}