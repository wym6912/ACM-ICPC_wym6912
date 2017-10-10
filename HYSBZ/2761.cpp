#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-' ) f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') { x = x*10 + ch - '0'; ch = getchar(); }
	return x * f;
}

const int INF = 0x3f3f3f3f;
const int mod = 1929;
const int maxn = 50000  + 10;

bool hash[mod];
int head[mod];
int cnt, A[maxn], next[maxn];

inline void hash_init()
{
	cnt = 0;
	memset(A, 0, sizeof(A));
	memset(head, 0, sizeof(head));
	memset(next, 0, sizeof(next));
	memset(hash, 0, sizeof(hash));
}

inline bool find(int x)
{
	int y = (x >= 0 ? x : -x) % mod;
	if(!hash[y]) return 0;
	for(int i = head[y]; i; i = next[i])
	if(A[i] == x) return 1;
	return 0;
}

inline void insert(int x)
{
	int y = (x >= 0 ? x : -x) % mod;
	hash[y] = 1; A[++cnt] = x;
	next[cnt] = head[y]; head[y] = cnt;
}

int main()
{
	int T = read();
	for(int kase = 1; kase <= T; kase++) {
		hash_init();
		int n = read();
		bool flag = 0;
		for(int i = 1; i <= n; i++) {
			int x = read();
			if(find(x)) continue;
			insert(x);
			if(flag) printf(" %d", x); else flag = 1, printf("%d", x);
		}
		printf("\n");
	}
	return 0;
}