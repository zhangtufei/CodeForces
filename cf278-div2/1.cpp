#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>
using namespace std;
int main()
{
	long long a;
	while (cin >> a)
	{
		int temp;
		bool flag = false;
		long long t = a+1;
		int step = 1;
		if (t < 0)
			t *= -1;
		bool f = false;
		while (t)
		{
			temp = t % 10;
			t /= 10;
			if (temp == 8)
			{
				f = true;
				break;
			}
		}
		if (f)
		{
			cout << step << endl;
			continue;
		}
		if (a < 0)
		{
			if (a >= -8)
			{
				cout << 8 - a << endl;
				continue;
			}
			t = (a + 1)*-1;
			if (t % 10 == 9)
			{
				cout << step + 1 << endl;
				continue;
			}
			else if (t % 10 == 8)
			{
				cout << step << endl;
				continue;
			}
			else
			{
				t = (a + 1)*-1 / 10 - 1;
				int y = (a + 1)*-1 % 10;
				bool f1 = false;
				while (t)
				{
					temp = t % 10;
					t /= 10;
					if (temp == 8)
					{
						f1 = true;
						break;
					}
				}
				if (f1)
				{
					cout << step + 1 + y << endl;
				}
				else
				{
					cout << step + 2 + y << endl;
				}
			}
		}
		else
		{
			t = a + 1;
			if (t % 10 <= 8)
			{
				cout << step +8-t%10<< endl;
			}
			else
			{
				t = (a+1) / 10 + 1;
				bool f1 = false;
				while (t)
				{
					temp = t % 10;
					t /= 10;
					if (temp == 8)
					{
						f1 = true;
						break;
					}
				}
				if (f1)
				{
					cout << 2 << endl;
				}
				else
					cout << 10 << endl;
			}
		}
	}
	return 0;
}