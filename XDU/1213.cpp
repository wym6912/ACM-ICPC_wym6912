#include <bits/stdc++.h>

#define m first
#define w second

using namespace std;

const int N = 1e5 + 9;

pair <int, int> s[100009];

int c[100009];

inline int lowbit(int x)
{
	return x & - x;
}

void update(int x)    // Update () 更新比它小的数量 
{ 
	for(;x < N;x += lowbit(x)) 
		++ c[x];
} 
int	query(int x) 
{
	int res = 0;
	for(;x > 0;x -= lowbit(x))
		res += c[x]; 
	return res; 
}

int main()
{
	int n, M, W;
	while(~ scanf("%d%d%d",&n,&M,&W))
	{
		long long ans = 0;
		for(int i = 1;i <= n;i ++)
			scanf("%d", &s[i].m);
		for(int i = 1;i <= n;i ++)
			scanf("%d", &s[i].w);
		sort(s + 1, s + n + 1);
		memset(c, 0, sizeof(c));
		int l = 1, r = n;
		for(;r >= 1;r --)
		{
			for(;l <= n && s[l].m + s[r].m <= M;l ++)
				update(s[l].w);
			if(W - s[r].w > 0)  //注意是左找右 
				ans += query(W - s[r].w);
		}
		//for(int i = 1;i <= n;i ++)
		//	cout << i << ' ' << s[i].w << ' ' << query(s[i].w) << endl; 
		for(int i = 1;i <= n;i ++) // 去除自己和自己的集合 
			if(s[i].w * 2 <= W && s[i].m * 2 <= M)
				ans --;
		ans /= 2;
		printf("%lld\n",ans);
	}
	return 0;
}
