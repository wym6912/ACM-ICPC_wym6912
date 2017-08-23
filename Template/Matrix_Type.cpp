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
	Matrix operator ^ (int &b) // ¾ØÕó¿ìËÙÃÝ 
	{
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
	Matrix operator + (const Matrix &b) const
	{
		Matrix tmp;
		tmp.n = n;
		for(int i = 0;i < n;i ++)
			for(int j = 0;j < n;j ++)
				tmp.a[i][j] = a[i][j] + b.a[i][j];
		return tmp;
	}
	Matrix operator - (const Matrix &b) const
	{
		Matrix tmp;
		tmp.n = n;
		for(int i = 0;i < n;i ++)
			for(int j = 0;j < n;j ++)
				tmp.a[i][j] = a[i][j] - b.a[i][j];
		return tmp;
	}
}; 
