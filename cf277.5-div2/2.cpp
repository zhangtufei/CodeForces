#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>
using namespace std;
int boy[110], girl[110], used[110], num, ma[110][110];
int n, m;
bool solve(int a)
{
	for (int i = 0; i <n; ++i)
	{
		if (!used[i] && ma[a][i])
		{
			used[i] = 1;
			if (boy[i]==-1 || solve(boy[i]))
			{
				boy[i] = a;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	
	while (cin >> n)
	{
		num = 0;
		memset(used, 0, sizeof(used));
		for (int i = 0; i < n; ++i)
			cin >> boy[i];
		cin >> m;
		int a;
		memset(ma, 0, sizeof(ma));
		for (int i = 0; i < m; ++i)
		{
			cin >> a;
			for (int j = 0; j < n; ++j)
			{
				if (boy[j] - a <= 1 && boy[j] - a >= -1)
					ma[i][j] = 1;
			}
		}
		memset(boy, -1, sizeof(boy));
		for (int i = 0; i < m; ++i)
		{
			memset(used, 0, sizeof(used));
			if (solve(i))
				++num;
		}
		cout << num << endl;
	}
	return 0;
}