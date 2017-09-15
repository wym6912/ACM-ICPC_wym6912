//#define NOSTDCPP
#ifndef NOSTDCPP

#include <bits/stdc++.h>

#else

#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <stack>

#endif

# define RESET(_) memset(_, 0, sizeof(_))

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef set <int> si;

const int MOD = 1e9 + 7;
const int maxn = 300009;
const int maxm = 300009;
const double pi = acos(-1.0);

int main()
{
	int x;
	while(~ scanf("%d", &x))
	{
		bool flag = false;
		for(int i = 1;i <= 10000;i ++)
			if((x * i + 18) % 65 == 0)
			{
				flag = true;
				printf("%d\n", i);
				break;
			}
		flag == false ? printf("no\n") : (flag);
	}
	return 0;
}

