#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300;
const int mod = 1000;

struct Matrix
{
	int n;
	int a[MAXN][MAXN];
	void clear(){memset(a,0,sizeof(a));n = 0;}
	Matrix operator * (const Matrix &b) const
	{
		Matrix tmp;
		tmp.clear();
		tmp.n = n;
		for(int i = 0;i < n;i ++)
			for(int k = 0;k < n;k ++)
				for(int j = 0;j < n;j ++)
					tmp.a[i][j] = (tmp.a[i][j] + a[i][k] * b.a[k][j]) % mod;
		return tmp;
	}
	Matrix one()
	{
		Matrix tmp;
		tmp.clear();
		tmp.n = n;
		for(int i = 0;i < n;i ++)tmp.a[i][i] = 1;
		return tmp;
	}
	Matrix operator ^ (int &k)
	{
		int b = k;
		Matrix tmp,tmp2 = one();
		tmp.n = n;
		for(int i = 0;i < n;i ++)
			for(int j = 0;j < n;j ++)
				tmp.a[i][j] = a[i][j];
		while(b)
		{
			if(b & 1)tmp2 = tmp * tmp2;
			b >>= 1;
			tmp = tmp * tmp;
		}
		return tmp2;
	}
}Graph,GG;

int main()
{
	//freopen("A.txt","w",stdout);
	int n, m, from, to, T, A, B, k;
	while(~ scanf("%d%d",&n,&m) && (n || m))
	{
		Graph.clear(); 
		Graph.n = n;
		while(m --)
		{
			scanf("%d%d",&from,&to);
			Graph.a[from][to] = 1;
		}
		scanf("%d",&T);
		while(T --)
		{
			scanf("%d%d%d",&A,&B,&k);
			GG = Graph ^ k;
			printf("%d\n",GG.a[A][B]);
		}
	}
	return 0;
}
