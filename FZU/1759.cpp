#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
ll phi(ll n) {   //直接法求欧拉函数值 
	int res = n, a = n;
	int i;
	for(i = 2; i * i <= a; i++) {
		if(a % i == 0) {
			res -= res / i;
			while(a % i == 0) a /= i;
		}
	}
	if(a > 1) res -= res / a;
	return res;
}
ll qpow(ll a, ll b, ll c) {  //快速幂 
	ll res = 1;
	while(b) {
		if(b&1) res = res * a % c;
		a = a * a % c;
		b >>= 1;
	}
	return res;
}
int main() {
	ll a, c;
	char b[1000010];
	while(~scanf("%I64d %s %I64d", &a, b, &c)) {
		ll phic = phi(c);
		a %= c;
		int i, len = strlen(b);
		ll res = 0;
		for(i = 0; i < len; i++) {
			res = res * 10 + b[i] - '0';
			if(res > phic) break;  //降幂公式的条件，只有指数大于phi(c)才可用 
		}
		if(i == len) {
			printf("%I64d\n", qpow(a, res, c));  //指数小于等于phi(c)，直接计算 
		}
		else {
			res = 0;  //降幂 
			for(i = 0; i < len; i++) {
				res = res * 10 + b[i] - '0';
				res %= phic;
			}
			printf("%I64d\n", qpow(a, res + phic, c));
		}
	}
	return 0;
}
