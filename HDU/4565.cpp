#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2;
const int MAXM = 2;

typedef long long ll;

struct Matrix
{
	int n, m;
	ll a[MAXN][MAXM];
}bb,x,tmp,one,ans,ans2;

ll M;

Matrix subb (const Matrix &ax,const Matrix &b)
{
	Matrix tmp;
	tmp.n = tmp.m = 2;
	memset(tmp.a,0,sizeof(tmp.a));
	for(int i = 0;i < 2;i ++)
		for(int k = 0;k < 2;k ++)
			for(int j = 0;j < 2;j ++)
				tmp.a[i][j] = (tmp.a[i][j] + ax.a[i][k] * b.a[k][j]) % M;
	return tmp;
}

Matrix quickpow(const Matrix m, long long q)
{
	Matrix tmp = m, tmp2 = one;
	while(q)
	{
		if(q & 1)
			tmp2 = subb(tmp2, tmp);
		q >>= 1;
		tmp = subb(tmp, tmp);
	}
	return tmp2;
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

int main()
{
	ll A, B, N;
	x.m = 2,x.n = 2;
	bb.m = bb.n = 2;
	tmp.n = 2,tmp.m = 1;
	one.n = one.m = 2;
	ans.m = ans.n = 2;
	one.a[1][1] = one.a[0][0] = 1;
	one.a[0][1] = one.a[1][0] = 0;
	while(~ scanf("%lld%lld%lld%lld",&A,&B,&N,&M))
	{
		x.a[0][0] = 1;x.a[0][1] = 0;
		x.a[1][0] = 0;x.a[1][1] = 1;
		bb.a[0][0] = A,bb.a[0][1] = B;
		bb.a[1][0] = 1,bb.a[1][1] = A;
		ans2 = one;
		bb = quickpow(bb, N);
		x = subb(x, bb);
		//if(! N)printf("%lld\n",(A * 2) % M);
		/*else*/ printf("%lld\n",(2 * x.a[0][0]) % M);
	}
	return 0;
}
