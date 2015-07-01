#include <iostream>
#include <map>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		map<int, int> m;
		++m[n];
		for (int i = 0; i < 5; ++i)
		{
			cin >> n;
			++m[n];
		}
		map<int, int>::iterator iter = m.begin();
		bool flag1 = false, flag2 = false;
		for (; iter != m.end(); ++iter)
		{
			if (iter->second >= 4)
			{
				iter->second -= 4;
				flag1 = true;
			}
		}
		for (iter=m.begin(); iter != m.end(); ++iter)
		{
			if (iter->second == 2)
			{
				flag2 = true;
			}
		}
		if (flag1)
		{
			if (flag2)
				cout << "Elephant" << endl;
			else
				cout << "Bear" << endl;
		}
		else
			cout << "Alien" << endl;
	}
	return 0;
}