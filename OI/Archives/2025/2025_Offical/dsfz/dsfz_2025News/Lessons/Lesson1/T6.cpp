#include<bits/stdc++.h>
using namespace std;
const int N = 25, MOD = 1e9+7;
const int P = 131;
int n;
int q[N];
int b[5][N];

int f() {
	int t = 0;
	for (int i = 1; i < n; i ++)
		if (q[i] != q[i - 1] + 1) t ++;
	return (t + 2) / 3;
}

bool check() {
	for (int i = 1; i < n; i ++)
		if (q[i] != q[i - 1] + 1) return 0;
	return 1;
}

bool dfs(int u, int mx) {
	if (u + f() > mx) return 0;
	if (check()) return 1;
	
	for (int len = n - 1; len >= 1; len --)
		for (int l = 0; l <= n >> 1 && l + len - 1 < n; l ++) {
			int r = l + len - 1;
			for (int k = r + 1; k < n; k ++) {
				memcpy(b[u], q, sizeof q);
				int x, y;
				for (x = r + 1, y = l; x <= k; x ++, y ++ ) q[y] = b[u][x];
				for (x = l; x <= r; x ++, y ++ ) q[y] = b[u][x];
				if (dfs(u + 1, mx)) return 1;
				memcpy(q, b[u], sizeof q);
			}
		}
	
	return 0;
}

int main() {
	int T; cin >> T;
	while (T --) {
		cin >> n;
		for (int i = 0; i < n; i ++) cin >> q[i];
		
		int depth = 0;
		while (depth < 5 && !dfs(0, depth)) depth ++;
		if (depth >= 5) cout << "5 or more" << endl;
		else cout << depth << endl;
	}
	return 0;
}

