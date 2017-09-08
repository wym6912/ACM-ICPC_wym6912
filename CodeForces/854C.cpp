#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct node
{
	ll num;
	int place;
	friend bool operator < (const node &a, const node &b)
	{
		return a.num < b.num;
	}
}flight[300009];

int pp[300009];

priority_queue <node> pq;

int main()
{
	ios::sync_with_stdio(false);
	int n, m, ans, k, p;
	ll sum;
	while(cin >> n >> m)
	{
		sum = 0;
		ans = 0;
		k = m + 1;
		while(! pq.empty()) pq.pop();
		for(int i = 1;i <= n;i ++)
			cin >> flight[i].num, flight[i].place = i;
		for(int i = 1;i <= m;i ++)
			pq.push(flight[i]);
		while(! pq.empty())
		{
			if(k <= n) pq.push(flight[k]);
			flight[0] = pq.top();
			pq.pop();
			sum += flight[0].num * (k - flight[0].place);
			pp[flight[0].place] = k;
			k ++;
		}
		cout << sum << endl;
		for(int i = 1;i <= n;i ++)
			cout << pp[i] << ' ';
		cout << endl;
	}
	return 0;
}
