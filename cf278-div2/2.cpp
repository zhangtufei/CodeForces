#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>
using namespace std;
int box[5];
int main()
{
	int n;
	while (cin >> n)
	{
		int m1=0;
		for (int i = 1; i <= n; ++i)
		{
			cin >> box[i];
			m1 += box[i];
		}
		if (n == 4)
		{
			int m2 = (box[2] + box[3]) / 2;
			int m3 = box[4] - box[1];
			m1 /= 4;
			if (m1 == m2&&m1 == m3)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		else if (n == 3)
		{
			int m2 = (box[2] + box[3])/2;
			box[4] = box[1] + m2;
			m1 += box[4];
			m1 /= 4;
			int m3 = box[4] - box[1];
			if (m1 == m2&&m1 == m3)
			{
				cout << "YES" << endl;
				cout << box[4] << endl;
			}
			else
			{
				cout << "NO" << endl;
			}
		}
		else if (n == 2)
		{
			if (box[2] + 1 == 2 * box[1])
			{
				cout << "YES" << endl;
				box[3] = box[2] + 2;
				box[4] = box[1] + box[2] + 1;
				cout << box[3] << endl << box[4] << endl;
			}
			else if (box[2] = 2 * box[1])
			{
				cout << "YES" << endl;
				box[3] = box[2];
				box[4] = box[1]*3;
				cout << box[3] << endl << box[4] << endl;
			}
			else
				cout << "NO" << endl;
		}
		else if (n == 1)
		{
			cout << "YES" << endl;
			box[2] = box[1] * 2 - 1;
			box[3] = box[2] + 2;
			box[4] = box[1] + box[2] + 1;
			cout <<box[2]<<endl<< box[3] << endl << box[4] << endl;
		}
	}
	return 0;
}