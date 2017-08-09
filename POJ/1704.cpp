#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int data[10101];

int main()
{
	int _,n,ans;
	scanf("%d",&_);
	while(_ --)
	{
		ans = 0;
		scanf("%d",&n);
		for(int i = 1;i <= n;i ++)
			scanf("%d",&data[i]);
		sort(data + 1,data + n + 1);
		if(n & 1)ans = data[1] - 1;
		for(int i = (n & 1) + 1;i <= n;i += 2)
			ans ^= (data[i + 1] - data[i] - 1);
		puts(! ans ? "Bob will win" : "Georgia will win");
	}
	return 0;
}
