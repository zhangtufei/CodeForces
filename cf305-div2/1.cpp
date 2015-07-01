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
string s;
bool solve(int i, int len)
{
	int x, y;
	for (x = i,y =i+ len - 1; y >= x; ++x, --y)
	{
		if (s[x] != s[y])
			return false;
	}
	return true;
}
int main()
{
	//streambuf *bk;
	//fstream fin;
	//fin.open("dataA.txt");
	//bk = cin.rdbuf();
	//cin.rdbuf(fin.rdbuf());
	while (cin >> s)
	{
		int k;
		cin >> k;
		if (s.size() % k != 0)
		{
			cout << "NO" << endl;
			continue;
		}
		int len = s.size() / k;
		bool flag = true;
		for (int i = 0; i < s.size();i+=len)
		{
			if (!solve(i, len))
			{
				flag = false;
				break;
			}
		}
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	//cin.rdbuf(bk);
	return 0;
}