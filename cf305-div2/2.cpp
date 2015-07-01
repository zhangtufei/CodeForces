#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <streambuf>
#include <utility>
using namespace std;
int mp[510][510];
struct m
{
	int beg;
	int ed;
	int mx;
};
int n, m, q;
int mxnum, mxrow;
struct m rw[510];
void solve(int x, int y)
{
	if (mp[x][y] == 0)
	{
		int num = 1;
		mp[x][y] = 1;
		if (rw[x].mx == 0)
		{
			rw[x].beg = y;
			rw[x].ed = y;
			rw[x].mx = 1;
			if (rw[x].mx > mxnum)
			{
				mxnum = rw[x].mx;
				mxrow = x;
			}
		}
		else
		{
			if (y == rw[x].beg - 1)
			{
				while (y - 1 >= 1 && mp[x][y - 1] == 1)
				{
					++num;
					y -= 1;
				}
				rw[x].beg = y;
				/*		if (rw[x].ed == 0)
							rw[x].ed = rw[x].beg;*/
				rw[x].mx += num;
				if (rw[x].mx > mxnum)
				{
					mxnum = rw[x].mx;
					mxrow = x;
				}
			}
			else if (y == rw[x].ed + 1)
			{
				while (y + 1 <= m && mp[x][y + 1] == 1)
				{
					++num;
					y += 1;
				}
				rw[x].ed = y;
				/*		if (rw[x].beg == 0)
							rw[x].beg = rw[x].ed;*/
				rw[x].mx += num;
				if (rw[x].mx > mxnum)
				{
					mxnum = rw[x].mx;
					mxrow = x;
				}
			}
		}
	}
	else if (mp[x][y] == 1)
	{
		mp[x][y] = 0;
	/*	if (rw[x].mx == 1)
		{
			rw[x].beg = 0;
			rw[x].ed = 0;
			rw[x].mx = 0;
			if (mxrow == x)
			{
				mxnum = 0;
				return;
			}
		}*/
		if (y >= rw[x].beg&&y <= rw[x].ed)
		{
			rw[x].mx = 0;
			int beg = 0, ed =0, mx = 0;
			bool flag = true;
			int i = x;
			for (int j = 1; j <= m; ++j)
			{
				//cin >> mp[i][j];
				if (mp[i][j])
				{
					if (flag)
					{
						beg = j;
						ed = j;
						mx = 1;
						flag = false;
					}
					else
					{
						ed = j;
						++mx;
					}
					if (mx > rw[i].mx)
					{
						rw[i].beg = beg;
						rw[i].ed = ed;
						rw[i].mx = mx;
					}
				}
				else
				{
					flag = true;
					mx = 0;
				}
			}
			if (mxrow == x)
			{
				mxnum = 0;
				for (int i = 1; i <= n; ++i)
				{
					if (rw[i].mx > mxnum)
					{
						mxnum = rw[i].mx;
						mxrow = i;
					}
				}
			}
		}
	}
}
int main()
{
	streambuf *bk;
	fstream fin;
	fin.open("dataB.txt");
	bk = cin.rdbuf();
	cin.rdbuf(fin.rdbuf());
	while (cin >> n >> m >> q)
	{
		mxnum = 0;
		mxrow = 0;
		memset(rw, 0, sizeof(rw));
		for (int i = 1; i <= n; ++i)
		{
			int beg =0, ed = 0, mx = 0;
			bool flag = true;
			for (int j = 1; j <= m; ++j)
			{
				cin >> mp[i][j];
				if (mp[i][j])
				{
					if (flag)
					{
						beg = j;
						ed = j;
						mx = 1;
						flag = false;
					}
					else
					{
						ed = j;
						++mx;
					}
					if (mx > rw[i].mx)
					{
						rw[i].beg = beg;
						rw[i].ed = ed;
						rw[i].mx = mx;
					}
				}
				else
				{
					flag = true;
				}
			}
			if (mxnum < rw[i].mx)
			{
				mxnum = rw[i].mx;
				mxrow = i;
			}
		}
		int tx, ty;
		for (int i = 0; i < q; ++i)
		{
			cin >> tx >> ty;
			solve(tx, ty);
			cout << mxnum << endl;
		}
	}

	cin.rdbuf(bk);
	return 0;
}