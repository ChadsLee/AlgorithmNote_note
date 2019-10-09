#include<iostream>
#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
//倒水问题，只要三个a,b,c有一个等于k就行
//每次有6个分支
const int maxs = 102;

int A, B, C, K;
int full[3];
struct node
{
	int a[3];
	int step;
};



int bfs()
{
	//初始化
	bool vis[maxs][maxs][maxs] = { false };
	full[0] = A;
	full[1] = B;
	full[2] = C;

	queue<node> q;
	q.push({ A,0,0,0 });
	vis[A][0][0] = true;
	while (!q.empty())
	{
		node now_root = q.front();
		if (now_root.a[0] == K || now_root.a[1] == K || now_root.a[2] == K)
		{
			return now_root.step;
		}
		q.pop();
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (j == i) continue;
				node now = now_root;
				//倒水
				int rest = full[j] - now.a[j];
				if (rest == 0) continue;//j是满的
				if (now.a[i] <= rest)//j到不满
				{
					now.a[j] = now.a[j] + now.a[i];
					now.a[i] = 0;
				}
				else
				{
					now.a[j] += rest;
					now.a[i] -= rest;
				}
				if (vis[now.a[0]][now.a[1]][now.a[2]] == false)
				{
					now.step++;
					vis[now.a[0]][now.a[1]][now.a[2]] = true;
					q.push(now);
				}
			}
		}
	}
	return -1;
}
int main()
{
	while (scanf("%d%d%d%d",&A,&B,&C,&K) !=EOF)
	{
		int t = bfs();
		if (t == -1)
			cout << "no" << endl;
		else
		{
			cout << "yes" << endl;
			cout << t << endl;
		}
	}
	return 0;
}


/*
const int maxp = 53;
bool vis[maxp][maxp][maxp] = { false };
int maze[maxp][maxp][maxp];
int A, B, C, T;
struct node
{
	int a, b, c;
	int t;
};

int go[6][3] = {
	1,0,0,
	-1,0,0,
	0,1,0,
	0,-1,0,
	0,0,1,
	0,0,-1
};
bool judge(int x, int y, int z)
{
	if (x >= A || x<0 || y >= B || y<0 || z >= C ||z<0) return false;//溢出
	if (vis[x][y][z] == true) return false;//来过
	if (maze[x][y][z] == 1) return false;//是墙
	return true;
}
int BFS()
{
	queue<node> q;
	node tmp;
	tmp.a = tmp.b = tmp.c = tmp.t = 0;
	q.push(tmp);
	vis[0][0][0] = true;
	while (!q.empty())
	{
		node t = q.front();
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			int na =t.a + go[i][0];
			int nb =t.b + go[i][1];
			int nc = t.c + go[i][2];
			if (judge(na, nb, nc))
			{
				node newnode;
				newnode.a = na;
				newnode.b = nb;
				newnode.c = nc;
				newnode.t = t.t + 1;
				if (newnode.t == T + 1) return -1;//时间到，跑不掉了
				q.push(newnode);
				vis[na][nb][nc] = true;
				if (na == A - 1 && nb == B - 1 && nc == C - 1) return newnode.t;
			}
		}
	}
	return -1;
}
int main()
{
	int o;
	while (cin>>o)
	{
		for (int m = 0; m < o; m++)
		{
			//fill(vis, vis + maxp * maxp * maxp, false);
			cin >> A >> B >> C >> T;
			for (int i = 0; i < A; i++)
			{
				for (int j = 0; j < B; j++)
				{
					for (int k = 0; k < C; k++)
					{
						cin>>maze[i][j][k];
						vis[i][j][k] = false;
					}
				}
			}
			cout << BFS() << endl;

			
		}
		
	}
	return 0;
}

*/