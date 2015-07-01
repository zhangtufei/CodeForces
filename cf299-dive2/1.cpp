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
string ten[] = { "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
string intwo[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
int main()
{
	//streambuf *bk;
	//fstream fin;
	//fin.open("dataA.txt");
	//bk = cin.rdbuf();
	//cin.rdbuf(fin.rdbuf());
	int s;
	while (cin >> s)
	{
		if (s < 20)
		{
			cout << intwo[s] << endl;
		}
		else
		{
			cout << ten[s/10-1];
			if (s % 10)
			{
				cout << '-' << intwo[s % 10];
			}
			cout << endl;
		}
	}
	
	//cin.rdbuf(bk);
	return 0;
}