#include<iostream>
#include<stdio.h>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;

const int maxn = 103;

int main()
{
	int N;
	while (cin >> N && N != 0)
	{
		priority_queue < int, vector<int>, greater<int> > q;
		map<char, int> m;
		int ans = 0;
		for (int i = 0; i < N; i++)
		{
			char t;
			cin >> t;
			cin >> m[t];
		}
		for (map<char, int>::iterator it = m.begin(); it != m.end(); it++)
		{
			q.push(it->second);
		}
		while (q.size() > 1)
		{
			int t1 = q.top();
			q.pop();
			int t2 = q.top();
			q.pop();
			int temp = t1 + t2;
			q.push(temp);
			ans += temp;
		}
		cout << ans << endl;;
	}
	return 0;
}
