#include <bits/stdc++.h>

using namespace std;

const int maxn = 300009;

typedef struct node
{
	int val, pre;
	node *next;
}node;

typedef struct inf
{
	int f, t, v;
}inf;

inf info[maxn];
bool isin[10009];

int main()
{
	memset(isin, false, sizeof(isin));
	int firplace, n;
	scanf("%d%d", &firplace, &n);
	for(int i = 1;i <= n;i ++)
		scanf("%d%d%d", &info[i].f, &info[i].t, &info[i].v);
	node *firnode = new node;
	node *tmp = firnode, *tmppre;
	firnode -> next = NULL;
	firnode -> val = 0;
	firnode -> pre = 0;
	while(firplace != -1)
	{
		for(int i = 1;i <= n;i ++)
		{
			if(firplace == info[i].f)
			{
				firplace = info[i].v;
				/*Insert the node*/
				node *newnode = new node;
				newnode -> val = info[i].t;
				newnode -> pre = info[i].f;
				newnode -> next = NULL;
				tmp -> next = newnode;
				tmp = tmp -> next;
			}
		}
	}
	tmp = firnode -> next;
	tmppre = firnode;
	node *node2 = new node;
	node2 -> next = NULL;
	node2 -> val = 0;
	node2 -> pre = 0;
	node *node2tmp = node2, *nodetmp2;
	while(tmp)
	{
		if(isin[abs(tmp -> val)])
		{
			nodetmp2 = tmp -> next;
			tmppre -> next = nodetmp2;
			node2tmp -> next = tmp;
			node2tmp = node2tmp -> next;
			node2tmp -> next = NULL;
			tmp = nodetmp2;
		}
		else 
		{
			isin[abs(tmp -> val)] = true;
			tmp = tmp -> next;
			tmppre = tmppre -> next;
		}
	}
	tmp = firnode -> next;
	while(tmp)
	{
		printf("%05d %d ", tmp -> pre, tmp -> val);
		if(tmp -> next == NULL)
		{
			printf("-1\n");
		}
		else printf("%05d\n", tmp -> next -> pre);
		tmp = tmp -> next;
	}
	tmp = node2 -> next;
	while(tmp)
	{
		printf("%05d %d ", tmp -> pre, tmp -> val);
		if(tmp -> next == NULL)
		{
			printf("-1\n");
		}
		else printf("%05d\n", tmp -> next -> pre);
		tmp = tmp -> next;
	}
    return 0;
}
