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
//int car[110][110];
int main()
{
	streambuf *bk;
	fstream fin;
	fin.open("dataC.txt");
	bk = cin.rdbuf();
	cin.rdbuf(fin.rdbuf());


	cin.rdbuf(bk);
	return 0;
}