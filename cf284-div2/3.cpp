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
int n, T;
double p[5010][5010], sum;
int t[5010];
void Solve(int num, int ti, int songs, double pi)
{
	if (num>n)
	{
		sum += ((songs)*pi);
		return;
	}
	for (int i = 1; i <= t[num]; ++i)
	{
		if (ti + i == T)
		{
			double temp=0;
			for (int j = i + 1; j <= t[num]; ++j)
				temp += p[num][i];
			sum += (((songs+1)*pi*p[num][i])+songs*pi*(1-temp));//这里需要计算出听出与听不出当前歌曲的概率
			return;
		}
		Solve(num + 1, ti + i, songs + 1, pi*p[num][i]);
	}
}
int main()
{
	streambuf * buf;
	fstream fin;
	fin.open("dataD.txt");
	buf = cin.rdbuf();
	cin.rdbuf(fin.rdbuf());
	while (cin >> n >> T)
	{
		double tp;
		memset(p, 0, sizeof(p));
		memset(t, 0, sizeof(t));
		for (int i = 1; i <= n; ++i)
		{
			cin >> tp >> t[i];
			tp /= 100.0;
			double tp1 = tp, tp2 = 0.0;
			for (int j = 1; j <= t[i]; ++j)
			{
				if (j == t[i])
				{
					p[i][j] = 1 - tp2;
					break;
				}
				p[i][j] = tp1;
				tp2 += tp1;
				tp1 *= (1 - tp);
			}
		}
		sum = 0.0;
		Solve(1, 0,0,1);
		cout.precision(9);
		cout << fixed << sum << endl;
	}
	cin.rdbuf(buf);
	return 0;
}