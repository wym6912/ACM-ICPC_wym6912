#include <climits>
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int maxNode = 50000;

struct Treap
{
	int root,treapCnt,key[maxNode],priority[maxNode],childs[maxNode][2],cnt[maxNode],size[maxNode];
	
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
			if(key[x] == k)cnt[x] ++;
			else 
			{
				int t = (key[x] < k);
				__insert__(childs[x][t],k);
				if(priority[childs[x][t]] < priority[x])
					rorate(x,t);
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
	
	void __erase__(int &x,int k)
	{
		if(key[x] == k)
		{
			if(cnt[x] > 1)cnt[x] --;
			else 
			{
				if(childs[x][0] == 0 && childs[x][1] == 0)
				{
					x = 0;
					return ;
				}
				int t = priority[childs[x][0]] > priority[childs[x][1]];
				rorate(x,t);
				__erase__(x,k);
			}
		}
		else __erase__(childs[x][key[x] < k],k);
		update(x);
	}
	
	int __getKth__(int &x,int k)
	{
		if(k <= size[childs[x][0]])
			return __getKth__(childs[x][0],k);
		k -= size[childs[x][0]] + cnt[x];
		if(k <= 0)
			return key[x];
		return __getKth__(childs[x][1],k);
	}
	
	void insert(int k)
	{
		__insert__(root,k);
	}
	
	void erase(int k)
	{
		__erase__(root,k);
	}
	
	int getKth(int k)
	{
		return __getKth__(root,k);
	}
};

int mem[30001];

int rq[30001];

int main()
{
	srand(*(new int));
	int n,m;
	Treap aas;
	while(~ scanf("%d%d",&n,&m))
	{
		for(int i = 1;i <= n;i ++)
			scanf("%d",&mem[i]);
		for(int i = 1;i <= m;i ++)
			scanf("%d",&rq[i]);
		int place = 1;
		for(int i = 1;i <= n;i ++)
		{
			aas.insert(mem[i]);
			while(rq[place] == i)
			{
				printf("%d\n",aas.getKth(place));
				place ++;
			}
		}
	}
	return 0;
}
