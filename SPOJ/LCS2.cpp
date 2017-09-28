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
# define RESET_(_, val) memset(_, val, sizeof(_))

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef set <int> si;

const int MOD = 1e9 + 7;
const int maxn = 250010;
const int maxm = 300009;
const double pi = acos(-1.0);
const double eps = 1e-6;

const int CHAR = 26;

struct SAM_node
{
	SAM_node *fa, *next[CHAR];
	int len;
	int id, pos;
	SAM_node(){}
	SAM_node(int __len__)
	{
		fa = 0;
		len = __len__;
		RESET(next);
	}
};

SAM_node SAM_NODE[maxn * 2], *SAM_root, *SAM_last;
int SAM_size;

SAM_node* newSAM_node(int len)
{
	SAM_NODE[SAM_size] = SAM_node(len);
	SAM_NODE[SAM_size].id = SAM_size;
	return & SAM_NODE[SAM_size ++];
}

SAM_node* newSAM_node(SAM_node *p)
{
	SAM_NODE[SAM_size] = *p;
	SAM_NODE[SAM_size].id = SAM_size;
	return & SAM_NODE[SAM_size ++];
}

void SAM_init()
{
	SAM_size = 0;
	SAM_root = SAM_last = newSAM_node(0);
	SAM_NODE[0].pos = 0;
}

void SAM_add(int x, int len)
{
	SAM_node *p = SAM_last, *np = newSAM_node(p -> len + 1);
	np -> pos = len;
	SAM_last = np;
	for(;p && ! p -> next[x];p = p -> fa)
		p -> next[x] = np;
	if(! p)
	{
		np -> fa = SAM_root;
		return ;
	}
	SAM_node *q = p -> next[x];
	if(q -> len == p -> len + 1)
	{
		np -> fa = q;
		return ;
	}
	SAM_node *nq = newSAM_node(q);
	nq -> len = p -> len + 1;
	q -> fa = nq;
	np -> fa = nq;
	for(;p && p -> next[x] == q;p = p -> fa)
		p -> next[x] = nq;
}

void SAM_build(char *s)
{
	SAM_init();
    int len = strlen(s);
    SAM_last = SAM_root;
    for(int i = 0;i < len;i++)
    {
        if( !SAM_last -> next[s[i] - 'a'] || !(SAM_last->next[s[i] - 'a']->len == i+1) )
            SAM_add(s[i] - '0',i+1);
        else SAM_last = SAM_last->next[s[i] - '0'];
    }
}

// Topological Sort
char str[maxn], str2[maxn];
int topocnt[maxn];
SAM_node* topsam[maxn * 2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> str;
	int n = strlen(str);
	RESET(topocnt);
	SAM_build(str);
	int ans = 0;
	while(cin >> str2)
	{
		int len = strlen(str2);
    	SAM_node *tmp = SAM_root;
    	int t = 0;
    	for(int i = 0;i < len;i++)
    	{
        	if(tmp -> next[str2[i] - 'a'])
        	{
           		tmp = tmp -> next[str2[i] - 'a'];
            	t ++;
        	}
	        else
	        {
	            while(tmp && ! tmp -> next[str2[i] - 'a'])
	                tmp = tmp -> fa;
	            if(tmp == NULL)
	            {
	                tmp = SAM_root;
	                t = 0;
	            }
	            else
	            {
	                t = tmp -> len + 1;
	                tmp = tmp -> next[str2[i] - 'a'];
	            }
	        }
	        ans = min(ans, t);
	    }
	}
	cout << ans << endl;
	return 0;
}
/*
alsdfkjfjkdsal
fdjskalajfkdsla
*/
