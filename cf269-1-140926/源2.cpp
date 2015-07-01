#include <iostream>
using namespace std;
long long h[1000010];
int main()
{
	h[0] = 0;
	h[1] = 2;
	for (int i = 2; i <= 1000000; ++i)
	{
		h[i] = h[i - 1] + (i - 1) * 3 + 2;
	}
	long long n;
	while (cin >> n)
	{
		if (n <= 2)
			cout << 0 << endl;
		else
		{
			long long k = 0;
			for (long long i = 1; i <= 1000000; ++i)
			{
				if (h[i] > n)
				{
					k = i-1;
					break;
				}
			}
			if ((n - h[k]) % 3 == 1)
				cout << ((k - 2) > 0 ? k - 2 : 0) << endl;
			else if ((n - h[k]) % 3 == 2)
				cout << ((k - 3) > 0 ? k - 3 : 0) << endl;
			else
				cout << k - 1 << endl;
		}
	}
	return 0;
}