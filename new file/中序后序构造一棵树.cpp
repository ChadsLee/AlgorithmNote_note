#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
struct node
{
	int val;
	node* lchild;
	node* rchild;
};
const int maxn = 50;
int post[maxn];
int in[maxn];
int level[maxn];

node* build(int inL, int inR, int postL, int postR)
{
	if (inL > inR || postL > postR)
		return NULL;
	node* root = new node;//声明指针还要初始化
	root->val = post[postR];
	int k;
	for (k = inL; k <= inR; k++)
	{
		if (in[k] == post[postR])
		{
			break;
		}
	}
	int numR = k - inL;
	root->lchild = build(inL, k - 1, postL, postL + numR-1);
	root->rchild = build(k + 1, inR, postL + numR , postR-1);
	return root;
}

void BFS(node* root)
{
	queue<node*> q;
	q.push(root);
	int c = 0;
	while (!q.empty())
	{
		node* now = q.front();
		q.pop();
		level[c++] = now->val;
		//cout << now->val;
		if (now->lchild != NULL)
			q.push(now->lchild);
		if (now->rchild != NULL)
			q.push(now->rchild);
	}
}

int main()
{
	int N;
	while (cin>>N)
	{
		for (int i = 1; i <= N; i++)
		{
			cin >> post[i];
		}
		for (int i = 1; i <= N; i++)
		{
			cin >> in[i];
		}
		node* t = build(1, N, 1, N);
		BFS(t);
		cout << level[0];
		for (int i = 1; i < N; i++)
		{
			cout << " " << level[i];
		}
		cout << endl;
	}
	return 0;
}