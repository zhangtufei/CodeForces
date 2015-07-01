#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>
using namespace std;
int main()
{
	int m, s;
	while (cin >> m >> s)
	{
		if (m * 9 < s||m==0||(m!=1&&s==0))
		{
			cout << -1 << ' ' << -1 << endl;
			continue;
		}
		int a = s / 9;
		int b = s % 9;
		if (b == 0)
		{
			if (a == 0)
			{
				cout << 0 << ' ' << 0 << endl;
				continue;
			}
			--a;
			b = 9;
		}
		if (a + 1 == m)
		{
			cout << b;
			for (int i = 0; i < a; ++i)
				cout << 9;
			cout << ' ';
			for (int i = 0; i < a; ++i)
				cout << 9;
			cout << b << endl;
		}
		else if (a + 1 < m)
		{
			cout << '1';
			for (int i = 0; i < m - a - 2; ++i)
			{
				cout << '0';
			}
			cout << b - 1;
			for (int i = 0; i < a; ++i)
				cout << 9;
			cout << ' ';
			for (int i = 0; i < a; ++i)
				cout << 9;
			cout << b;
			for (int i = 0; i < m - a - 1; ++i)
				cout << 0;
			cout << endl;
		}
		else if (a + 1 > m)
		{
			cout << -1 << ' ' << -1 << endl;
		}
	}
}