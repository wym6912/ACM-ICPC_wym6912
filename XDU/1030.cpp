#include <algorithm>
#include <bitset>
#include <cassert>
#include <complex>
#include <cstring>
#include <cstdio>
#include <iomanip>
#include <iostream>

# define RESET(_) memset(_, 0, sizeof(_))
# define RESET_(_, val) memset(_, val, sizeof(_))
# define fi first
# define se second

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int maxn = 300009;
const int maxm = 300009;
const double pi = acos(-1.0);
const double eps = 1e-6;

int data[maxn], n, fir, endd;

int tmp[3];

void print_process(int a, int b, int c)
{
	tmp[0] = a;
	tmp[1] = b;
	tmp[2] = c;
	sort(tmp, tmp + 3);
	printf("%d %d %d\n", tmp[0], tmp[1], tmp[2]);
}

bool nosame(int a, int b, int c)
{
	if(a == b || a == c || b == c)
		return false;
	else return true;
}

int find(int x, int ps)
{
	//cout << data[ps] << ' ' << x << endl;
	int f = ps, t = n + 1, mid = (f + t) >> 1;
	while(f + 1 < t)
	{
		if(data[mid] < x)
			f = mid;
		else if(data[mid] == x)return data[mid];
		else t = mid;
		mid = (f + t) >> 1;
		//cout << f << ' ' << t << ' ' << mid << ' ' << data[mid] << endl;
	}
	//cout << endl;
	return 10000000;
}

bool iszero(int place) //data place
{
	int tmp;
	bool isok = false, ik2 = false;
	for(int i = place + 1, j = 1; i <= n; i ++, j ++)
	{
		int k = find(-(data[i] + data[place]), i);
		if(k != 10000000 && k + data[i] + data[place] == 0)
		{
			print_process(k, data[i], data[place]);
			isok = true;
		}
	}
	return isok;
}

int main()
{
	//freopen("1030.out", "w", stdout);
	while(~ scanf("%d", &n))
	{
		data[0] = data[n + 1] = 100000000;
		bool isok = false;
		for(int i = 1; i <= n; i ++)
			scanf("%d", &data[i]);
		sort(data + 1, data + 1 + n);
		for(int i = 1; i <= n; i ++)
			if(iszero(i))
				isok = true;
		if(! isok)printf("Ren Chou Jiu Gai Duo Du Shu!\n");
	}
	return 0;
}
/*
4
-21 14 9 12
5
-2 -1 0 2 3
23
-24 1 23 2 22 3 21 4 20 5 19 6 18 7 17 8 16 9 15 10 14 11 13
5
-5 -3 -2 0 5
*/
