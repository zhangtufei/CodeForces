#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits.h>
#include <limits>
#include <iosfwd>
using namespace std;
int main()
{
	int k;
	while (cin >> k)
	{
		string s[6] = { "+------------------------+",
			"|#.#.#.#.#.#.#.#.#.#.#.|D|)",
			"|#.#.#.#.#.#.#.#.#.#.#.|.|",
			"|#.......................|",
			"|#.#.#.#.#.#.#.#.#.#.#.|.|)",
			"+------------------------+", };
		if (k > 4)
		{
			for (int i = 1; i <= 4; ++i)
				s[i][1] = 'O';
		}
		else
		{
			for (int i = 1; i <= k;++i)
				s[i][1] = 'O';
			for (int i = 0; i < 6; ++i)
				cout << s[i] << endl;
			continue;
		}
		k -= 4;
		int temp = k / 3;
		k %= 3;
		for (int i = 1; i <= temp; ++i)
		{
			for (int j = 1; j <= 4; ++j)
			{
				if (j == 3)
					++j;
				s[j][1 + 2 * i] = 'O';
			}
		}
		if (k == 1)
		{
			s[1][3+ temp * 2] = 'O';
		}
		else if (k == 2)
		{
			s[1][3+ temp * 2] = 'O';
			s[2][3 + temp * 2] = 'O';
		}
		for (int i = 0; i < 6; ++i)
			cout << s[i] << endl;
	}
	return 0;
}