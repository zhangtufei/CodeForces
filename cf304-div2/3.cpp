#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <streambuf>
#include <utility>
using namespace std;
int main()
{
	streambuf *bk;
	fstream fin;
	fin.open("dataC.txt");
	bk = cin.rdbuf();
	cin.rdbuf(fin.rdbuf());
	int n;
	while (cin >> n)
	{
		int k1, k2;
		string ko, kt;
		cin >> k1;
		getline(cin, ko);
		cin >> k2;
		getline(cin, kt);
		if (ko[0]==' ')
			ko = ko.substr(1, ko.size());
		if (kt[0]==' ')
			kt = kt.substr(1, kt.size());
		int len1 = ko.size(), len2 = kt.size();
		int re = 0;

		map<pair<string, string>, int> ma;
		ma[make_pair(ko, kt)] = 1;
		bool flag = true;
		while (len1&&len2)
		{	
			int c1, c2;
			if (ko[1] == ' ')
				c1 = ko[0] - '0';
			else
				c1 = 10;
			if (kt[1] == ' ')
				c2 = kt[0] - '0';
			else
				c2 = 10;
			if (c1 > c2)
			{
				ko = ko + ' ' + c2 + ' ' +c1 ;
				ko = ko.substr(2, ko.size());
				kt = kt.substr(1, kt.size());
				if(kt.size()>1)
					kt = kt.substr(1, kt.size());
			}
			else
			{
				
				kt = kt+ ' ' + c1 + ' ' + c2;
				kt = kt.substr(2, kt.size());
				ko = ko.substr(1, ko.size());
				if (ko.size()>1)
					ko = ko.substr(1, ko.size());
			}
			if (ma[make_pair(ko,kt)])
			{
				flag = false;
				break;
			}
			ma[make_pair(ko, kt)] = 1;
			++re;
			len1 = ko.size();
			len2 = kt.size();
		}
		if (flag)
		{
			cout << re;
			if (len1)
				cout << ' ' << 1 << endl;
			else
				cout << ' ' <<2 << endl;
		}
		else
			cout << -1 << endl;
	}
	cin.rdbuf(bk);
	return 0;
}