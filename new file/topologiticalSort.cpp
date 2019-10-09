#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<map>
using namespace std;

const int MAXV = 1010;
vector <int> G[MAXV];
int n, m;
int inDegree[MAXV];

bool topologicalSort()
{
	priority_queue<int> q;
	int num = 0;//入队结点
	for (int i = 1; i <= n; i++)
	{
		if (inDegree[i] == 0)
		{
			q.push(i);
		}
	}
	if (q.size() > 1) return false;

	while (!q.empty())
	{
		num++;
		int u = q.top();
		q.pop();
		for (int i = 0; i < G[u].size(); i++)
		{
			int v = G[u][i];
			inDegree[v]--;
			if (inDegree[v] == 0)
			{
				q.push(v);
			}
		}
		G[u].clear();
	}
	if (num == n)
		return true;
	else
	{
		return false;
	}
}

int main()
{
	while (scanf("%d", &m) != EOF && m != 0)
	{

		string A, B;
		map<string, int> mp;
		int a, b;
		int cnt = 1;
		for (int i = 0; i < m; i++)
		{
			cin >> A >> B;
			if (mp.find(A) == mp.end())
			{
				mp[A] = cnt;
				a = cnt;
				cnt++;
			}
			else
			{
				a = mp[A];
			}
			if (mp.find(B) == mp.end())
			{
				mp[B] = cnt;
				b = cnt;
				cnt++;
			}
			else
			{
				b = mp[B];
			}
			G[a].push_back(b);
			inDegree[b]++;
		}
		n = mp.size();
		if (topologicalSort())
			cout << "Yes" << endl;
		else
		{
			cout << "No" << endl;
		}
		for (int i = 0; i <= n; i++)
		{
			G[i].clear();
			inDegree[i] = 0;
		}

	}
	return 0;
} 