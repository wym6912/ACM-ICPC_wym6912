#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int data[10101];

int main()
{
	int k,n,ans;
	while(~ scanf("%d%d",&n,&k))
	{
		ans = 0;
		if(k == 1){for(int i = 1;i <= n;i ++)scanf("%*d");puts("Alice");continue;}
		for(int i = 1;i <= n;i ++)
			scanf("%d",&data[i]);
		data[0] = 0;
		if(k != 2)data[0] = -1;
		for(int i = n;i >= 1;i -= 2)
			ans ^= (data[i] - data[i - 1] - 1);
		puts(! ans ? "Bob" : "Alice");
	}
	return 0;
}
