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
//int car[110][110];
int main()
{
	//streambuf *bk;
	//fstream fin;
	//fin.open("dataB.txt");
	//bk = cin.rdbuf();
	//cin.rdbuf(fin.rdbuf());
	string s, t;
	while (cin >> s>>t)
	{
		int n = s.size();
		string q = s;
		int flag = 0;
		int num = 0;
		//int equl = 0;
		//int temp;
		for (int i = 0; i < n; ++i)
		{
			if (s[i] != t[i])
			{
				if (!flag)
				{
					q[i] = t[i];
					flag = 1;
				}
				else
					flag = 0;
				++num;
			}
			//else if (!equl)
			//{
			//	temp = i;
			//}
		}
		if (num % 2 == 0)
		{
			cout << q << endl;
		}
		else
		{
			cout << "impossible" << endl;
		}
	}

	//cin.rdbuf(bk);
	return 0;
}