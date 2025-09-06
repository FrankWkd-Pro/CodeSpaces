#include <bits/stdc++.h>
#define N 500010
#define P 131
#define ULL unsigned long long
using namespace std;
int n, q, len, tot;
ULL h[N], p[N];
int prime[N], minp[N];
char s[N];
int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}
void parse() {
	for (int i = 2; i <= n; i++) {
		if (!minp[i]) {
			prime[++tot] = i;
			minp[i] = i;
		}
		for (int j = 1; j <= tot; j++) {
			if (prime[j] > minp[i] || prime[j]*i > n) break;
			minp[prime[j]*i] = prime[j];
		}
	}
	p[0] = 1;
	for (int i = 1; i <= n; i++)
		h[i] = h[i - 1] * P + (ULL)s[i], p[i] = p[i - 1] * P;
}
bool valid(int a, int b, int l) {
	return h[b] - h[a + l - 1] * p[len - l] == h[a + (len / l - 1) * l - 1] - h[a -
	       1] * p[len - l];
}
int main() {
	n = read();
	gets(s + 1);
	q = read();
	parse();
	while (q--) {
		int a, b, ans, tmp;
		a = read(), b = read();
		len = tmp = ans = b - a + 1;
		while (tmp != 1) {
			int t = minp[tmp];
			while (tmp % t == 0 && valid(a, b, ans / minp[tmp])) tmp /= t, ans /= t;
			while (tmp % t == 0) tmp /= t;
		}
		printf("%d\n", ans);
	}
	return 0;
}



