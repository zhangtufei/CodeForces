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
	//fin.open("dataC.txt");
	//bk = cin.rdbuf();
	//cin.rdbuf(fin.rdbuf());
	int A, b, n;
	while (cin >> A >> b >> n)
	{
		while (n--)
		{
			int l, t, m;
			cin >> l >> t >> m;
			int a = (l - 1)*b + A;
			if (t <a)
			{
				cout << -1 << endl;
				continue;
			}
			long long sum = t*m;
			double r;
			double temp = 2 * sum / b + (2 * a - b)*(2 * a - b) / (4 * b*b);
			temp = sqrt(temp);
			r = temp - (2 * a - b) / (2 * b);
			int re = r;
			re /= b;
			if (re == 0)
			{
				re = 1;
			}
			re = l + re - 1;
			cout << re << endl;
		}
	}
	//cin.rdbuf(bk);
	return 0;
}