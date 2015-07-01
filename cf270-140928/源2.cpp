#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>
using namespace std;
int main()
{
	int n, k;
	while (cin >> n)
	{
		cin >> k;
		map<int, int> fl;
		int temp;
		for (int i = 1; i <= n; ++i)
		{
			cin >> temp;
			++fl[temp];
		}
		long long sum = 0;
		map<int, int>::iterator iter = fl.begin();
		for (; iter != fl.end(); ++iter)
		{
			while (iter->second >= k)
			{
				iter->second -= k;
				sum += (iter->first-1);
			}
		}
		iter = fl.begin();
		int fll[2010];
		memset(fll, 0, sizeof(fll));
		for (; iter != fl.end(); ++iter)
		{
			if (iter->second)
			{
				fll[iter->first] = iter->second;
			}
		}
		--iter;
		int t = iter->first;
		while (t>=2)
		{
			if (fll[t]<=0)
			{
				t -= 1;
				continue;
			}
			sum += (t - 1);
			int temp = k-fll[t];
			fll[t] = 0;
			t -= 1;
			while (temp - fll[t] >= 0)
			{
				if (t<= 2)
					break;
				if (!fll[t])
				{
					t-= 1;
					continue;
				}
				temp -= fll[t];
				fll[t] = 0;
				--t;
			}
			if (t>=2)
				fll[t] -= temp;
			if (t<=2 && fll[2] > 0)
			{
				sum += 1;
				break;
			}

		}
		cout << sum * 2 << endl;
	}
	return 0;
}