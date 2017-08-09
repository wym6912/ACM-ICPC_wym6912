#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2;
const int MAXM = 2;

struct Matrix
{
	int n, m;
	int a[MAXN][MAXM];
}bb,x,tmp;

void subb (const Matrix &ax,const Matrix &b)
{
	memset(tmp.a,0,sizeof(tmp.a));
	for(int i = 0;i < 2;i ++)
		for(int k = 0;k < 2;k ++)
			for(int j = 0;j < 1;j ++)
				tmp.a[i][j] = (tmp.a[i][j] + ax.a[i][k] * b.a[k][j]) % 7;
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
	int A, B, N;
	x.m = 1,x.n = 2;
	bb.m = bb.n = 2;
	tmp.n = 2,tmp.m = 1;
	while(~ scanf("%d%d%d",&A,&B,&N) && (A || B || N))
	{
		x.a[0][0] = x.a[1][0] = 1;
		bb.a[0][0] = A,bb.a[0][1] = B;
		bb.a[1][0] = 1,bb.a[1][1] = 0;
		//cout << "x = " << x;
		//cout << "bb = " << bb;
		//cout << "tmp = " << tmp;
		//cout << 1 << ' ' << 1 << ' ';
		for(int i = 1;i <= (N - 2) % 48;i ++)
		{
			subb(bb,x);
			x = tmp;
			//cout << x.a[0][0] << ' ';
			//if(i % 48 == 46)cout << endl;
		}
		cout << endl;
		printf("%d\n",x.a[0][0]);
	}
	return 0;
}
