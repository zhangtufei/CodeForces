#include <iostream>
#include <string>
//#include <map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits.h>
#include <limits>
#include <iosfwd>
using namespace std;
int map[21][21][21][21], used[30][30];
bool solve(int x, int y)
{

}
int main()
{
	int n, m;
	while (cin >> n)
	{
		cin >> m;
		memset(map, 0, sizeof(map));
		memset(used, 0, sizeof(used));
		char c;
		for (int i = 1; i <= n; ++i)
		{
			cin >> c;
			if (c == '>')
			{
				for (int j = 0; j < m; ++j)
					map[i][j][i][j + 1] = 1;
			}
			else if (c == '<')
			{
				for (int j = m; j >0; --j)
					map[i][j][i][j-1] = 1;
			}
		}
		for (int i = 1; i <= m; ++i)
		{
			cin >> c;
			if (c == 'v')
			{
				for (int j = 0; j <= n; ++j)
					map[j][i][j+1][i] = 1;
			}
			else if (c == '^')
			{
				for (int j = n; j > 0; --j)
				{
					map[j][i][j-1][i] = 1;
				}
			}
		}
	}
	for ()
}