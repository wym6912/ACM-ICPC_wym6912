#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 200050;

ll summ[maxn],data[maxn];
double now1,now2,nowans,ans = -1.0;
int n,ansi = 1,ansl;

int main()
{
	while(~ scanf("%d",&n))
	{
		memset(summ,0,sizeof(summ));
		for(int i = 1;i <= n;i ++)
			scanf("%I64d",&data[i]);
		if(n == 2)
		{
			printf("%d\n%I64d %I64d\n",n,data[1],data[2]);
			continue;
		}
		if(n == 1)
		{
			printf("%d\n%I64d\n",n,data[1]);
			continue;
		}
		sort(data + 1,data + 1 + n);
		for(int i = 1;i <= n;i ++)
			summ[i] = summ[i - 1] + data[i];
		int l,r,mid;
		int now;
		for(int i = 2;i <= n - 1;i ++)
		{
			l = 1;
			r = min(i - 1,n - i);
			now = 0;
			while(l <= r)
			{
				mid = (l + r) >> 1;
				now1 = (1.0 * (summ[n] + summ[i] - summ[n - mid] - summ[i - mid - 1])) / (2 * mid + 1);
				now2 = (1.0 * (summ[n] + summ[i] - summ[n - mid + 1] - summ[i - mid])) / (2 * mid - 1);
				if(now1 > now2)
				{
					now = mid;
					l = mid + 1;
				}
				else r = mid - 1;
			}
			nowans = (1.0 * ( summ[n] + summ[i] - summ[n - now] - summ[i - now - 1])) / (2 * now + 1) - data[i];
			if(ans < nowans)
			{
				ans = nowans;
				ansi = i;
				ansl = now;
			}
		}
		printf("%d\n",2 * ansl + 1);  
	    for (int i = ansi - ansl;i <= ansi;i ++)  
	    {  
	        printf("%I64d ",data[i]);  
	    }  
	    for (int i = n - ansl + 1;i <= n;i ++)  
	    {  
	        printf("%I64d ",data[i]);  
	    }  
	    printf("\n");
	}
	return 0;
}
