#include<iostream>
#include<stdio.h>
using namespace std;
const int maxn = 33;
int DP[maxn] = { -1 };
int F(int x)
{
	if (x == 0 || x == 1) return 1;
	if (DP[x] != -1) return DP[x];
	else
	{
		DP[x] = F(x - 1) + F(x - 2);
		return DP[x];
	}
	
}
int main()
{
	int n;
	while (cin>>n)
	{
		for (int i = 0; i < maxn; i++)
			DP[i] = -1;
		cout << F(n) << endl;
	}
	return 0;
}