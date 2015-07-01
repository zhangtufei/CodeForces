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
int car[110][110];
int main()
{
	//streambuf *bk;
	//fstream fin;
	//fin.open("dataA.txt");
	//bk = cin.rdbuf();
	//cin.rdbuf(fin.rdbuf());
	int n;
	while (cin >> n)
	{

		int dp[110];
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
				cin >> car[i][j];
		}
		if (n == 1)
		{
			cout << 1 << endl<<1<<' '<<endl;
			continue;
		}
		for (int i = 1; i <= n; ++i)
		{
			if (dp[i] == 1)
				continue;
			for (int j = 1; j < i; ++j)
			{
				//if (dp[i] == 1)
				//	continue;
				if (car[i][j] == 1)
				{
					dp[i] = 1;
				}
				else if (car[i][j] == 2)
					dp[j] = 1;
				else if (car[i][j] == 3)
					dp[i] = dp[j] = 1;
			}
		}
		int re = 0;
		int temp = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (!dp[i])
			{
				re += 1;
				dp[temp++] = i;
			}
		}
		cout << re << endl;
		for (int i = 0; i < re; ++i)
			cout << dp[i] << ' ';
		if (re)
			cout << endl;
		//for (int i = 0; i < re-1; ++i)
		//	cout << dp[i] << ' ';
		//if (re>1)
		//	cout << dp[re - 1] << ' ' << endl;
		//else if (re == 1)
		//	cout <<dp[re-1]<< endl;
	}
	
	//cin.rdbuf(bk);
	return 0;
}