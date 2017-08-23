#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
const int INF=100000000;
int r[300],sum[300][40],one[300][300];

int from[300][40],to[300][40],at[300][40];

int output(int i,int j)
{
    if(j<=0||i<=0)return 1;
    int num=output(from[i][j]-1,j-1);
    printf("Depot %d at restaurant %d serves ",num,at[i][j]);
    if(from[i][j]==to[i][j])printf("restaurant %d\n",from[i][j]);
    else printf("restaurants %d to %d\n",from[i][j],to[i][j]);
    return num+1;
}    

int main()
{
    int n,K,i,j,k,middle;
    int iCase=0;
    while(scanf("%d%d",&n,&K)!=EOF)
    {
        iCase++;
        if(n==0&&K==0)break;
        for(i=1;i<=n;i++)scanf("%d",&r[i]);
        memset(one,0,sizeof(one));
        memset(sum,0,sizeof(sum));
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                middle=(i+j)/2;
                for(k=i;k<middle;k++)one[i][j]+=r[middle]-r[k];
                for(k=middle+1;k<=j;k++)one[i][j]+=r[k]-r[middle];
            }    
        }  
        for(i=1;i<=n;i++)sum[i][0]=INF;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=i&&j<=K;j++)
            {
                sum[i][j]=INF;
                for(k=j-1;k<=i-1;k++)
                {
                    int tmp=sum[k][j-1]+one[k+1][i];
                    if(tmp<sum[i][j])
                    {
                        sum[i][j]=tmp;
                        from[i][j]=k+1;
                        to[i][j]=i;
                        at[i][j]=(k+1+i)/2;
                    }    
                }    
            }    
        } 
        printf("Chain %d\n",iCase);
        output(n,K);
        printf("Total distance sum = %d\n\n",sum[n][K]);     
    }    
    return 0;
}