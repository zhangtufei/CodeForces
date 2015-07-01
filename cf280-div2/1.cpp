#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>
using namespace std;
long long a[101], b[101];
int main()
{
	a[1] = 1;
	b[1] = 1;
	for (int i = 2; i <= 100; ++i)
	{
		a[i] = a[i - 1] + i;
		b[i] = b[i - 1] + a[i];
	}
	int n;
	while (cin >> n)
	{
		for (int i = 1; i <= 100; ++i)
		{
			if (b[i] > n)
			{
				cout << i - 1 << endl;
				break;
			}
		}
	}
	return 0;
}