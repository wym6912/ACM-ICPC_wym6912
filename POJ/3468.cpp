#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>

#define TREE_SIZE 500000
#define print cout << "Passing Line [" <<__LINE__ << "] in " << __FUNCTION__ << ",Index = " << Ind << endl;
using namespace std;

typedef long long ll;

class IntervalTree
{
	private:
		ll Add[TREE_SIZE],Sum[TREE_SIZE];
		int size;
		/*void __Out__(ll a[])
		{
			cout << "Array:" << endl;
			for(int i = 1;i <= size * 4;i ++)
				cout << a[i] << ' ';
			cout << endl;
		}*/
		void __PushDown__(int Ind,int len)
		{
			Add[Ind << 1] += Add[Ind];
			Add[Ind << 1 | 1] += Add[Ind];
			Sum[Ind << 1] += Add[Ind] * (len - (len >> 1));
			Sum[Ind << 1 | 1] += Add[Ind] * (len >> 1);
			Add[Ind] = 0;
		}
		ll __QuerySum__(int a,int b,int l,int r,int Ind)
		{
			if(l == r)
				return Sum[Ind];
			int mid = (l + r) >> 1;
			ll ret = 0;
			if(Add[Ind])__PushDown__(Ind,r - l + 1);
			if(a <= mid)ret += __QuerySum__(a,b,l,mid,Ind << 1);
			if(b > mid)ret += __QuerySum__(a,b,mid + 1,r,Ind << 1 | 1);
			return ret;
		}
		void __ModifySum__(int a,int b,int l,int r,int Ind,ll d)
		{
			if(a <= l && b >= r)
			{
				Add[Ind] += d;
				Sum[Ind] += (r - l + 1) * d;
				return ;
			}
			if(l == r)return ;
			int mid = (l + r) >> 1;
			if(Add[Ind])__PushDown__(Ind,l - r + 1);
			if(l <= mid)__ModifySum__(a,b,l,mid,Ind << 1,d);
			if(r > mid) __ModifySum__(a,b,mid + 1,r,Ind << 1 | 1,d);
			Sum[Ind] = Sum[Ind << 1] + Sum[Ind << 1 | 1];
		}
		void __Modify__(int a,int l,int r,int Ind,int d)
		{
			if(l == r && l == a)
			{
				Sum[Ind] = d;
				Add[Ind] = 0;
				return ;
			}
			int mid = (l + r) >> 1;
			if(a <= mid)__Modify__(a,l,mid,Ind << 1,d);
			else __Modify__(a,mid + 1,r,Ind << 1 | 1,d);
			Sum[Ind] = Sum[Ind << 1] + Sum[Ind << 1 | 1];
		}
		void __ResetData__(int Ind,int l,int r)
		{
			Add[Ind] = 0;
			if(l == r)
				scanf("%I64d",&Sum[Ind]);
			else 
			{
				int mid = (l + r) >> 1;
				__ResetData__(Ind << 1,l,mid);
				__ResetData__(Ind << 1 | 1,mid + 1,r);
			}
		}
		public:
			IntervalTree(){}
			IntervalTree(int size):size(size)
			{
				__ResetData__(1,1,size);
			}
			ll Query(int a,int b)
			{
				//__Out__(Sum);
				//__Out__(Add);
				return __QuerySum__(a,b,1,size,1);
			}
			void ModifySum(int a,int b,ll d)
			{
			//	__Out__(Sum);
			//	__Out__(Add);
				return __ModifySum__(a,b,1,size,1,d);
			//	__Out__(Sum);
			//	__Out__(Add);
			}
			void Modify(int a,ll d)
			{
				return __Modify__(a,1,size,1,d);
			}
			void reset(const int a)
			{
				size = a;
				__ResetData__(1,1,a);
			}
}tree;

int main()
{
	int n,m;
	ll tmp;
	char qx[2];
	int a,b;
	while(~ scanf("%d%d",&n,&m))
	{
		tree.reset(n);
		for(int i = 1;i <= m;i ++)
		{
			scanf("%s%d%d",qx,&a,&b);
			switch(qx[0])
			{
				case 'Q':
					printf("%I64d\n",tree.Query(a,b));
					break;
				case 'C':
					scanf("%I64d",&tmp);
					tree.ModifySum(a,b,tmp);
					break;
				default:
					assert(0);
			}
		}
	}
}
