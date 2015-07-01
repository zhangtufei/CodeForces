#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>
using namespace std;
int pri[1000000];
int main()
{
	for (int i = 2; i <= 1000000; ++i)
	{
		if (!pri[i])
		{
			int temp = sqrt((double)i);
			bool flag = false;
			for (int j = 2; j <= temp; ++j)
			{
				if (i%j == 0)
				{
					flag = true;
					break;
				}
			}
			if (flag)
				pri[i] = 1;
			else
			{
				long long t = i*2;
				for (int j = 3; t <= 1000000; ++j)
				{
					pri[t] = 1;
					t *= j;
				}
			}
		}
	}
	int n ;
	while (cin >> n)
	{
		for (int i = 4; i < n; ++i)
		{
			if (pri[i] && pri[n - i])
			{
				cout << i << ' ' << n - i << endl;
				break;
			}
		}
	}
	return 0;
}