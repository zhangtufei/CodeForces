#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>
#include <iomanip>
using namespace std;
long long a[1010];
int main()
{
	long long n, l;
	while (cin >> n >> l)
	{
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		sort(a + 1, a + n + 1);
		long long res = (a[1] - 0 > l - a[n]) ? (a[1] - 0) : (l - a[n]);
		res *= 2;
		for (int i = 2; i <= n; ++i)
		{
			if (a[i] - a[i - 1] > res)
				res = a[i] - a[i - 1];
		}
		double ans = res / 2.0;
		cout.precision(10);
		cout <<fixed<< ans << endl;
	}
}