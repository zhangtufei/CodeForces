#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	string s[3] = { "qwertyuiop", "asdfghjkl;", "zxcvbnm,./", };
	char c;
	while (cin >> c)
	{
		int flag ;
		if (c == 'R')
		{
			flag = -1;
		}
		else
		{
			flag = 1;
		}
		string si;
		cin >> si;
		for (int i = 0; i < si.size(); ++i)
		{
			bool f = false;
			if (flag == -1 && (si[i] == 'q' || si[i] == 'a' || si[i] == 'z'))
				continue;
			if (flag == 1 && (si[i] == 'p' || si[i] == ';' || si[i] == '/'))
			{
				continue;
			}
			for (int j = 0; j < 3 && !f; ++j)
			{
				for (int k = 0; k < s[j].size(); ++k)
				{
					if (si[i] == s[j][k])
					{
						si[i] = s[j][k + flag];
						f = true;
						break;
					}
				}
			}
		}
		cout << si << endl;
	}
	return 0;
}