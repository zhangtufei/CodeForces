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
	//fin.open("dataA.txt");
	//bk = cin.rdbuf();
	//cin.rdbuf(fin.rdbuf());
	int n;
	while (cin >> n)
	{
		if (n == 1)
			cout << 1 << endl << 1 << endl;
		else if (n == 2)
			cout << 1 <<endl<<1<< endl;
		else if (n == 3)
			cout << 2 << endl << "1 3" << endl;
		else if (n == 4)
			cout << 4 << endl << "3 1 4 2" << endl;
		else
		{
			cout << n << endl;
			int i = 1;
			while (i <= n - 1)
			{
				cout << i << ' ';
				i += 2;
			}
			i = 2;
			if (n % 2 == 0)
			{
				while (i <= n - 1)
				{
					cout << i << ' ';
					i += 2;
				}
				cout << n << endl;
			}
			else
			{
				cout << n << ' ';
				while (i <= n - 3)
				{
					cout << i << ' ';
					i += 2;
				}
				cout << n - 1 << endl;
			}
		}
	}
	//cin.rdbuf(bk);
	return 0;
}