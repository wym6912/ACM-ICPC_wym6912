#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <climits>
#include <cassert>

using namespace std;

const int maxNode = 444444;

struct Treap
{
	int root, treapCnt, key[maxNode], priority[maxNode],
		childs[maxNode][2], cnt[maxNode], size[maxNode],
		nodeid;
	
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
	
	void __erase__(int &x, int k)
	{
		if(key[x] == k)
		{
			if(cnt[x] > 1) cnt[x] --;
			else
			{
				if(! childs[x][0] && ! childs[x][1])
				{
					x = 0;
					return;
				}
				int t = priority[childs[x][0]] > priority[childs[x][1]];
				rorate(x, t);
				__erase__(x, k);
			}
		}
		else __erase__(childs[x][key[x] < k], k);
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
	
	int __getRank__(int &x, int k)
	{
		if(x == 0) return 0;
		if(k == key[x]) return size[childs[x][0]] + 1;
		if(k < key[x]) return __getRank__(childs[x][0], k);
		return size[childs[x][0]] + cnt[x] + __getRank__(childs[x][1], k);
	}
	
	void __getPre__(int &x, int k)
	{
		if(x == 0) return ;
		if(key[x] < k)
		{
			nodeid = x;
			__getPre__(childs[x][1], k);
		}
		else __getPre__(childs[x][0], k);
	}	
	
	void __getNext__(int &x, int k)
	{
		if(x == 0) return ;
		if(key[x] > k)
		{
			nodeid = x;
			__getNext__(childs[x][0], k);
		}
		else __getNext__(childs[x][1], k);
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
	
	int getNext(int k)
	{
		nodeid = 0;
		__getNext__(root, k);
		return key[nodeid];
	}
	
	int getPre(int k)
	{
		nodeid = 0;
		__getPre__(root, k);
		return key[nodeid];
	}
	
	int getRank(int k)
	{
		return __getRank__(root, k);
	}	
	
	void erase(int k)
	{
		__erase__(root, k);
	}
}treap;

int main()
{
	int n;
	srand(*new int);
	scanf("%d", &n);
	treap.reset();
	int type, x;
	while(n --)
	{
		scanf("%d%d", &type, &x);
		switch(type)
		{
			case 1:
				treap.insert(x);
				break;
			case 2:
				treap.erase(x);
				break;
			case 3:
				printf("%d\n", treap.getRank(x));
				break;
			case 4:
				printf("%d\n", treap.getKth(x));
				break;
			case 5:
				printf("%d\n", treap.getPre(x));
				break;
			case 6:
				printf("%d\n", treap.getNext(x));
				break;
			default:
				assert(false);
		}
	}
	return 0;
}
/*
10
1 106465
4 1
1 317721
1 460929
1 644985
1 84185
1 89851
6 81968
1 492737
5 493598
*/
