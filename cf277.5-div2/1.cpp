#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>
#include <iomanip>
#include <queue>
#include <stack>
using namespace std;
long long a[3010];
int main()
{
	int n;
	while (cin >> n)
	{
		int swaps = 0;
		int point = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		long long min;
		int x, y;
		int st1[3010], st2[3010];
		int temp = n - 1;
		while (temp--)
		{
			min = a[point];
			x = point;
			//bool flag = true;
			for (int i = point; i < n; ++i)
			{
				if (a[i] < min)
				{
					min = a[i];
					x = i;
					//flag = false;
				}
			}
			if (x!=point)
			{
				a[x] = a[point];
				a[point] = min;
				st1[swaps] = x;
				st2[swaps++] = point;
			}
			point++;
		}
		cout << swaps << endl;
		for (int i = 0; i < swaps; ++i)
			cout << st2[i] << ' ' << st1[i] << endl;
	}
	return 0;
}