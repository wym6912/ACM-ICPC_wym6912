#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1.0);
const double eps = 1e-8;

inline double sqr(double x)
{
	return x * x;
}

int cmp(double x)
{
	if(fabs(x) < eps)return 0;
	if(x > 0)return 1;
	return -1;
}

struct point
{
	double x,y;
	bool flag;
	point(){}
	point(double a,double b): x(a),y(b){}
	void input()
	{
		scanf("%lf%lf",&x,&y);
	}
	friend point operator - (const point & a,const point & b)
	{
		return point(a.x - b.x,a.y - b.y);
	}
	double norm()
	{
		return sqrt(sqr(x) + sqr(y));
	}
}p[201];

double det(const point & a,const point & b)
{
	return a.x * b.y - a.y * b.x;
}

double dis(const point & a,const point & b)
{
	return (a - b).norm();
}

void reset(int *a,int *b,int *c,int *d)
{
	*a = 0;
	*b = 0;
	*c = -1;
	*d = -1;
}

int main()
{
	double radius;
	int n,l,r,lm,rm;
	p[0].input();
	scanf("%lf",&radius);
	while(radius >= 0.0)
	{
		reset(&l,&r,&lm,&rm);
		scanf("%d",&n);
		for(int i = 1;i <= n;i ++)
		{
			p[i].input();
			if(dis(p[0],p[i]) <= radius)
				p[i].flag = true;
			else p[i].flag = false;
		}
		for(int i = 1;i <= n;i ++)
			if(p[i].flag)
			{
				for(int j = 1;j <= n;j ++)
					if(j != i && p[j].flag)
						if(cmp(det(p[i] - p[0],p[j] - p[0])) == 1)
							r ++;
						else 
							l ++;
				lm = max(l,lm);
				rm = max(r,rm);
				r = 0;
				l = 0;
			}
		printf("%d\n",max(lm,rm) + 1);
		p[0].input();
		scanf("%lf",&radius);
	}
}
