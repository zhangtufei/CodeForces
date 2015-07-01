#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>
#include <iomanip>
using namespace std;
struct Node
{
	long long p;
	long long b;
};
Node a[100100];
bool Comp(Node x, Node y)
{
	return x.b < y.b;
}
int main()
{
	long long n, r, avg;
	//long long x = 100000 * 1000000;
	//cout << x << endl;
	while (cin >> n)
	{
		cin >> r >> avg;
		long long sum = 0;
		avg *= n;
		for (int i = 1; i <= n; ++i)
		{
			cin >> a[i].p >> a[i].b;
			if (sum < avg)
			{
				sum += a[i].p;
			}
		}
		sort(a + 1, a + n + 1, Comp);
		int flag = 1;
		long long min = 0;
		while (sum < avg)
		{
			if (a[flag].p >= r)
			{
				++flag;
				continue;
			}
			if (a[flag].p<r&&sum + (r - a[flag].p) <= avg)
			{
				sum +=(r - a[flag].p);
				min += ((r - a[flag].p)*a[flag].b);
			}
			else
			{
				long long temp = avg - sum;
				min += (temp*a[flag].b);
				sum = avg;
				//while (sum < avg&&a[flag].p<r)
				//{
				//	min += a[flag].b;
				//	++a[flag].p;
				//	++sum;
				//}
			}
			++flag;
		}
		cout << min << endl;
	}
	return 0;
}