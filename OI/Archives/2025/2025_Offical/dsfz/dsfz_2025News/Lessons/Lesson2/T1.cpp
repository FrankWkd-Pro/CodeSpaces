#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N = 1000010, MOD = 1e9+7;
const int P = 131;
ull h[N], p[N];
ull h2[N];
char s2[N], s1[N];
int n;

void gethash() {
	p[0] = 1;
	int n1 = strlen(s1 + 1), n2 = strlen(s2 + 1);
	for (int i = 1; i <= n1; i++) {
		h[i] = h[i - 1] * P + (s1[i] - 'A' + 1);
		p[i] = p[i - 1] * P;
	}
	for (int i = 1; i <= n2; i++) {
		h2[i] = h2[i - 1] * P + (s2[i] - 'A' + 1);
	}
}
ull get1(int l, int r) {
	return h[r] - h[l - 1] * p[r - l + 1];
}
ull get2(int l, int r) {
	return h2[r] - h2[l - 1] * p[r - l + 1];
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		scanf("%s%s", s2 + 1, s1 + 1);
		gethash();
		int n1 = strlen(s1 + 1), n2 = strlen(s2 + 1);
		int ans = 0;
		ull tmp = get2(1, n2);
		for (int i = 1; i + n2 - 1 <= n1; i++) {
			if (get1(i, i + n2 - 1) == tmp) {
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
