#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxv = 503;
const int INF = 999999;
int G[maxv][maxv] = { INF };
int d[maxv] = { INF };
bool vis[maxv] = { false };
int n, m;//点 边
int c1, c2;//自己、目标城市
int city[maxv];
int tot[maxv] = { 0 };//保存起点到每个点最短路的条数
int num[maxv] = { 0 };//表示到点i时候的人数
void init()
{
	for (int i = 0; i < maxv; i++)
	{
		for (int j = 0; j < maxv; j++)
		{
			G[i][j] = INF;
		}
		vis[i] = false;
		d[i] = INF;
		tot[i] = 0;
		num[i] = 0;
	}

}


void dijsktra(int s)
{
	d[s] = 0;
	num[s] = city[s];
	tot[s] = 1;
	for (int i = 0; i < n; i++)
	{
		int u = -1, min = INF;
		for (int j = 0; j < n; j++)
		{
			if (vis[j] == false && d[j] < min)
			{
				u = j;
				min = d[j];
			}
		}
		if (u == -1) return;//说明不连通
		vis[u] = true;
		//cout << u << endl;
		for (int v = 0; v < n; v++)
		{
			if (vis[v] == false && G[u][v] != INF)
			{
				if (d[u] + G[u][v] == d[v])
				{
					tot[v] += tot[u];
					num[v] = max(num[v], num[u] + city[v]);
				}
				//cout << d[u] + G[u][v] << "?" <<d[v] << endl;
				if (d[u] + G[u][v] < d[v])
				{
					d[v] = d[u] + G[u][v];
					//cout << d[v] << endl;
					tot[v] = tot[u];
					num[v] = num[u] + city[v];
				}
				//cout << G[0][4] << endl;
				//cout <<"u:"<<u<< "v:" << v << "-" << tot[v] << "-" << num[v] << endl;
				//
			}
		}
		//cout << endl;
	}
}

int main()
{
	init();
	cin >> n >> m >> c1 >> c2;
	for (int i = 0; i < n; i++)
	{
		cin >> city[i];
	}
	for (int i = 0; i < m; i++)
	{
		int p1, p2, len;
		cin >> p1 >> p2 >> len;
		G[p1][p2] = len;
		G[p2][p1] = len;
	}
	dijsktra(c1);
	cout << tot[c2] << " " << num[c2] << endl;
	return 0;

}

