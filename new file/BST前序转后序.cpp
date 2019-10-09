#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
const int maxn = 1003;
bool isMirror;
vector<int> pre, post;
void getPost(int l, int r)
{
	if (l > r) return;
	int i = l + 1, j = r;
	if (isMirror == false)//bst
	{
		while (i <= r && pre[l] > pre[i])
		{
			i++;
		}
		while (j > l && pre[l] <= pre[j])
		{
			j--;
		}
	}
	else
	{
		while (i <= r && pre[l] <= pre[i])
		{
			i++;
		}
		while (j > l && pre[l] > pre[j])
		{
			j--;
		}
	}
	if (i - j != 1)return;
	getPost(l + 1, j);
	getPost(i, r);
	post.push_back(pre[l]);
}


int main()
{
	int N;
	cin >> N;
	pre.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> pre[i];
	}
	getPost(0, N - 1);
	if (post.size() != N)
	{
		post.clear();
		isMirror = true;
		getPost(0, N - 1);
	}
	if (post.size() != N)
	{
		cout << "NO" << endl;
	}
	else
	{
		cout << "YES" << endl;
		cout << post[0];
		for (int i = 1; i < N; i++)
		{
			cout << " " << post[i];
		}
	}
	return 0;
}