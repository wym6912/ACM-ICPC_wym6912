#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>

using namespace std;

typedef long long ll;

const int maxn = 100003;
const int maxm = 100003;

template <class T>
inline bool scan_d(T & ret)
{
	char c;
	int sgn;
	if(c = getchar(), c == EOF)return false;
	while(c != '-' && (c < '0' || c > '9'))c = getchar();
	sgn = (c == '-') ? -1 : 1;
	ret = (c == '-') ? 0 : (c - '0');
	while(c = getchar(), c >= '0' && c <= '9')
		ret = ret * 10 + (c - '0');
	ret *= sgn;
	return true;
}

inline bool scan_ch(char &ch)
{
	if(ch = getchar(), ch == EOF)return false;
	while(ch == ' ' || ch == '\n')ch = getchar();
	return true;
}

inline void out_number(ll x)
{
	if(x < 0)
	{
		putchar('-');
		out_number(- x);
		return ;
	}
	if(x > 9)out_number(x / 10);
	putchar(x % 10 + '0');
}

int n, m, u;

struct query
{
	int l, r, id;
	bool operator < (const query &b) const
	{
		return l / u < b.l / u || (l / u == b.l / u && r < b.r);
	}
}qqqq[maxn];

ll data[maxn], ans[maxn], num[maxn];
ll mp[maxn];

void pre1()
{
	memcpy(mp + 1, data + 1, n * sizeof(ll));
	sort(mp + 1, mp + 1 + n);
	int d = unique(mp + 1, mp + 1 + n) - mp - 1;
	for(int i = 1; i <= n; i ++)
		data[i] = lower_bound(mp + 1, mp + 1 + n, data[i]) - mp;
}

void modui()
{
	ll temp = 0;
	memset(num, 0, sizeof(num));
	int l = 1, r = 0;
	for(int i = 1; i <= m; i ++)
	{
		while(r > qqqq[i].r) 
		{
			temp -= (ll)(num[data[r]] * num[data[r]] * num[data[r]]);
			-- num[data[r]];
			temp += (ll)(num[data[r]] * num[data[r]] * num[data[r]]);
			-- r;
		}
		while(r < qqqq[i].r) 
		{
            ++ r;
			temp -= (ll)(num[data[r]] * num[data[r]] * num[data[r]]);
			++ num[data[r]];
			temp += (ll)(num[data[r]] * num[data[r]] * num[data[r]]);
		}
		while(l > qqqq[i].l) 
		{
			-- l;
			temp -= (ll)(num[data[l]] * num[data[l]] * num[data[l]]);
			++ num[data[l]];
			temp += (ll)(num[data[l]] * num[data[l]] * num[data[l]]);
		}
		while(l < qqqq[i].l) 
		{
			temp -= (ll)(num[data[l]] * num[data[l]] * num[data[l]]);
			-- num[data[l]];
			temp += (ll)(num[data[l]] * num[data[l]] * num[data[l]]);
			++ l;
		}	
		ans[qqqq[i].id] = temp;
	}
}

int main()
{
	while(scan_d(n))
	{
		for(int i = 1; i <= n; i ++)
			scan_d(data[i]);
			//scanf("%I64d", &data[i]);
		pre1();
		scan_d(m);
		//scanf("%d", &m);
		for(int i = 1; i <= m; i ++)
		{
			scan_d(qqqq[i].l);
			scan_d(qqqq[i].r);
			//scanf("%d %d", &qqqq[i].l, &qqqq[i].r);
			qqqq[i].id = i;
		}
		u = (int)sqrt(n * 1.0);
		sort(qqqq + 1, qqqq + 1 + m);
		modui();
		for(int i = 1; i <= m; i ++)
			//printf("%I64d\n", ans[i]);
			out_number(ans[i]), puts("");
	}
	return 0;
}
