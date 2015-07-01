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
	int v1, v2, t, d;
	int speed[110];
	while (cin >> v1 >> v2)
	{
		cin >> t >> d;
		speed[1] = v1;
		speed[t] = v2;
		int i = 1;
		while (speed[i] + d <= v2&&i < t - 1)
		{
			speed[i + 1] = speed[i] + d;
			++i;
		}
		if (i != t - 1)
		{
			int temp = (t - i-1)*d + v2;
			while (speed[i] + d <= temp&&i<t-1)
			{
				speed[i + 1] = speed[i] + d;
				++i;
				temp -= d;
			}
			speed[i + 1] = temp;
			i += 2;
			for (; i < t; ++i)
			{
				speed[i] = speed[i - 1] - d;
			}
		}
		long long m=0;
		for (int i = 1; i <= t; ++i)
			m += speed[i];
		cout << m << endl;
	}

	//cin.rdbuf(bk);
	return 0;
}