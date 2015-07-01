#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>
using namespace std;
int ma[3010][3010], used[3010];
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		int a, b;
		memset(ma, 0, sizeof(ma));
		for (int i = 1; i <= m; ++i)
		{
			cin >> a >> b;
			ma[a][b] = 1;
		}
		long long sum[3010];
		long long re = 0;
		for (int i = 1; i <= n; ++i)
		{
			memset(sum, 0, sizeof(sum));
			memset(used, 0, sizeof(used));
			used[i] = 1;
			for (int j = 1; j <= n; ++j)
			{
				if (!used[j] && ma[i][j])
				{
					used[j] = 1;
					for (int k = 1; k <= n; ++k)
					{
						if (!used[k] && ma[j][k])
						{
							++sum[k];
						}
					}
					used[j] = 0;
				}
			}
			used[i] = 0;
			for (int i = 1; i <= n; ++i)
			{
				if (sum[i])
				{
					re = re + sum[i] - 1;
				}
			}
		}
		cout << re << endl;
	}
	return 0;
}