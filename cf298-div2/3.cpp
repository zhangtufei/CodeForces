#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <streambuf>
using namespace std;
int d[200100];
int main()
{
	streambuf *bk;
	fstream fin;
	fin.open("dataC.txt");
	bk = cin.rdbuf();
	cin.rdbuf(fin.rdbuf());
	int n;
	long long a, s;
	while (cin >> n >> a)
	{
		s = 0;
		for (int i = 1; i <= n; ++i)
		{
			cin >> d[i];
			s += d[i];
		}
		if (s == a)
		{
			int i = 1;
			while (i <= n - 1)
			{
				cout << d[i] - 1 << ' ';
				++i;
			}
			cout << d[n] - 1 << endl;
			continue;
		}
		else if (a == n)
		{
			int i = 1;
			while (i <= n - 1)
			{
				cout << 2<< ' ';
				++i;
			}
			cout << 2<< endl;
			continue;
		}
		int i = 1;
		int flag = 0;
		while (s - a > d[i]&&i<n)
		{
			if (!flag)
				flag = 1;
			cout << 0 << ' ';
			s -= d[i];
			a -= 1;
			++i;
		}
		if (s - a <= d[i])
			flag = 1;
		if (!flag)
		{
			while (a - n - i > d[i] && i < n)
			{
				flag = 2;
				cout << 0 << ' ';
				a -= d[i];
				++i;
			}
			if (a - n - i <= d[i])
				flag = 2;
		}
		if (i == n&&flag==1)
		{
			cout << a - 1 << endl;
			continue;
		}
		else if (flag==1)
		{
			if (s != a)
			{
				cout << s - a - 1 << ' ';
				++i;
			}
			while (i <= n-1)
			{
				cout << d[i] - 1 << ' ';
				++i;
			}
			cout << d[n] - 1 << endl;
			continue;
		}
		if (i == n)
		{
			cout << a + 1 << endl;
			continue;
		}
		else 
		{
			if (a != n)
			{
				cout << a - n - i + 1 << ' ';
				++i;
			}
			while (i++ <= n - 1)
				cout << 2 << ' ';
			cout << 2 << endl;
		}
	}
	cin.rdbuf(bk);
	return 0;
}