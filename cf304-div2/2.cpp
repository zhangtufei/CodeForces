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
	//streambuf *bk;
	//fstream fin;
	//fin.open("dataB.txt");
	//bk = cin.rdbuf();
	//cin.rdbuf(fin.rdbuf());
	int n;
	while (cin >> n)
	{
		map<int, int> ma;
		int temp;
		long long re = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> temp;
			while (ma[temp])
			{
				++temp;
				++re;
			}
			ma[temp] = 1; 
		}
		cout << re << endl;
		//map<int, int>::iterator iter = ma.begin();
		//for (; iter != ma.end(); ++iter)
		//{
		//	while(iter->second > 1)
		//	{
		//		temp = iter->first;
		//		while (ma[temp])
		//		{
		//			++temp;
		//			++re;
		//		}
		//		ma[temp] = 1;
		//		--iter->second;
		//	}
		//}
	}
	//cin.rdbuf(bk);
	return 0;
}