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
	//streambuf *bk;
	//fstream fin;
	//fin.open("dataA.txt");
	//bk = cin.rdbuf();
	//cin.rdbuf(fin.rdbuf());
	long long k, n, w;
	while (cin >> k >> n >> w)
	{
		long long re = w*(w + 1)*k / 2;
		if (re - n <= 0)
			cout << 0 << endl;
		else
			cout << re - n << endl;
	}

	//cin.rdbuf(bk);
	return 0;
}