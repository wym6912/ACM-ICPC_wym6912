#include <bits/stdc++.h>

using namespace std;

const int maxn = 300009;

typedef struct node
{
	int pre, data;
	node *next;
	node *prenode;
}node;

typedef node * NEXT;

struct temp
{
	int pre, data, next;
}tmp[maxn];

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, start;
//	freopen("L2-022.in", "r", stdin);
//	freopen("L2-022.txt", "w", stdout);
	//cin >> start >> n;
	scanf("%d%d", &start, &n);
	for(int i = 1;i <= n;i ++)
		//cin >> ;
		scanf("%d%d%d", &tmp[i].pre, &tmp[i].data, &tmp[i].next);
	node *link = new node;
	node *tmpn = link;
	link -> data = 0;
	link -> pre  = -1;
	link -> next = NULL;
	link -> prenode = NULL;
	while(start != -1)
	{
		for(int i = 1; i <= n; i ++)
			if(tmp[i].pre == start)
			{
				node *newnode = new node;
				newnode -> prenode = tmpn;
				newnode -> pre = tmp[i].pre;
				newnode -> data = tmp[i].data;
				newnode -> next = NULL;
				tmpn -> next = newnode;
				tmpn = tmpn -> next;
				start = tmp[i].next;
			}
	}
	node *s, *e; // s is start, e is point to end
	node *ans = new node, *anstmp = ans;
	node *epre = link;
	n = 0;
	while(epre -> next != NULL)epre = epre -> next, n ++;
	//epre = epre -> prenode;
	ans -> next = NULL;
	ans -> data = 0;
	ans -> pre = -1;
	ans -> prenode = NULL;
	if(n % 2 == 0)
	{
		for(int i = 1;i <= n / 2; i ++)
		{
			s = link -> next, e = epre;
			epre = link;
			//while(epre -> next != e)epre = epre -> next;
			epre = e -> prenode;
			epre -> next = NULL;
			anstmp -> next = e;
			link -> next = s -> next;
			anstmp = anstmp -> next;
			anstmp -> next = s;
			anstmp = anstmp -> next;
		}
	}
	else 
	{
		//assert(false);
		for(int i = 1;i <= n / 2; i ++)
		{
			s = link -> next, e = epre;
			epre = link;
			//while(epre -> next != e)epre = epre -> next;
			epre = e -> prenode;
			if(e == s)break;
			epre -> next = NULL;
			anstmp -> next = e;
			link -> next = s -> next;
			anstmp = anstmp -> next;
			anstmp -> next = s;
			anstmp = anstmp -> next;
		}
		anstmp -> next = link -> next;
	}
	tmpn = ans -> next;
	while(tmpn)
	{
		printf("%05d %d ", tmpn -> pre, tmpn -> data);
		if(tmpn -> next == NULL)printf("%d\n", -1);
		else
			printf("%05d\n", tmpn -> next -> pre);
		tmpn = tmpn -> next;
	}
	return 0;
}
/*
11231 5
99999 153 -1
15964 456 99999
11050 2359 15964
11231 4687 54655
54655 11050 11050

00100 2
68237 6 -1
00100 23 68237

00000 2
00000 153 -1
12323 2 12323 

*/ 
