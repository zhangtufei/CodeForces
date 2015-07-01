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
	//streambuf * backup;
	//fstream fin;
	//fin.open("data.txt");
	//backup = cin.rdbuf();
	//cin.rdbuf(fin.rdbuf());
	int a[110], n;
	while (cin >> n)
	{
		int min = 0,maxi=10000;
		cin >> a[1];
		cin >> a[2];
		min = a[2] - a[1];
		for (int i = 3; i <= n; ++i)
		{
			cin >> a[i];
			if (a[i] - a[i - 1] > min)
				min = a[i] - a[i - 1];
			if (a[i] - a[i - 2] < maxi)
				maxi = a[i] - a[i - 2];
		}
		if (min > maxi)
			cout << min << endl;
		else
			cout << maxi << endl;
	}
	//cin.rdbuf(backup);
	return 0;
}