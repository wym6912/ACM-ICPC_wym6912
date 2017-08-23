#include <cstdio>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long ll;

const int DAT_SIZE = (1 << 18) - 1;
const int MAX_N = 100009;
const int MAX_Q = 100009;

int Q, N;
int A[MAX_N];
char T[MAX_Q];
int L[MAX_Q], R[MAX_Q], X[MAX_Q];

ll data[DAT_SIZE], datb[DAT_SIZE]; //data is Main Tree, datb is tag tree

inline int min(int a,int b){return a < b ? a : b;}
inline int max(int a,int b){return a > b ? a : b;}

void add(int a,int b,int x,int k,int l,int r)
{
	if(a <= l && r <= b)data[k] += x;
	else if(l < b && a < r)
	{
		datb[k] += (min(b, r) - max(a, l)) * x;
		add(a, b, x, k * 2 + 1, l, (l + r) >> 1);
		add(a, b, x, k * 2 + 2, (l + r) >> 1, r);
	}
	//else assert();
}

ll sum(int a,int b,int k,int l,int r)
{
	if(b <= l || r <= a)
		return 0;
	else if(a <= l && r <= b)
	{
		return data[k] * (r - l) + datb[k];
	}
	else 
	{
		ll res = (min(b, r) - max(a, l)) * data[k];
		res += sum(a, b, k * 2 + 1, l, (l + r) >> 1);
		res += sum(a, b, k * 2 + 2, (l + r) >> 1, r);
		return res;
	}
}

void solve()
{
	for(int i = 0;i < N;i ++)
		add(i,i + 1, A[i], 0, 0, N);
	for(int i = 0;i < Q;i ++)
		if(T[i] == 'C')
			add(L[i] - 1, R[i], X[i], 0, 0, N);
		else
			printf("%lld\n", sum(L[i] - 1, R[i], 0, 0, N));
}

int main()
{
	while(~ scanf("%d%d",&N,&Q))
	{
		memset(data,0,sizeof(data));
		memset(datb,0,sizeof(datb));
		for(int i = 0;i < N;i ++)
			scanf("%lld",&A[i]);
		for(int i = 0;i < Q;i ++)
		{
			scanf("\n%c",&T[i]);
			if(T[i] == 'C')scanf("%d%d%lld",&L[i],&R[i],&X[i]);
			else scanf("%d%d",&L[i],&R[i]);
		}
		solve();
	}
	return 0;
}
