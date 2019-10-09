#include<iostream>
#include<stdio.h>
using namespace std;
int cou = 1;
void hanoi(int n, char x, char y, char z)
{
	if (n == 1)
	{
		
	}
	else
	{
		hanoi(n - 1, x, z, y);
		cout << cou++ << ". Move disk " << n << " from " << x << " to " << z << endl;
		hanoi(n - 1, y, x, z);
	}
}
int main()
{
	int n;
	while (cin>>n)
	{
		cou = 1;
		hanoi(n, 'X', 'Y', 'Z');
	}
	return 0;
}