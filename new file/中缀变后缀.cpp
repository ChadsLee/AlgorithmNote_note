#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<stack>
#include<string.h>
#include<map>
#include<string>

using namespace std;
const int maxn = 210;
map<char, int> P;
stack<char> OP;
int main()
{
	P['-'] = P['+'] = 1;
	P['*'] = P['/'] = 2;
	P['#'] = -1;
	P['('] = 0;
	string in;
	while (cin >> in)
	{
		while (!OP.empty())
		{
			OP.pop();
		}
		int len = in.length();
		for (int i = 0; i < len; i++)
		{
			if (in[i] == '(')
			{
				OP.push(in[i]);
			}
			else if (in[i] == ')')
			{
				while (!OP.empty())
				{
					char t = OP.top();
					if (t == '(') break;
					cout << OP.top();
					OP.pop();
				}
				OP.pop();//pop '('
			}
			else if (in[i] == '+' || in[i] == '-' || in[i] == '*' || in[i] == '/')
			{
				//cout << in[i] << endl;
				if (OP.empty() || P[in[i]] > P[OP.top()])
				{
					//cout << in[i] << endl;
					OP.push(in[i]);
				}
				else
				{
					while (!OP.empty() && P[in[i]] <= P[OP.top()])
					{
						cout << OP.top();
						OP.pop();
					}
					OP.push(in[i]);
				}
			}
			else
			{
				cout << in[i];
			}
		}
		while (!OP.empty())
		{
			cout << OP.top();
			OP.pop();
		}
	}
	return 0;
}