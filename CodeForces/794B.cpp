#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-6;

int main()
{
	double a,b;
	scanf("%lf %lf",&a,&b);
	int end = (int)a;
	printf("%.12lf",sqrt(b * b / a));
	for(int i = 2;i < end;i ++)
		printf(" %.12lf",sqrt(b * (double)i * b / a));
	printf("\n");
	return 0;
}
