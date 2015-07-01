#include <iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int a[100010];
		int temp;
		a[0] = 0;
		for (int i = 1; i <= n; ++i)
		{
			cin >> temp;
			a[i] = a[i - 1] + temp;
		}
		int m;
		cin >> m;
		while (m--)
		{
			int q;
			cin >> q;
			for (int i = 1; i <= n; ++i)
			{
				if (q <= a[i])
				{
					cout << i << endl;
					break;
				}
			}
		}
	}
	return 0;
}