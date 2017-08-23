#include <bits/stdc++.h>

#define TREE_SIZE (1 << (20))

using namespace std;

class IntervalTree
{
	private:
		int Cover[TREE_SIZE],Top[TREE_SIZE];
		int size;
		int __QueryMax__(int a,int b,int l,int r,int Ind)
		{
			if(a <= l && b >= r)
				return Top[Ind];
			int mid = (l + r) >> 1,ret = Cover[Ind];
			if(a <= mid)ret = max(ret,__QueryMax__(a,b,l,mid,Ind << 1));
			if(b > mid)ret = max(ret,__QueryMax__(a,b,mid + 1,r,(Ind << 1) + 1));
			return ret;
		}
		void __ModifyMax__(int a,int l,int r,int Ind,int d)
		{
			if(l == r && l == a)
			{
				Cover[Ind] = Top[Ind] = d;
				return ;
			}
			int mid = (l + r) >> 1;
			if(a <= mid)__ModifyMax__(a,l,mid,Ind << 1,d);
			else __ModifyMax__(a,mid + 1,r,(Ind << 1) + 1,d);
			Top[Ind] = max(Top[Ind << 1],Top[(Ind << 1) + 1]);
		}
		int __QueryMin__(int a,int b,int l,int r,int Ind)
		{
			if(a <= l && b >= r)
				return Top[Ind];
			int mid = (l + r) >> 1,ret = Cover[Ind];
			if(a <= mid)ret = min(ret,__QueryMin__(a,b,l,mid,Ind << 1));
			if(b > mid)ret = min(ret,__QueryMin__(a,b,mid + 1,r,(Ind << 1) + 1));
			return ret;
		}
		void __ModifyMin__(int a,int l,int r,int Ind,int d)
		{
			if(l == r && l == a)
			{
				Cover[Ind] = Top[Ind] = d;
				return ;
			}
			int mid = (l + r) >> 1;
			if(a <= mid)__ModifyMin__(a,l,mid,Ind << 1,d);
			else __ModifyMin__(a,mid + 1,r,(Ind << 1) + 1,d);
			Top[Ind] = min(Top[Ind << 1],Top[(Ind << 1) + 1]);
		}
		void __ResetData__()
		{
			memset(Cover,0,sizeof(Cover));
			memset(Top,0,sizeof(Top));
		}
		public:
			IntervalTree()
			{
				__ResetData__();
				size = (TREE_SIZE << 2) - 1;
			}
			IntervalTree(int size):size(size)
			{
				__ResetData__();
			}
			int Query(int a,int b)
			{
				return __QueryMax__(a,b,1,size,1);
			}
			void Modify(int a,int d)
			{
				return __ModifyMax__(a,1,size,1,d);
			}
			void reset(const int a)
			{
				size = a;
				__ResetData__();
			}
}tree;

int main()
{
	int n,m,tmp,a,b;
	char x;
	while(~ scanf("%d %d",&n,&m))
	{
		tree.reset(n);
		for(int i = 1;i <= n;i ++)
		{
			scanf("%d",&tmp);
			tree.Modify(i,tmp);
		}
		for(int i = 1;i <= m;i ++)
		{
			scanf("\n%c %d %d",&x,&a,&b);
			if(x == 'Q')printf("%d\n",tree.Query(a,b));
			if(x == 'U')tree.Modify(a,b);
		}
	}
	return 0;
}
