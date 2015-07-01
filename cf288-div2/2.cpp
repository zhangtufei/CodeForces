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
	string n;
	while (cin >> n)
	{
		int num, p1,p2,pt;
		if (n.size() == 2)
		{
			if (n[1] == '0')
			{
				cout << -1 << endl;
			}
			else
			{
				if ((n[1] - '0') % 2 == 0)
				{
					if ((n[0] - '0') % 2 == 1)
						cout << -1 << endl;
					else
						cout << n[1] << n[0] << endl;
				}
				else
				{
					if ((n[0] - '0') % 2 == 0)
						cout << n[1] << n[0] << endl;
					else
						cout << -1 << endl;
				}
			}
			continue;
		}
		if ((n[n.size() - 1] - '0') % 2 == 0)
		{
			p1 = n.size() - 2;
			p2 = p1;
			bool flag = false;
			while (p2 >= 1 )
			{
				if (n[p2] > n[p2 - 1])
				{
					p1 = p2;
					p2 = p1 - 1;
					flag = true;
					break;
				}
				--p2;
			}
			if (flag)
			{
				for (int i = 0; i <= p2; ++i)
				{
					if (n[i] <= n[p2])
					{
						p2 = i;
						pt = p1;
						for (int j = p2 + 1; i <= pt; ++i)
						{
							if (n[i] > n[p1])
								p1 = i;
						}
						for (int j = n.size() - 2; j >= pt; --j)
						{
							if (n[j] >= n[p1])
							{
								p1 = j;
								break;
							}
						}
						break;
					}
				}
				if (n[p1] <= n[n.size() - 1] && (n[p2] - '0') % 2 == 0)
				{
					p1 = n.size() - 1;
				}
				for (int i = 0; i <= p2; ++i)
				{
					if ((n[i] - '0') % 2 == 0 && n[i] < n[n.size() - 1])
					{
						p2 = i;
						p1 = n.size() - 1;
						break;
					}
				}
			}
			else
			{
				if ((n[n.size() - 2] - '0') % 2 == 0)
				{
					p2 = n.size() - 2;
					p1 = n.size() - 1;
				}
				else
				{
					p2 = n.size() - 3;
					p1 = n.size() - 2;
				}
			}
			char c = n[p1];
			n[p1] = n[p2];
			n[p2] = c;
			cout << n << endl;
		}
		else
		{
			bool flag = false;
			p1 = n.size() - 1;
			for (int i = n.size() - 2; i >= 0; --i)
			{
				if ((n[i] - '0') % 2 == 0)
				{
					p2 = i;
					flag = true;
					break;
				}
			}
			for (int i = 0; i <=n.size()-2; ++i)
			{
				if ((n[i] - '0') % 2 == 0 && n[i] < n[p1])
				{
					p2 = i;
					break;
				}
			}
			if (flag)
			{
				char c = n[p1];
				n[p1] = n[p2];
				n[p2] = c;
				cout << n << endl;
			}
			else
				cout << -1 << endl;
		}
	}
	//cin.rdbuf(bk);
	return 0;
}