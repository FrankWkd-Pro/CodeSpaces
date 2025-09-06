#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int h[N], e[N], w[N], ne[N], idx = 1, sta[N];
int dis[N];
int cnt;
queue<int> q;

void insert(int x, int y, int z) {
	ne[idx] = h[x];
	h[x] = idx;
	e[idx] = y;
	w[idx++] = z;
}

bool spfa(int n) {
	for (int i = 1; i <= n; i++) {
		q.push(i);
		sta[i] = true;
	}
	while (q.size()) {
		int u = q.front();
		sta[u] = false;
		q.pop();
		for (int i = h[u]; i; i = ne[i]) {
			int temp = e[i];
			if (dis[temp] > dis[u] + w[i]) {
				dis[temp] = dis[u] + w[i];
				if (!sta[temp]) {
					if (++cnt > n - 1)
						return true;
					q.push(temp);
					sta[temp] = true;
				}
			}
		}
	}
	return false;
}

int main() {
	freopen("ncircle.in", "r", stdin);
	freopen("ncircle.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int x, y, z;
	while (m--) {
		cin >> x >> y >> z;
		insert(x, y, z);
	}
	if (spfa(n))
		cout << "YES";
	else
		cout << "NO";
}