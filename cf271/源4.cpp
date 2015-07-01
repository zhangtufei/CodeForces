#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
struct Node
{
	int data;
	Node *next;
};
Node * test(Node *head)
{
	Node *p1 = head;
	Node *p2 = head->next;
	while (p2)
	{
		p1->next = p2->next;
		p2->next = head;
		head = p2;
		p2 = p1->next;
	}
	Node *p3 = new Node();
	p1->data = 0;
	p1->next = head;
	return p1;
}
void main()
{
	Node *head=new Node();
	Node *p1 = head;
	for (int i = 0; i < 5; ++i)
	{
		p1->next = new Node();
		cin >> p1->next->data;
		p1->next->next = NULL;
		p1 = p1->next;
	}
	p1 = head->next;
	while (p1)
	{
		cout << p1->data<<' ';
		p1 = p1->next;
	}
	cout << endl;
	head= test(head);
	p1 = head->next;
	int flag = 5;
	while (p1&&flag)
	{
		--flag;
		cout << p1->data<<' ';
		Node *p2 = p1;
		p1 = p1->next;
		delete p2;
	}
	cout << endl;

}
//int getMaxComStr(char *pcSrc1,char *pcSrc2,char **ppDst1,char **ppDst2)
//{
//	int max = 0;
//	char *pd1=0, *pd2=0;
//	while (*pcSrc1)
//	{
//		char *p1 = pcSrc1, *p2 = pcSrc2;
//		int temp = 0;
//		while (*p2)
//		{
//			while (*p2 != *p1&&*p2&&*p1)
//				++p2;
//			char *pt = p2;
//			 while(*p2 == *p1&&*p1&&*p2)
//			{
//				++p2; 
//				++p1;
//				++temp;
//				if (temp > max)
//				{
//					max = temp;
//					pd1 = pcSrc1;
//					pd2 = pt;
//				}
//			}
//			 temp = 0;
//		}
//		++pcSrc1;
//	}
//
//	*ppDst1 = pd1;
//	*ppDst2 = pd2;
//	return max;
//}
//int main()
//{
//	char s1[] = "abccade";
//	char s2[] = "dgcadde";
//	char *pDst1;
//	char *pDst2;
//	int t = getMaxComStr(s1, s2, &pDst1,& pDst2);
//	cout << t << pDst1 << pDst2 << endl;
//	return 0;
//}

//double coin_in;
//int main()
//{
//	char *s = "abc";
//	do
//	{
//		cout << *s++ % 10;
//	} while (*s);
	//cout << "输入4张扑克牌（1、2、3、4、5、6、7、8、9、10、J、Q、K）,逗号分开"<<endl;
	//while (1)
	//{
	//	string s, s1[4], temp;
	//	cin >> s; //因为有J Q K，所以不能用整形，因为有10，所以不能用char
	//	temp = "";
	//	int flag = 0; 
	//	for (int i = 0; i < s.size(); ++i)
	//	{
	//		if (s[i] == ',')
	//		{
	//			s1[flag++] = temp;
	//			temp = "";
	//			continue;
	//		}
	//		temp += s[i];
	//	}
	//	s1[flag] = temp;
	//	for (int i = 0; i < 4; ++i)
	//	{
	//		for (int j = 0; j < 4; ++j)
	//		{
	//			if (j == i)
	//				continue;
	//			for (int k = 0; k < 4; ++k)
	//			{
	//				if (k == i || k == j)
	//					continue;
	//				for (int z = 0; z < 4; ++z)
	//				{
	//					if (z == i || z == j || z == k)
	//						continue;
	//					cout << s1[i] << ' ' << s1[j] << ' ' << s1[k] << ' ' << s1[z] << endl;
	//				}
	//			}
	//		}
	//	}
	//}
//}
//struct custom_sel
//{
//	int id;
//	double price;
//};
//int snack_out;
//double coin_out;
//1.coin_in<custom_sel.price
//2.id不存在，或者id对应商品已售完
//3、每次snack out后，coin_in是否等于coin_in-custom_sel.price
//4、coin_out是否一直等于coin_in
//5、
//int main()
//{
//	string logo;
//	while (getline(cin,logo))
//	{
//		string http;
//		for (int i = logo.size() - 1; i >= 0; --i)
//		{
//
//		}
//	}
//}
//bool Comp(int x, int y)
//{
//	return x > y;
//}
//int solve(int *array, int m, int n)
//{
//	int *a = new int[m];
//	for (int i = 0; i < m; ++i)
//		a[i] = array[i];
//	sort(a, a + m, Comp);
//	return a[n-1];
//}
//int main()
//{
//	int n, m,array[10];
//	cin >> m >> n;
//	for (int i = 0; i < m; ++i)
//	{
//		cin >> array[i];
//	}
//	int ans = solve(array, m, n);
//	cout << ans<<endl;
//	system("pause");
//	return 0;
//}
//long long h[100010];
//long long d[100010];
//int main()
//{
//	int t, k;
//	cin >> t >> k;
//	long long temp = 0;
//	d[0] = 0;
//	for (int i = 1; i < k; ++i)
//	{
//		h[i] = 1;
//		temp += h[i];
//		//if (temp >= 1000000007)
//		//	temp %= 1000000007;
//		d[i] = temp;
//	}
//	h[k] = 2;
//	temp += 2;
//	//if (temp >= 1000000007)
//	//	temp %= 1000000007;
//	d[k] = temp;
//	for (int i = k + 1; i <= 100000; ++i)
//	{
//		h[i] = h[i - k] + h[i - 1];
//		if (h[i] >= 1000000007)
//			h[i] %= 1000000007;
//		temp += h[i];
//		if (temp >= 1000000007)
//			temp %= 1000000007;
//		d[i] = temp;
//	}
//	while (t--)
//	{
//		int a, b;
//		cin >> a >> b;
//		long long t = d[b]-d[a-1];
//		if (t < 0)
//		{
//			t += 1000000007;
//		}
//		cout << t<< endl;
//		//if (k > b)
//		//{
//		//	cout << b - a + 1 << endl;
//		//	continue;
//		//}
//		//long long sum = 0;
//		////for (int i = a; i <= b; ++i)
//		////{
//		////	sum += h[i];
//		////	if (sum >= 1000000007)
//		////		sum %= 1000000007;
//		////}
//		//if (a <= k)
//		//{
//		//	sum += (k - a);
//		//	sum += 2;
//		//	for (int i = k + 1; i <= b; ++i)
//		//	{
//		//		sum += h[i];
//		//		if (sum >= 1000000007)
//		//			sum %= 1000000007;
//		//	}
//		//}
//		//else
//		//{
//		//	for (int i = a; i <= b; ++i)
//		//	{
//		//		sum += h[i];
//		//		if (sum >= 1000000007)
//		//			sum %= 1000000007;
//		//	}
//		//}
//		//for (int i = k + 1; i <= b; ++i)
//		//{
//		//	h[i] = h[i - k] + h[i - 1];
//		//	if (h[i] >= 1000000007)
//		//		h[i] %= 1000000007;
//		//	if (i >= a)
//		//	{
//		//		sum += h[i];
//		//		if (sum >= 1000000007)
//		//			sum %= 1000000007;
//		//	}
//		//}
//		//cout << sum << endl;
//	}
//	return 0;
//}