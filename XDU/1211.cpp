#include <bits/stdc++.h>

# define RESET(_) memset(_, 0, sizeof(_))
# define RESET_(_, val) memset(_, val, sizeof(_))
# define fi first
# define se second
# define pb push_back
# define midf(x, y) ((x + y) >> 1)

using namespace std;

const int MOD = 1e9 + 7;
const int maxn = 300009;
const int maxm = 300009;

typedef long long ll;
typedef vector <double> vd;

const double eps = 1e-12;
double inf = 1e+6;

inline int sgn(double x)
{
	return x < -eps ? -1 : x > eps;
}

inline double get(const vd &coef, double x)
{
	double e = 1, s = 0;
	for(int i = 0; i < coef.size(); i ++)
		s += coef[i] * e, e *= x;
	return s;
}

double find(const vd &coef, int n, double lo, double hi)
{
	double sgn_lo, sgn_hi;
	if((sgn_lo = sgn(get(coef, lo))) == 0)return lo;
	if((sgn_hi = sgn(get(coef, hi))) == 0)return hi;
	if(sgn_lo * sgn_hi > 0)return inf;
	for(int step = 0; step < 100 && hi - lo > eps; step ++)
	{
		double m = (lo + hi) * .5;
		int sgn_mid = sgn(get(coef, m));
		if(sgn_mid == 0)return m;
		if(sgn_lo * sgn_mid < 0)
			hi = m;
		else lo = m;
	}
	return (lo + hi) * .5;
}

vd equation(vd coef, int n)
{
	vd ret;
	if(n == 1)
	{
		if(sgn(coef[1]))ret.pb(-coef[0] / coef[1]);
		return ret;
	}
	vd dcoef(n);
	for(int i = 0; i < n; i ++) dcoef[i] = coef[i + 1] * (i + 1);
	vd droot = equation(dcoef, n - 1);
	droot.insert(droot.begin(), -inf);
	droot.pb(inf);
	for(int i = 0; i + 1 < droot.size(); i ++)
	{
		double tmp = find(coef, n, droot[i], droot[i + 1]);
		if(tmp < inf)ret.pb(tmp);
	}
	return ret;
}

double c[maxn];

int main()
{
	vd coef, ans;
	int n, p;
	while(~ scanf("%d", &n))
	{
		coef.clear();
		inf = 1e+6;
		for(int i = 1; i <= n; i ++)
		{
			scanf("%lf", &c[i]);
			if(abs(c[i]) > inf)
				inf = abs(c[i]) * 10.0;
		}
		for(int i = n; i >= 1; i --)
			coef.pb(c[i]);
		coef.pb(1.00);
		ans = equation(coef, n);
		vd :: iterator it = unique(ans.begin(), ans.end());
		ans.erase(it, ans.end());
		if(! ans.size())puts("0.00");
		else
		{
			double ans2 = 0.00;
			int anssize = ans.size();
			for(int i = 0; i < anssize; i ++)
			{
				ll tmp1 = floor(ans[i] - eps), tmp2 = ceil(ans[i] + eps);
				if(sgn(get(coef, (double)((tmp1 + tmp2) >> 1) ) == 0))
					ans2 += (tmp1 + tmp2) >> 1;
			}
			printf("%.2f\n", ans2);
		}
	}
	return 0;
}
