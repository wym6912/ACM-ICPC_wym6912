#include <cstdio>
#include <cstring>

using namespace std;

int T,n,sum,w[205],lim;
bool dp[20005];

int main() 
{
    scanf("%d",&T);
        while(T-->0) {
            sum=0;
            scanf("%d",&n);
            for(int i=0;i<n;++i) {
                scanf("%d",w+i);
                sum+=w[i];
            }
            if(sum & 1 || n == 1)
            {
            	printf("No\n");
            	continue;
            }
            lim=sum>>1;
            memset(dp,false,sizeof(dp));
            dp[0]=true;
            for(int i=0;i<n;++i) {
                for(int j=lim;j>=w[i];--j) {
                    if(dp[j-w[i]])
                        dp[j]=true;
                }
            }
            if(dp[lim])
            	printf("Yes\n");
            else printf("No\n");
            }
    return 0;
}
