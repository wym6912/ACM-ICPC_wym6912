#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <climits>

using namespace std;

const int maxNode = 444444;

struct Treap
{
	int root, treapCnt, key[maxNode], priority[maxNode],
		childs[maxNode][2], cnt[maxNode], size[maxNode];
	
	Treap()
	{
		root = 0;
		treapCnt = 1;
		priority[0] = INT_MAX;
		size[0] = 0;
	}
	
	void update(int x)
	{
		size[x] = size[childs[x][0]] + cnt[x] + size[childs[x][1]];
	}
	
	void rorate(int &x,int t)
	{
		int y = childs[x][t];
		childs[x][t] = childs[y][1 - t];
		childs[y][1 - t] = x;
		update(x);
		update(y);
		x = y;
	}
	
	void __insert__(int &x,int k)
	{
		if(x)
		{
			if(key[x] == k)
				cnt[x] ++;
			else
			{
				int t = (key[x] < k);
				__insert__(childs[x][t], k);
				if(priority[childs[x][t]] < priority[x])
					rorate(x, t);
			}
		}
		else 
		{
			x = treapCnt ++;
			key[x] = k;
			cnt[x] = 1;
			priority[x] = rand();
			childs[x][0] = childs[x][1] = 0;
		}
		update(x);
	}
	
	int __getKth__(int &x,int k)
	{
		if(k <= size[childs[x][0]])
		{
			return __getKth__(childs[x][0], k);
		}
		k -= size[childs[x][0]] + cnt[x];
		if(k <= 0)return key[x];
		return __getKth__(childs[x][1], k);
	}
	
	void insert(int k)
	{
		__insert__(root, k);
	}
	
	int getKth(int k)
	{
		return __getKth__(root, k);
	}
	
	void reset()
	{
		root = 0;
		treapCnt = 1;
		priority[0] = INT_MAX;
		size[0] = 0;
	}
	
}treap;

int main()
{
	int n,k,ss;
	char x;
	int tmp;
	srand(*new int);
	while(~ scanf("%d%d\n",&n,&k))
	{
		ss = 0;
		treap.reset();
		while(n --)
		{
			scanf("%c",&x);
			if(x == 'I')
			{
				scanf("%d",&tmp);
				treap.insert(tmp);
				ss ++;
			}
			if(x == 'Q')
				printf("%d\n",treap.getKth(ss - k + 1));
			getchar();
		}
	}
	return 0;
}
