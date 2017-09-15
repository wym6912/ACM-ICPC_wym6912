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
	char s[100];
	while(~ scanf("%s",s))
	{
		if(s[0] == 'v')
			printf("SingleDog&YangRouHuoGuo\n");
		if(s[0] == 'q')
			printf("Couple&Program\n");
		if(s[0] == 'l')
			printf("SingleDog&GoodGoodStud\n");
	}
	return 0;
}

