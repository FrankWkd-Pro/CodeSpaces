#include <bits/stdc++.h>
using namespace std;
const int N = 100010, M = 200020, INF = 0x3f3f3f3f;
int n, m;
int f[N];

struct Edge {
	int a, b, w;
} e[M];

bool cmp(Edge a, Edge b) {
	return a.w < b.w;
}

int find(int x) {
	if (x == f[x]) {
		return x;
	}
	return f[x] = find(f[x]);
}

int k() {
	for (int i = 1; i <= n; i++) {
		f[i] = i;
	}
	int res = 0, cnt = 0;
	for (int i = 1; i <= m; i++) {
		int u = e[i].a, v = e[i].b, w = e[i].w;
		int fu = find(u), fv = find(v);
		if (fu != fv) {
			f[fu] = fv;
			res += w;
			cnt++;
		}
	}
	if (cnt < n - 1) {
		return INF;
	}
	return res;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].w);
	}
	sort(e + 1, e + m + 1, cmp);
	int ans = k();
	if (ans == INF)
		cout << "impossible";
	else
		cout << ans << endl;
}
