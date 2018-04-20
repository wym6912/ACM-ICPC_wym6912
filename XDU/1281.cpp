#include <bits/stdc++.h>

using namespace std;

const int maxn = 4;
const long long mod = 1e9 + 7;

struct matrix
{
	int n;
	long long a[maxn][maxn];
	void clear()
	{
		n = 0;
		memset(a, 0, sizeof(a));
	}
	matrix one()
	{
		matrix tmp;
		tmp.clear();
		tmp.n = n;
		for(int i = 0; i < n; ++ i)
			tmp.a[i][i] = 1;
		return tmp;
	}
	matrix operator * (const matrix &b) const
	{
		matrix tmp;
		tmp.clear();
		tmp.n = n;
		for(int k = 0; k < n; ++ k)
			for(int i = 0; i < n; ++ i)
				for(int j = 0; j < n; ++ j)
					tmp.a[i][j] = (tmp.a[i][j] + a[i][k] * b.a[k][j] + mod) % mod;
		return tmp;
	}
	matrix operator ^ (const long long &k)
	{
		long long b = k;
		matrix tmp, tmp2 = one();
		tmp.n = n;
		for(int i = 0; i < n; ++ i)
			for(int j = 0; j < n; ++ j)
				tmp.a[i][j] = a[i][j];
		while(b)
		{
			if(b & 1)
				tmp2 = tmp * tmp2;
			b >>= 1;
			tmp = tmp * tmp;
		}
		return tmp2;
	}
};

int main()
{
	matrix pol, base, ans;
	pol.clear();
	pol.n = 3;
	pol.a[0][0] = 2; pol.a[0][1] = -1; pol.a[0][2] = 1;
	pol.a[1][0] = 1; pol.a[2][1] = 1;
	base.clear();
	base.n = 3;
	base.a[0][0] = 2;
	base.a[1][0] = 1;
	base.a[2][0] = 1;
	ans.clear();
	long long n;
	while(~ scanf("%lld", &n))
	{
		n ++;
		if(n <= 3)printf("%lld\n", base.a[3 - n][0]);
		else 
		{
			ans.clear();
			ans = (pol ^ (n - 3)) * base;
			printf("%lld\n", ans.a[0][0]);
		}
	}
	return 0;
}
//P(n) = 2 * P(n - 1) - P(n - 2) + P(n - 3)
