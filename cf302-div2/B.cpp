#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
//#include <map>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <streambuf>
using namespace std;
int dir[8][2] = { 1, 0, -1, 0, 0, 1, 0, -1, 1, 1, 1, -1, -1, 1, 1, -1 };
int main()
{
	//streambuf *bk;
	//fstream fin;
	//fin.open("dataB.txt");
	//bk = cin.rdbuf();
	//cin.rdbuf(fin.rdbuf());
	int n, k;
	char map[110][110];
	int dp[110][110];
	while (cin >> n >> k)
	{
		int ma = n / 2;
		if (n % 2)
			ma += 1;
		ma *= ma;
		if (k > ma)
		{
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		memset(map, 'S', sizeof(map));
		memset(dp, 0, sizeof(dp));
		for (int x = 0; x < n; x += 2)
		{
			for (int y = 0; y < n; y += 2)
			{
				map[x][y] = 'L';
				--k;
				if (!k)
					break;
				for (int u = 0; u < 8; ++u)
				{
					if (x + dir[u][0] >= 0 && x + dir[u][0] < n&&y + dir[u][1] >= 0 && y + dir[u][1] < n)
						dp[x + dir[u][0]][y + dir[u][1]] = 1;
				}
			}
			if (!k)
				break;
		}
		for (int x = 0; x < n; x ++)
		{
			for (int y = 0; y < n; y ++)
			{
				if (!dp[x][y])
					map[x][y] = 'L';
				cout << map[x][y];
			}
			cout << endl;
		}
	}
	//cin.rdbuf(bk);
	return 0;
}