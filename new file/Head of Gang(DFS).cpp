#include<iostream>
#include<stdio.h>
#include<string>
#include<map>
using namespace std;
/*
需要：最大人数；最大值；编号.姓名、姓名.编号、head.人数的map；连接矩阵G；点权；边数k；下限k；总人数numPerson；标记是否访问vis
函数：DFS; DFSTrave; 返回姓名str对应的编号; main
*/
const int maxn = 2020;//1000条边，可能2000人
const int INF = 10000000;
//map不能定义大小
map<string, int> strToint;
map<int, string> intToStr;
map<string, int> gang;
int G[maxn][maxn];
int weight[maxn];
int n = 0;
int k = 0;
int numPerson = 0;
bool vis[maxn];

void DFS(int nowVisit, int& head, int& numMember, int& totalValue)
{
	vis[nowVisit] = true;
	numMember++;
	if (weight[nowVisit] > weight[head])
		head = nowVisit;
	for (int i = 0; i < numPerson; i++)
	{
		if (G[nowVisit][i] != 0)
		{
			totalValue += G[nowVisit][i];
			G[nowVisit][i] = G[i][nowVisit] = 0;//拆掉回路
			if (vis[i] == false)
				DFS(i, head, numMember, totalValue);
		}
	}
}

void DFSTrave()
{
	for (int i = 0; i < numPerson; i++)
	{
		if (vis[i] == false)
		{
			int head = i;
			int numMember = 0;
			int totalValue = 0;
			DFS(i, head, numMember, totalValue);
			if (totalValue > k && numMember > 2)
			{
				gang[intToStr[head]] = numMember;
			}
		}
	}
}

int change(string s)
{
	if (strToint.find(s) != strToint.end())
	{
		return strToint[s];
	}
	else
	{
		strToint[s] = numPerson;
		intToStr[numPerson] = s;
		return numPerson++;
	}
}

int main()
{
	while (cin >> n >> k)
	{
		string s1, s2;
		int w;
		for (int i = 0; i < n; i++)
		{
			cin >> s1 >> s2 >> w;
			int u1 = change(s1);
			int u2 = change(s2);
			//记录每个人的通话时间
			//因为可能打很多遍，所以是+=
			weight[u1] += w;
			weight[u2] += w;
			G[u1][u2] += w;
			G[u2][u1] += w;
		}
		DFSTrave();
		map<string, int>::iterator it;//迭代器
		cout << gang.size() << endl;
		for (it = gang.begin(); it != gang.end(); it++)
		{
			cout << it->first << " " << it->second << endl;
		}
	}
	return 0;
}