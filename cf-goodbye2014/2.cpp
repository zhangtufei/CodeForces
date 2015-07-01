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

struct Node
{
	int num;
	int pos;
	int curp;
};
bool Comp(Node a, Node b)
{
	return a.num < b.num;
}
Node node[310];
int A[310][310];
int main()
{
	//streambuf *backup;
	//fstream fin;
	//fin.open("dataB.txt");
	//backup = cin.rdbuf();
	//cin.rdbuf(fin.rdbuf());
	int n;
	while (cin >> n)
	{
		Node nt[310];
		for (int i = 1; i <= n; ++i)
		{
			cin >> node[i].num;
			node[i].pos = i;
			node[i].curp = i;
			nt[i] = node[i];	
		}
		for (int i = 1; i <= n; ++i)
		{
			char c;
			for (int j = 1; j <= n; ++j)
			{
				cin >> c;
				A[i][j] = c - '0';
			}
		}
		sort(nt + 1, nt + 1 + n, Comp);
		for (int i = 1; i <= n; ++i)
		{
			int pos = nt[i].curp;
			for (int j = 1; j < pos; ++j)
			{
				if (A[pos][j])
				{
					if (node[pos].num < node[j].num)
					{
						Node temp = node[j];
						temp.curp = node[pos].curp;
						nt[i].curp = j;
						for (int z = 1; z <= n; ++z)
						{
							if (nt[z].pos == node[j].pos)
							{
								nt[z].curp = pos;
								break;
							}
						}
						node[j].num = node[pos].num;
						node[j].pos = node[pos].pos;
						node[pos] = temp;
						pos = j;
						j = 1;
					}
				}
			}
		}
		for (int i = 1; i <= n - 1; ++i)
		{
			cout << node[i].num << ' ';
		}
		cout << node[n].num << endl;
	}
	//cin.rdbuf(backup);
	return 0;
}