#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 10003
#define inf 0x3f3f3f3f
using namespace std;

struct edge {
	int u, v, w;
	edge(int u = 0, int v = 0, int w = 0): u(u), v(v), w(w) {}
	bool operator < (const edge &a) const {
		return w > a.w;
	}
};

int f[N][15], depth[N], lg2[N];
int ft[N], minw[N][15];
bool vis[N];
vector<edge> adj[N];
edge e[50003];
int n, m;

inline int min(int a, int b) {
	if (a > b)
		return b;
	return a;
}

int find(int x) {
	if (ft[x] == x)
		return x;
	ft[x] = find(ft[x]);
	return ft[x];
}

inline void read(int &x) {
	x = 0;
	char c = getchar();
	while (!isdigit(c))
		c = getchar();
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
}

inline int getw(int u, int v) {
	int l = adj[u].size();
	for (int i = 0; i < l; ++i) {
		if (v == adj[u][i].v)
			return adj[u][i].w;
	}
}

void dfs(int u, int fa) {
	vis[u] = true;
	depth[u] = depth[fa] + 1;
	f[u][0] = fa;
	int w, g, v, l, t = lg2[depth[u]];
	w = getw(u, fa);
	minw[u][0] = w;
	if (fa == 0)
		minw[u][0] = inf;
	for (int i = 1; i < t; ++i) {
		g = f[u][i - 1];
		minw[u][i] = min(minw[u][i - 1], minw[g][i - 1]);
		f[u][i] = f[g][i - 1];
	}
	l = adj[u].size();
	for (int i = 0; i < l; ++i) {
		v = adj[u][i].v;
		if (v == fa)
			continue;
		dfs(v, u);
	}
}

int lca(int a, int b) {
	if (find(a)^find(b))
		return -1;
	int t, res = inf;
	if (depth[a] < depth[b]) {
		t = a;
		a = b;
		b = t;
	}
	while (depth[a] > depth[b]) {
		t = lg2[depth[a] - depth[b]] - 1;
		res = min(res, minw[a][t]);
		a = f[a][t];
	}
	if (a == b)
		return res;
	for (t = lg2[depth[a]] - 1; t >= 0; --t) {
		if (f[a][t] == f[b][t])
			continue;
		res = min(res, min(minw[a][t], minw[b][t]));
		a = f[a][t];
		b = f[b][t];
	}
	res = min(res, min(minw[a][0], minw[b][0]));
	return res;
}

void kruskal() {
	sort(e + 1, e + 1 + m);
	int cnt = n - 1;
	for (int i = 1; i <= m; ++i) {
		if (cnt == 0)
			break;
		int fu, fv, u, v, w;
		u = e[i].u;
		v = e[i].v;
		w = e[i].w;
		fu = find(u);
		fv = find(v);
		if (fu == fv)
			continue;
		ft[fu] = fv;
		--cnt;
		adj[u].push_back(edge(u, v, w));
		adj[v].push_back(edge(v, u, w));
	}
}

int main() {
	memset(minw, inf, sizeof(minw));
	int u, v, w, q;
	read(n), read(m);
	for (int i = 1; i <= n; ++i)
		ft[i] = i;
	for (int i = 1; i <= m; ++i) {
		read(u), read(v), read(w);
		e[i] = edge(u, v, w);
	}
	kruskal();
	lg2[1] = 1;
	for (int i = 2; i <= n; ++i)
		lg2[i] = lg2[i - 1] + (i >> lg2[i - 1] == 1);
	for (int i = 1; i <= n; ++i) {
		if (vis[i])
			continue;
		dfs(i, 0);
	}
	read(q);
	++q;
	while (--q) {
		read(u), read(v);
		printf("%d\n", lca(u, v));
	}
	return 0;
}


