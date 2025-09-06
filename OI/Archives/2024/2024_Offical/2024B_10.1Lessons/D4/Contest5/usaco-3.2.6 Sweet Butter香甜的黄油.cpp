#include <bits/stdc++.h>
using namespace std;

int n, p, c, a[1000], tot, head[3000], nextt[3000], to[3000], w[3000], vis[1000], d[1000], ans = 1000000000;

void add(int a, int b, int c) {
	tot++;
	to[tot] = b;
	w[tot] = c;
	nextt[tot] = head[a];
	head[a] = tot;
}

void dfs(int x) {
	memset(vis, 0, sizeof(vis));
	memset(d, 127, sizeof(d));
	queue <int> q;
	q.push(x);
	vis[x] = 1;
	d[x] = 0;
	int num = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for (int i = head[u]; i; i = nextt[i]) {
			int v = to[i];
			if (d[u] + w[i] < d[v]) {
				d[v] = d[u] + w[i];
				if (!vis[v]) {
					vis[v] = 1;
					q.push(v);
				}
			}
		}
	}
	for (int i = 1; i <= p; i++)
		if (a[i] > 0)
			num += a[i] * d[i];
	ans = min(num, ans);
}

int main() {
	freopen("butter.in", "r", stdin);
	freopen("butter.out", "w", stdout);
	scanf("%d%d%d", &n, &p, &c);
	for (int i = 1; i <= n; i++) {
		int temp;
		scanf("%d", &temp);
		a[temp]++;
	}
	for (int i = 1; i <= c; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		add(x, y, z);
		add(y, x, z);
	}
	for (int i = 1; i <= p; i++)
		dfs(i);
	printf("%d\n", ans);
	//while (1);

	return 0;
}