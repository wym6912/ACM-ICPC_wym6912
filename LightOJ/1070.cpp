#include <bits/stdc++.h>

using namespace std;
const int MAXN = 2;
const int MAXM = 2;

struct Matrix
{
	int n, m;
	unsigned long long a[MAXN][MAXM];
}bb,x,one;

Matrix subb (const Matrix &ax,const Matrix &b)
{
	Matrix tmp;
	memset(tmp.a,0,sizeof(tmp.a));
	tmp.n = tmp.m = 2;
	for(int i = 0;i < 2;i ++)
		for(int k = 0;k < 2;k ++)
			for(int j = 0;j < 2;j ++)
				tmp.a[i][j] = (tmp.a[i][j] + ax.a[i][k] * b.a[k][j]);
	return tmp;
}

ostream & operator << (ostream &out, const Matrix &b)
{
    cout << endl;
    for(int i = 0;i < b.n;i ++)
    {
        for(int j = 0;j < b.m;j ++)
            out << b.a[i][j] << ' ';
        cout << endl;
    }
    cout << endl;
    return out;
}

Matrix quickpow(const Matrix m, long long q)
{
	Matrix tmp = m, tmp2 = one;
	while(q)
	{
		if(q & 1)
			tmp2 = subb(tmp, tmp2);
		q >>= 1;
		tmp = subb(tmp, tmp);
	}
	return tmp2;
}

int main()
{
	freopen("1070.txt","w",stdout);
	long long A, B, N;
	x.m = 1,x.n = 2;
	bb.m = bb.n = 2;
	one.m = one.n = 2;
	one.a[0][0] = one.a[1][1] = 1;
	one.a[1][0] = one.a[0][1] = 0;
	int T;
	scanf("%d", &T);
	for(int aa = 1;aa <= T;aa ++)
	{
		scanf("%lld%lld%lld",&A,&B,&N);
		x.a[0][0] = A,x.a[1][0] = 2;
		bb.a[0][0] = A,bb.a[0][1] = -B;
		bb.a[1][0] = 1,bb.a[1][1] = 0;
		//cout << "X0 = " << x; 
		if(N == 1)
		{
			printf("Case %d: %llu\n",aa,A);
			continue; 
		}
		if(N == 0)
		{
			printf("Case %d: %llu\n",aa,2);
			continue; 
		}
		bb = quickpow(bb, N - 1);
		x = subb(bb,x);
		//cout << "x = " << x;
		//cout << "One = " << one;
		//cout << "bb = " << bb;
		printf("Case %d: %llu\n",aa,x.a[0][0]);
	}
	return 0;
}
