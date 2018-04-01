#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef struct node
{
	double data;
	char name[4];
	ll key;
	node(){data = 0.0; key = 0;}
	bool operator < (const node &b) const
	{
		return key < b.key;
	}
}node;

ll data[5009];
int pt;

node nnn[10009];
double sum;

void deal(char str[4])
{
	pt ++;
	ll ans = 0;
	for(int i = 0; i <= 3; i ++)
		ans = (ans << 8) | str[i];
	data[pt] = ans;
}

void deal_2(char str[4], int x)
{
	ll ans = 0;
	for(int i = 0; i <= 3; i ++)
		ans = (ans << 8) | str[i];
	nnn[x].key = ans;
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, q;
	bool flag;
	char str[4];
	scanf("%d", &n);
	pt = 0;
	while(n --)
	{
		scanf(" %s ", str);
		deal(str);
	}
	sum = 0.0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)
		scanf("%s %lf", nnn[i].name, &nnn[i].data), 
		sum += nnn[i].data, 
		deal_2(nnn[i].name, i);
	sum = sum / (double)n;
	sort(nnn + 1, nnn + 1 + n);
	sort(data + 1, data + 1 + pt);
	flag = true;
	for(int i = 1; i <= n; i ++)
	{
		if(nnn[i].data > sum)
			if(find(data + 1, data + 1 + pt, nnn[i].key) == data + pt + 1)
			{
				puts(nnn[i].name);
				flag = false;
			}
	}
	if(flag)puts("Bing Mei You");
	return 0;
}
