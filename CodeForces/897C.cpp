#include<bits/stdc++.h>

using namespace std;

const char 
    s0[] = "What are you doing at the end of the world? Are you busy? Will you save us?",
    s1[] = "What are you doing while sending \"",
    s2[] = "\"? Are you busy? Will you send \"",
    s3[] = "\"?";
int l1, l2, l3, lim;
long long len[100];
char calc(int n, long long k)
{
    if(! n)
		return s0[k];
    if(k < l1)
		return s1[k];
    k -= l1;
    if(n - 1 > lim || k < len[n - 1])
		return calc(n - 1,k);
    k -= len[n - 1];
    if(k < l2)
		return s2[k];
    k -= l2;
    if(n - 1 > lim || k < len[n - 1])
		return calc(n - 1,k);
    k -= len[n - 1];
    return s3[k];
}
int main(){
    len[0] = strlen(s0);
    l1 = strlen(s1);
    l2 = strlen(s2);
    l3 = strlen(s3);
    while(len[lim] < 1e18)
	{
        lim ++;
		len[lim] = l1 + len[lim - 1] + l2 + len[lim - 1] + l3;
    }
    int q;
	scanf("%d",&q);
    while(q --){
        int n;
		long long k;
        scanf("%d%lld",&n,&k);
        if(n <= lim && k > len[n])
			putchar('.');
        else putchar(calc(n,k - 1));
    }
    puts("");
    return 0; 
}
/*
By eds467, 
contest: Codeforces Round #449 (Div. 1), 
problem: (A) Nephren gives a riddle, Accepted, #
*/
/*
10
4 1825
3 75
3 530
4 1829
4 1651
3 187
4 584
4 255
4 774
2 474
*/
// Areyoubusy
