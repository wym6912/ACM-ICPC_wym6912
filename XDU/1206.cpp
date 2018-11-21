#include <bits/stdc++.h>

using namespace std;
char s[50];


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

template <class T>
inline void out_number(T x)
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

__int128 zh, nx, xun, l, r, n, m; 

__int128 gcd(__int128 a, __int128 b)
{ 
	return b == 0 ? a : gcd(b, a % b);
}

__int128 abss(__int128 &x)
{
	if(x < 0) return -x;
	return x;
}

struct Fraction{
	__int128 num, den;
	Fraction(__int128 num = 0, __int128 den = 1){
		if(den < 0){
			num = -num;
			den = -den;
		}
		//assert(den!=0); 
		__int128 g = gcd(abss(num), den); 
		this -> num = num / g;
		this -> den = den / g;
	}
	void out()
	{
		out_number(num);
		putchar('/');
		out_number(den);
		puts("");
	} 
	Fraction operator +(const Fraction &o) const{
		return Fraction(num*o.den+den*o.num,den*o.den);
	}
}; 


__int128 ppow10(__int128 a)
{
	__int128 b = 1;
	for(int i = 1;i <= a;i ++)
		b *= 10;
	return b; 
} 


__int128 tonum(int l, int r)
{
	__int128 res = 0;
	while(l < r)
	{ 
		res = s[l ++] - '0' + res * 10;
		
	} 
	return res;
}

void pre()
{
	l = r = 0;
	while(s[++ r]!= '.'&& r < strlen(s));
	zh = tonum(l, r);
	l = r + 1; 
	while(s[++ r] != '_' && r < strlen(s));
	if(l == r) 
	{	
		nx = 0;
		n = 0;
	} 
	else 
	{
		nx = tonum(l, r);
		n = r - l;
	} 
	l = r + 1; 
	if(r == strlen(s)) 
	{
		xun = 0;
		m = 1;
	} 
	else 
	{
		while(s[++ r] != '.' && r < strlen(s)); 
		xun = tonum(l, r);
		m = r - l; 
	} 
} 

int main()
{
	//freopen("1206.out", "w", stdout);
	
	while(scanf("%s",s)==1)
	{
		pre();
		/*
		printf("整数部分: ");
		out_number(zh);
		printf(", 不循环小数部分: ");
		out_number(nx);
		printf(", 长度: ");
		out_number(n);
		printf(", 循环小数部分: ");
		out_number(xun);
		printf(", 长度: ");
		out_number(m);
		puts("");
		*/
		Fraction x(zh, 1), y(nx, ppow10(n)),
		z(xun, (ppow10(xun == 0 ? 1 : m) - 1) * ppow10(n));
		Fraction ans = x + y + z;
		//x.out();
		//y.out();
		//z.out();
		ans.out();
		
	}
	return 0;
}
