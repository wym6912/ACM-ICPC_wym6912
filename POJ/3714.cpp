#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 200001;
const double inf = 1e60;

struct point
{
	double x,y;
	bool flag;
}pp[maxn],t[maxn];

int n;

inline bool cmpxy(const point &a,const point &b)
{
	if(a.x == b.x)return a.y < b.y;
	return a.x < b.x;
}

inline bool cmpy(const point &a,const point &b)
{
	return a.y < b.y;
}

inline double sqr(double a)
{
	return a * a;
}

inline double dis(point a,point b)
{
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

double doit(int l,int r)
{
	if(l == r)return inf;
	if(l + 1 == r)return ((pp[l].flag != pp[r].flag) ? dis(pp[l],pp[r]) : inf);
	if(l + 2 == r)
	{
        if( pp[l].flag == pp[l + 1].flag )  
        {  
            if(pp[l].flag == pp[l + 2].flag )    
				return inf;
            else    return min( dis(pp[l],pp[l + 2]),dis(pp[l + 1],pp[l + 2]) );  
        }  
        else  
        {  
            if( pp[l].flag == pp[l + 2].flag )    
				return min( dis(pp[l],pp[l+1]),dis(pp[l+2],pp[l+1]) );  
            else return  min( dis(pp[l],pp[l+1]),dis(pp[l],pp[l+2]) );  
        }  
        return min( dis(pp[l],pp[r]),min( dis(pp[l],pp[l+1]),dis(pp[l+1],pp[r]) ) );  
	}
	int mid = (l + r) >> 1;
	double ans = min(doit(l,mid),doit(mid + 1,r));
	int tot = 0;
	for(int i = l;i <= r;i ++)
		if(fabs(pp[i].x - pp[mid].x) <= ans )
			t[++ tot] = pp[i];
	sort(t + 1,t + tot + 1,cmpy);
	for(int i = 1;i <= tot;i ++)
		for(int j = i + 1;j <= tot && t[j].y - t[i].y < ans;j ++)
			ans = min(ans,((t[i].flag != t[j].flag) ? dis(t[i],t[j]) : inf));
	return ans;
}

int main()
{
	int x;
	while(~ scanf("%d",&x))
	{
		while(x --)
		{
			scanf("%d",&n);
			n *= 2;
			for(int i = 1;i <= n / 2;i ++)
				scanf("%lf%lf",&pp[i].x,&pp[i].y),pp[i].flag = false;
			for(int i = n / 2 + 1;i <= n;i ++)
				scanf("%lf%lf",&pp[i].x,&pp[i].y),pp[i].flag = true;
			sort(pp + 1,pp + n + 1,cmpxy);
			printf("%.3lf\n",doit(1,n));
		}
	}
	return 0;
}
