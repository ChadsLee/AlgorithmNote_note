#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std;
int map[210][210];
bool vis[210][210] = { false };
int prime[40010];
void getPrime()//得到素数表
{
	for (int i = 0; i <= 40008; i++)
		prime[i] = 1;
	prime[1] = 0;
	for (int i = 2; i <= 40010; i++)
	{
		if (prime[i])
		{
			for (int j = i * i; j < 40000; j += i)
			{
				prime[j] = 0;
			}
		}
	}
}
void graph()
{
	int c = 40000;
	int x = 1, y = 200, a = 1, b = 200;
	int i;
	while (c > 0)
	{
		for (i = x; i <= y; i++)
		{
			map[x][i] = c--;
		}
		x++;
		for (i = x; i <= y; i++)
		{
			map[i][y] = c--;
		}
		y--;
		for (i = y; i >= a; i--)
		{
			map[b][i] = c--;
		}
		b--;
		for (i = b; i > a; i--)
		{
			map[i][a] = c--;
		}
		a++;
	}
}
struct node
{
	int x, y;
	int step;
};
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int BFS(node s, int e)
{
	memset(vis, false, sizeof(vis));

	vis[s.x][s.y] = true;

	queue<node> q;
	q.push(s);
	while (!q.empty())
	{
		node now = q.front();
		vis[now.x][now.y] = true;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = now.x + dir[i][0];
			int ny = now.y + dir[i][1];
			if (nx < 1 || nx>200 || ny < 1 || ny >200 || vis[nx][ny] == true || prime[map[nx][ny]] == 1)
				continue;
			if (map[nx][ny] == e)
			{
				return now.step + 1;
			}
			vis[nx][ny] = true;
			//cout << map[nx][ny] << "--" << prime[map[nx][ny]] << endl;
			node t;
			t.x = nx;
			t.y = ny;
			t.step = now.step + 1;
			q.push(t);
		}
	}
	return -1;
}
node find_s(int s)
{
	node tmp;
	tmp.step = 0;
	for (int i = 1; i <= 200; i++)
	{
		for (int j = 1; j <= 200; j++)
		{
			if (map[i][j] == s)
			{
				tmp.x = i;
				tmp.y = j;
				//cout << i << j << endl;
				return tmp;
			}
		}
	}
}

int main()
{
	int N;
	cin >> N;
	int count = 1;
	for (int c = 0; c < N; c++)
	{
		int s, e;
		getPrime();
		graph();
		cin >> s >> e;
		node t = find_s(s);
		int flag = BFS(t, e);
		if (flag == -1)
		{
			cout << "Case " << count++ << ": impossible" << endl;
		}
		else
		{
			cout << "Case " << count++ << ": " << flag << endl;
		}

	}

	return 0;
}