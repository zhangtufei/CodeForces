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
	int k;
	string q;
	while (cin >> k)
	{
		cin >> q;
		if (k == 1)
		{
			cout << "YES" << endl;
			cout << q << endl;
			continue;
		}
		if (k > q.size())
		{
			cout << "NO" << endl;
			continue;
		}
		map<char, int> m;
		vector<string> v;
		string temp = "";
		m[q[0]] = 1;
		temp += q[0];
		for (int i = 1; i < q.size(); ++i)
		{
			if (m[q[i]])
			{
				temp += q[i];
			}
			else
			{
				v.push_back(temp);
				temp = "";
				temp += q[i];
				m[q[i]] = 1;
			}
		}
		if (temp != "")
			v.push_back(temp);
		if (v.size() < k)
			cout << "NO" << endl;
		else
		{
			cout << "YES" << endl;
			int size = 0;
			for (int i = 0; i < k - 1; ++i)
			{
				cout << v[i] << endl;
				size += v[i].size();
			}
			for (int i = size; i < q.size(); ++i)
			{
				cout << q[i];
			}
			cout << endl;
		}
	}
	//cin.rdbuf(bk);
	return 0;
}