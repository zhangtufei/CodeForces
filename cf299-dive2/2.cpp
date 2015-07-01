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
	long long n;
	while (cin >> n)
	{
		int temp = n%10;
		long long re = 0;
		int i = 0;
		if (temp == 4)
			re += 1;
		else
			re += 2;
		n /= 10;
		if (n == 0)
		{
			cout << re << endl;
			continue;
		}
		temp = n % 10;
		int x = 2;
		while (temp)
		{
			++i;
			if (temp==7)
			{
				re += x;
			}
			n /= 10;
			if (n == 0)
			{
				int y = 2;
				for (int j = 1; j <= i; ++j)
				{
					re += y;
					y *= 2;
				}
				cout << re << endl;
				break;
			}
			x *= 2;
			temp = n % 10;
		}
	}
	
	//cin.rdbuf(bk);
	return 0;
}