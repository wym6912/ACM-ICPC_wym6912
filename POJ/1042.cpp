#include <cstdio>
#include <cstring>

using namespace std;
 
int n,h,fi[30],di[30],cfi[30],ti[30];
 
struct lakei
{
    int num[30];
    int max;
}lake[30];
 
int GetMax(int p[], int i, int j)
{
    int cmax = p[i], loc = i;
    for (int m = i + 1; m <= j; m++)
    {
        if (cmax < p[m])
        {
            cmax = p[m];
            loc = m;
        }
    }
    return loc;
}
 
void GetFish()
{
    int i, j;
    int T = h * 60, t, CT;
    memset(lake,0,sizeof(lake));
    for (i = 1;i <= n; i ++)
    {
        CT = T;
        t = 0;
        for (j = 1; j <= i; j ++)
        {
            cfi[j] = fi[j];
            CT = (j < i) ? CT - ti[j] * 5 : CT;
        }
        while (t < CT)
        {
            int k = GetMax(cfi, 1, i);
            lake[i].max += cfi[k];
            lake[i].num[k] += 5;
            cfi[k] >= di[k] ?  cfi[k] -= di[k] : cfi[k] = 0;
            t += 5;
        }
    }
    for (i = 1; i <= n; i++)
    {
        cfi[i] = lake[i].max;
    }
    int la = GetMax(cfi, 1, n);
    for (i = 1; i <= n; i++)
    {
        (i != n) ?  printf("%d, ", lake[la].num[i]) : printf("%d", lake[la].num[i]);
    }
    printf("\nNumber of fish expected: %d\n\n", lake[la].max);
}
 
int main()
{
    int i;
    while (scanf("%d", &n) && n)
    {
        scanf("%d", &h);
        for (i = 1; i <= n; i++)
        {
            scanf("%d", &fi[i]);
        }
        for (i = 1; i <= n; i++)
        {
            scanf("%d", &di[i]);
        }
        for (i = 1; i < n; i++)
        {
            scanf("%d", &ti[i]);
        }
        GetFish();
    }
    return 0;
}
 
