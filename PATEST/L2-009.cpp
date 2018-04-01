#include <bits/stdc++.h>

using namespace std;

struct info
{
	long long data;
	int p;
	int cnt;
	info(){data = 0.0;}
	info(long long data, int p, int cnt) : data(data), p(p), cnt(cnt){}
	bool operator < (const info &b) const
	{
		return data > b.data || (data == b.data && cnt > b.cnt) || 
		(data == b.data && cnt == b.cnt && p < b.p);
	}
};

info x[10009];

int main()
{
	int n, k;
	int p;
	long long d;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)
	{
		scanf("%d", &k);
		x[i].p = i;
		while(k --)
		{
			scanf("%d %lld", &p, &d);
			x[p].data += d;
			x[i].data -= d;
			x[p].cnt ++;
		}
	}
	sort(x + 1, x + 1 + n);
	for(int i = 1; i <= n; i ++)
		printf("%d %.2f\n", x[i].p, (double)(x[i].data) / 100.0);
	return 0;
}
