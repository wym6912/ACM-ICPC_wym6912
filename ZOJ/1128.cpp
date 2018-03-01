#include <bits/stdc++.h>

using namespace std;

double x[1001],y[1001],in[1001][4];
bool xy[2001][2001];
double N=0.000001,sum = 0.0;
int i,j,k,n_map,n_case=0;

void input()
{
	k = 0;
	for(i = 0 ; i < n_map ; i++)
	{
		cin>>in[i][0]>>in[i][1]>>in[i][2]>>in[i][3];
		x[k] = in[i][0];
		y[k] = in[i][1];
		k++;
		x[k] = in[i][2];
		y[k] = in[i][3];
		k++;
	}
}

void solve()
{
	for(i = 0 ; i < n_map; i++)	
	{
		int i1,j1,i2,j2, I, J;
		k = 0 ; 
		while(abs(x[k]-in[i][0])>N && k < 2*n_map) k ++;
		i1 = k;	k = 0;
		while(abs(y[k]-in[i][1])>N && k < 2*n_map) k ++;
		j1 = k; k = 0 ; 
		while(abs(x[k]-in[i][2])>N && k < 2*n_map) k ++;		i2 = k; k = 0;
		while(abs(y[k]-in[i][3])>N && k < 2*n_map) k ++;
		j2 = k;
		for(I = i1 ; I < i2 ; I ++)
		for(J = j1 ; J < j2 ; J ++)	xy[I][J] = true;
	}
}

double calcu()
{
	double sum = 0;
	for(i = 0 ; i < 2 * n_map ; i ++)
	for(j = 0 ; j < 2 * n_map ; j ++)
		sum += xy[i][j]*(x[i+1] - x[i] )*( y[j+1] -y[j]);
	return sum;
}

int main()
{
	int xx = 0;
	while(cin>>n_map && n_map != 0)
	{
		xx ++;
		input();
		sort(x,x+2*n_map);
		sort(y,y+2*n_map);
		memset(xy,0,sizeof(xy));
		solve();
		cout << "Test case #" << xx << endl << "Total explored area: ";
		printf("%.2lf\n\n",calcu());
	}
	return 0;
}

