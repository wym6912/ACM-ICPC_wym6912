#include <bits/stdc++.h>

using namespace std;

struct node
{
	double a, b;
	bool operator < (const node &x)const 
	{
		return a * x.b < b * x.a;
	}
};

node data[1009];

int main()
{
	int n;
	double p, ans = 0.0;
	scanf("%d%lf", &n, &p);
	for(int i = 1; i <= n; i ++)
		scanf("%lf", &data[i].a);
	for(int i = 1; i <= n; i ++)
		scanf("%lf", &data[i].b);
	sort(data + 1, data + 1 + n);
	for(int i = 1; i <= n; i ++)
	{
		if(data[i].a <= p)
		{
			ans += data[i].b;
			p -= data[i].a;
		}
		else
		{
			if(p == 0.0)
				break;
			else 
			{
				ans += data[i].b * p / data[i].a;
				break;
			}
		}
	}
	printf("%.2f\n", ans);
	return 0;
}
/*
3 20
18 15 10
75 72 45
*/
