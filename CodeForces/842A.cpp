#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long r, l, y, x, k;
	while(~ scanf("%I64d%I64d%I64d%I64d%I64d",&l,&r,&x,&y,&k))
	{
		bool flag = false;
		for(long long i = x;i <= y;i ++)
		{
			if(l <= i * k && r >= i * k)
			{
				puts("YES");
				flag = true;
				break;
			}
		}
		if(! flag)puts("NO");
	}
	return 0;
}
