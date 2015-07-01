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
int main()
{
	//streambuf *backup;
	//fstream fin;
	//fin.open("dataA.txt");
	//backup = cin.rdbuf();
	//cin.rdbuf(fin.rdbuf());
	int n,t;
	while (cin >> n >> t)
	{
		bool flag = false;
		if (t == 1)
			flag = true;
		int beg = 1;
		int ai;
		int i=1;
		while (i<n)
		{
			while (i <= beg)
			{
				cin >> ai;
				++i;
			}
			if (!flag)
			{
				beg += ai;
				if (beg == t)
				{
					flag = true;
					while (i <= n-1)
					{
						cin >> ai;
						++i;
					}
					cout << "YES" << endl;
				}
				else if (beg > t)
				{
					while (i <= n - 1)
					{
						cin >> ai;
						++i;
					}
					cout << "NO" << endl;
				}
			}
		}
	}
	//cin.rdbuf(backup);
	return 0;
}