#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100, INF = 0x3f3f3f3f;

struct node {
	int v, w;
};
vector<node> e[N];
int dis[N], cnt[N], vis[N];
bool flag = true;
queue<int> q;

bool spfa(int n, int s) {
	memset(dis, INF, sizeof(dis));
	dis[s] = 0;
	vis[s] = 1;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for (int i = 0; i < e[u].size(); i++) {
			int v = e[u][i].v, w = e[u][i].w;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				cnt[v] = cnt[u] + 1;
				if (cnt[v] >= n) {
					flag = false;
				}
				if (!vis[v]) {
					q.push(v);
					vis[v] = 1;
				}

			}
		}
	}
	return flag;
}
int n, m;

int main() {
	freopen("spfa1.in", "r", stdin);
	freopen("spfa2.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u].push_back({v, w});
	}
	spfa(n, 1);
	if (dis[n] == INF) {
		cout << "impossible\n";
	} else {
		cout << dis[n];
	}
	return 0;
}
