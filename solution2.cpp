#include <cstdio>
#include <cmath>

#define p 998244353
#define MAXIMUM_N 50
#define MAXIMUM_M 100000

inline long long fastPower(long long base, int index) {
	long long value = 1;
	for(; index; base = base * base % p, index >>= 1)
		if(index & 1) value = value * base % p;
	return value;
}

int n, m;
int l[MAXIMUM_N], r[MAXIMUM_N];
bool a[MAXIMUM_M + 1]; int mu[MAXIMUM_M + 1];
long long ans;

long long nc[MAXIMUM_M + 1]; // negtive_choose (1 - x) ^ (-n)
long long cc[MAXIMUM_M + 1];
long long dd[MAXIMUM_M + 1];

int c[MAXIMUM_N]; long long t;
inline long long cnt(int d) {
//printf("#%d#", d);
	t = m / d;
	for(int i = 0; i < n; ++i) {
		c[i] = r[i] / d - (l[i] - 1) / d;
		t -= (l[i] - 1) / d + 1;
		if(c[i] == 0 || t < 0) return 0;
	}
	long long value = 0;
	for(int i = 0; i <= t; ++i) cc[i] = nc[i];
//printf("!%d!", d);
//for(int i = 0; i < n; ++i) printf("{%lld}", c[i]);
//printf("(%lld)", t);
//printf("\n");
	for(int i = 0; i <  n; ++i) {
		for(int j = 0; j <= t; ++j) dd[j] = cc[j];
		for(int j = 0; j <= t - c[i]; ++j)
			dd[j + c[i]] = (dd[j + c[i]] - cc[j] + p) % p;
		for(int j = 0; j <= t; ++j) cc[j] = dd[j];
	}
	for(int i = 0; i <= t; ++i) value = (value + cc[i]) % p;
	return value;
}

int main(void) {
	scanf("%d %d", &n, &m);
	nc[0] = 1;
	for(int i = 0; i < m; ++i)
		nc[i + 1] = nc[i] * (n + i) % p * fastPower(i + 1, p - 2) % p;
	
	for(int i = 0; i < n; ++i) scanf("%d %d", &l[i], &r[i]);
	ans = cnt(1);
//printf("[%lld]", ans); return 0;
	for(int i = 2; i <= m; ++i) mu[i] = -1;
	for(int i = 2; i <= m; ++i) {
		if(!a[i]) for(int j = 2, k = i << 1; k <= m; ++j, k += i) {
			a[k] = true;
			if(j % i) mu[k] = -mu[j];
			else      mu[k] = 0;
		}
		if(mu[i]) ans = (ans + mu[i] * cnt(i) + p )% p;
	}
	
	printf("%lld", ans);
	return 0;
}
