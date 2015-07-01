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
	//streambuf * backup;
	//fstream fin;
	//fin.open("data.txt");
	//backup = cin.rdbuf();
	//cin.rdbuf(fin.rdbuf());
	int n;
	while (cin >> n)
	{
		int a[1010];
		char c;
		int min=10, j;
		for (int i = 0; i < n; ++i)
		{
			cin >> c;
			a[i] = c - 0x30;
		}
		if (n == 1)
		{
			cout << 0 << endl;
			continue;
		}
		int mint = 10 - a[0];
		min = (a[1] + mint) % 10;
		j = 0;
		for (int i = 1; i < n; ++i)
		{
			int t = 10 - a[i], flag = 1;
			int temp = (a[(i + flag)%n] + t) % 10;
			if (temp < min)
			{
				min = temp;
				j = i;
				mint = t;
			}
			else if (temp == min)
			{
				++flag;
				while (a[(j + flag) % n] == a[(i + flag) % n]&&flag<=n)
				{
					++flag;
				}
				int t1 = min;
				while (temp == t1&&flag<=n)
				{
					temp = (a[(i + flag)%n] + t) % 10;
					t1 = (a[(j + flag)%n] + mint) % 10;
					++flag;
				}
				if (temp < t1)
				{
					mint = t;
					j = i;
				}
			}
		}
		cout << 0;
		++j;
		for (int i =1; i < n; ++i)
		{
			cout << (a[(j++)%n] + mint) % 10;
		}
		cout << endl;
	}
	//cin.rdbuf(backup);
	return 0;
}