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
	//streambuf * buf;
	//fstream fin;
	//fin.open("data.txt");
	//buf = cin.rdbuf();
	//cin.rdbuf(fin.rdbuf());
	int n, x;
	while (cin >> n >> x)
	{
		int st, ed, cur, num;
		cur=1; num = 0;
		while (n--)
		{
			cin >> st >> ed;
			cur = st - (st - cur) % x;
			num += (ed - cur+1);
			cur = ed+1;
		}
		cout << num << endl;
	}
	//cin.rdbuf(buf);
	return 0;
}