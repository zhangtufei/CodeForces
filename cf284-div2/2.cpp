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
	//streambuf * buf;
	//fstream fin;
	//fin.open("dataB.txt");
	//buf = cin.rdbuf();
	//cin.rdbuf(fin.rdbuf());
	int n, m;
	while (cin >> n >> m)
	{
		map<string, string> ma;
		string s1, s2;
		for (int i = 0; i < m; ++i)
		{
			cin >> s1 >> s2;
			ma[s1] = s2;
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> s1;
			s2 = ma[s1];
			if (s2.size() < s1.size())
				cout << s2;
			else
				cout << s1;
			if (i != n - 1)
				cout << ' ';
			else
				cout << endl;
		}
	}
	//cin.rdbuf(buf);
	return 0;
}