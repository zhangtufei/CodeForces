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
int ma[1010][1010], n, m, k;

int main()
{
	//streambuf *bk;
	//fstream fin;
	//fin.open("dataA.txt");
	//bk = cin.rdbuf();
	//cin.rdbuf(fin.rdbuf());
	while (cin >> n >> m >> k)
	{
		memset(ma, 0, sizeof(ma));
		int flag = 1, re=0;
		while (flag++ <= k)
		{
			int i, j;
			cin >> i >> j;
			if (!re)
			{
				ma[i][j] = 1;
				if (j - 1 >= 1 && ma[i][j - 1])
				{
					if (i - 1 >= 1 && ma[i - 1][j] && ma[i - 1][j - 1])
					{
						re = flag - 1;
						continue;
					}
					else if (i + 1 <= n&&ma[i + 1][j] && ma[i + 1][j - 1])
					{
						re = flag - 1;
						continue;
					}
				}
				else if (j + 1 <= m&&ma[i][j + 1])
				{
					if (i - 1 >= 1 && ma[i - 1][j] && ma[i - 1][j + 1])
					{
						re = flag - 1;
						continue;
					}
					else if (i + 1 <= n&&ma[i + 1][j] && ma[i + 1][j + 1])
					{
						re = flag - 1;
						continue;
					}
				}
			}
		}
		cout << re << endl;
	}
	//cin.rdbuf(bk);
	return 0;
}