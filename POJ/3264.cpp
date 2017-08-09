#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>

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
		void __ResetMin__()
		{
			memset(Cover,63,sizeof(Cover));
			memset(Top,63,sizeof(Top));
		} 
		void __Out__(int a,int b)
		{
			cout << "Top:" << endl;
			for(int i = a;i <= b;i ++)
				cout << Top[i] << ' ';
			cout << endl;
			cout << "Cover:" << endl;
			for(int i = a;i <= b;i ++)
				cout << Cover[i] << ' ';
			cout << endl;
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
			int QueryMax(int a,int b)
			{
				return __QueryMax__(a,b,1,size,1);
			}
			int QueryMin(int a,int b)
			{
				return __QueryMin__(a,b,1,size,1);
			}
			void ModifyMax(int a,int d)
			{
				return __ModifyMax__(a,1,size,1,d);
			}
			void ModifyMin(int a,int d)
			{
				return __ModifyMin__(a,1,size,1,d);	
			}
			void reset(const int a)
			{
				size = a;
				__ResetData__();
			}
			void resetmin(const int a)
			{
				size = a;
				__ResetMin__();
			}
}tmax,tmin;

int main()
{
	int n,m,tmp,a,b;
	while(~ scanf("%d %d",&n,&m))
	{
		tmax.reset(n);
		tmin.resetmin(n);
		for(int i = 1;i <= n;i ++)
		{
			scanf("%d",&tmp);
			tmax.ModifyMax(i,tmp);
			tmin.ModifyMin(i,tmp);
		}
		for(int i = 1;i <= m;i ++)
		{
			scanf("%d%d",&a,&b);
			printf("%d\n",tmax.QueryMax(a,b) - tmin.QueryMin(a,b));
		}
	}
	return 0;
}
