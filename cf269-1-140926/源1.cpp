#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
struct prb
{
	int id;
	int dif;
};
bool Comp(prb a, prb b)
{
	return a.dif < b.dif;
}
int main()
{
	int n;
	while (cin >> n)
	{
		map<int, int> m;
		prb a[2010];
		int temp;
		for (int i = 1; i <= n; ++i)
		{
			cin >> a[i].dif;
			a[i].id = i;
			++m[a[i].dif];
		}
		sort(a + 1, a + n + 1, Comp);
		map<int, int>::iterator iter = m.begin();
		int flag;
		int x[2] = { 0, 0 }, y = 0, t = 0;
		bool su = false;
		for (; iter != m.end(); ++iter)
		{
			flag = iter->second;
			if (flag >= 2)
			{
				if (flag >= 3)
					y = iter->first;
				else
					x[t++] = iter->first;
				if (t == 2||y)
					break;
			}
		}
		if (y || t == 2)
		{
			cout << "YES" << endl;
			if (y)
			{
				for (int j = 0; j < 3; ++j)
				{
					bool first = true;
					for (int i = 1; i <= n; ++i)
					{
						if (a[i].dif == y&&first)
						{
							if (i == n - 2)
								cout << a[i].id << ' ' << a[i + 1].id << ' ' << a[i + 2].id << endl;
							else
								cout << a[i].id << ' ' << a[i + 1].id << ' ' << a[i + 2].id << ' ';
							int temp = a[i].id;
							a[i].id = a[i + 1].id;
							a[i + 1].id = a[i + 2].id;
							a[i + 2].id = temp;
							i += 2;
							first = false;
							continue;
						}
						if (i != n)
							cout << a[i].id << ' ';
						else
							cout << a[i].id << endl;
					}
					first = true;
				}
			}
			else
			{
				int tt = 0;
				for (int j = 0; j < 3; ++j)
				{
					for (int i = 1; i <= n; ++i)
					{
						if (a[i].dif == x[tt])
						{
							if (i == n - 1)
								cout << a[i].id << ' ' << a[i + 1].id << endl;
							else
								cout << a[i].id << ' ' << a[i + 1].id << ' ';
							int temp = a[i].id;
							a[i].id = a[i + 1].id;
							a[i + 1].id = temp;
							i += 1;
							continue;
						}
						if (i != n)
							cout << a[i].id << ' ';
						else
							cout << a[i].id << endl;
					}
					if (++tt == 2)
						tt = 0;
				}
			}
		}
		else
			cout << "NO" << endl;
	}
	return 0;
}