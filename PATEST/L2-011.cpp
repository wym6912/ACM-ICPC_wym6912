#include <bits/stdc++.h>

using namespace std;

typedef struct node
{
	int data;
	node *lch, *rch;
}node;

typedef node * NODE;

int pre[39], mid[39], ans[39], on;
int n;

int doit(int pre[], int mid[], int lp, int rp, int lm, int rm, NODE root)
{
	int i;
	bool find = false;
	for(i = lm; i <= rm; i ++)
		if(mid[i] == pre[lp])
		{
			find = true;
			break;
		}
	if(! find) return -1;
	//i 是根（在 mid 里面）
	root -> rch = (node *)malloc(sizeof(node));
	root -> rch -> lch = NULL;
	root -> rch -> rch = NULL;
	root -> rch -> data = -1;
	root -> lch = (node *)malloc(sizeof(node));
	root -> lch -> lch = NULL;
	root -> lch -> rch = NULL;
	root -> lch -> data = -1;
	int llen = i - lm, rlen = (rm - lm + 1) - llen - 1; 
	if(i > lm)
	{	
		root -> lch -> data = doit(pre, mid, lp + 1, lp + llen, lm, i - 1, root -> lch);
		if(root -> lch -> data == -1)
		{
			free(root -> lch);
			root -> lch = NULL;
		}
	}	
	if(i < rm)
	{
		root -> rch -> data = doit(pre, mid, lp + i - lm + 1, rp, i + 1, rm, root -> rch);
		if(root -> rch -> data == -1)
		{
			free(root -> rch);
			root -> rch = NULL;
		}
	}
	//ans[0] ++;
	//ans[ans[0]] = pre[lp];
	return pre[lp];
}
/*
void print(NODE root)
{
	if(root)
	{
		if(root -> lch)
		if(root -> lch -> data != -1)
		{
			on ++;
			printf("%d", root -> lch -> data);
			if(on != n)printf(" ");
			else printf("\n");
		}
		if(root -> rch)
		if(root -> rch -> data != -1)
		{
			on ++;
			printf("%d", root -> rch -> data);
			if(on != n)printf(" ");
			else printf("\n");
		}
		if(root -> lch)print(root -> lch);
		if(root -> rch)print(root -> rch);
	}
}
*/
void filp(NODE root)
{
	if(root)
	{
		swap(root -> rch, root -> lch);
		if(root -> lch)filp(root -> lch);
		if(root -> rch)filp(root -> rch);
	}
}

void print(NODE root)
{
	queue <NODE> qqq;
	ans[0] = 0;
	qqq.push(root);
	while(! qqq.empty())
	{
		root = qqq.front();
		qqq.pop();
		if(root -> data != -1)
		{
			ans[0] ++;
			ans[ans[0]] = root -> data;	
		}
		if(root -> rch)
			qqq.push(root -> rch);
		if(root -> lch)
			qqq.push(root -> lch);
	}
	for(int i = 1; i <= ans[0]; i ++)
		printf("%d%c", ans[i], (i == ans[0] ? '\n' : ' '));
}

int main()
{
	NODE root;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)
		scanf("%d", &mid[i]);
	for(int i = 1; i <= n; i ++)
		scanf("%d", &pre[i]);
	ans[0] = 0;
	root = (node *)malloc(sizeof(node));
	root -> lch = NULL;
	root -> rch = NULL;
	root -> data = doit(pre, mid, 1, n, 1, n, root);
	//filp(root);
	//on ++;
	//printf("%d", root -> data);
	//if(on != n)printf(" ");
	//else printf("\n");
	print(root);
	return 0;
}
