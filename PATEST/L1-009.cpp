#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}

struct Fraction
{
	long long num, den;
	Fraction(long long num = 0, long long den = 1)
	{
		if(den < 0)
		{
			num = -num;
			den = -den;
		}
		assert(den != 0);
		long long g = gcd(abs(num), den);
		this -> num = num / g;
		this -> den = den / g;
	}
	Fraction operator + (const Fraction &o) const
	{
		return Fraction(num * o.den + den * o.num, o.den * den);
	}
	bool operator == (const Fraction &o) const
	{
		return num * o.den == den * o.num;
	}
};

int main()
{
	Fraction ans, read, zero;
	int n;
	scanf("%d", &n);
	while(n --)
	{
		scanf("%lld/%lld", &read.num, &read.den);
		ans = ans + read;
	}
	if(ans == zero)puts("0");
	else 
	{
		if(ans.num / ans.den)
			printf("%lld", ans.num / ans.den);
		if(ans.num / ans.den && ans.num % ans.den)putchar(' ');
		if(ans.num % ans.den)
			printf("%lld/%lld", ans.num % ans.den, ans.den);
		puts("");
	}
	return 0;
}
