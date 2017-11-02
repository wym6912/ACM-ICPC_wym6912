#define NOSTDCPP
#ifndef NOSTDCPP

#include <bits/stdc++.h>

#else

#include <algorithm>
#include <bitset>
#include <complex>
#include <cstring>
#include <cstdio>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <istream>
#include <iterator>
#include <list>
#include <map>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#endif

# define RESET(_) memset(_, 0, sizeof(_))
# define RESET_(_, val) memset(_, val, sizeof(_))
# define fi first
# define se second

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef set <int> si;

const int MOD = 1e9 + 7;
const int maxn = 300009;
const int maxm = 300009;
const double pi = acos(-1.0);
const double eps = 1e-6;

int len_of_st[101], n;
bool visited[101];

bool dfs(int len, int num, int remain, int s)
{
	//cout << "Remain = " << remain << " in stack " << s << " , len = " << len << endl; 
	if(remain == 0 && num == 0)return true;
	if(remain == 0)remain = len;
	for(int i = 1;i <= n;i ++)
	{
		if(visited[i] || len_of_st[i] > remain)continue; // 太长了或者已经拼过了 
		visited[i] = true;
		if(dfs(len, num - 1, remain - len_of_st[i], s + 1))return true; // 比它低的问题都可以 
		visited[i] = false;
		if(len_of_st[i] == remain || len == remain)break;
		while(len_of_st[i] == len_of_st[i + 1])i ++; // 跳过重复的
	}
	return false;
}

int main()
{
	while(~ scanf("%d", &n) && n)
	{
		RESET(len_of_st);
		int tmp, sum = 0, maxl = 0;
		for(int i = 1;i <= n;i ++)
		{
			//cin >> len_of_st[i];
			scanf("%d", &len_of_st[i]);
			sum += len_of_st[i];
			//maxl = max(maxl, len_of_st[i]);
		}
		sort(len_of_st + 1, len_of_st + 1 + n, greater <int> ());
		bool flag = true;
		for(int i = len_of_st[1];i <= sum;i ++)
		{
			//printf("%d\n", i);
			if(sum % i)continue;
			RESET(visited);
			if(dfs(i, n, i, 1))
			{
				//cout << i << endl; 
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}
