#include <bits/stdc++.h>

using namespace std;

int gcd(int x,int y)
{
	if(!(x%y))return y;
    return gcd(y,x%y);
}

int lcm(int x,int y)
{
	return (x*y)/gcd(max(x,y),min(x,y));
}

int main()
{
	int n,m,z;
	scanf("%d %d %d",&n,&m,&z);
	printf("%d\n",z/lcm(n,m));
	return 0;
} 
