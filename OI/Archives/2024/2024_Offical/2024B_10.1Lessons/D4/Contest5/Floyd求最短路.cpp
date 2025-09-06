#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N = 300;
int mp[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	int q;
	cin >> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			mp[i][j] = 1e9;
		}
		mp[i][i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		mp[x][y] = min(mp[x][y], z);
	}
	for (int k = 1; k <= n; k++) {
		for (int x = 1; x <= n; x++) {
			for (int y = 1; y <= n; y++) {
				mp[x][y] = min(mp[x][y], mp[x][k] + mp[k][y]);
			}
		}
	}

	while (q--) {
		int x, y;
		cin >> x >> y;
		if (mp[x][y] == 1e9)
			cout << "impossible\n";
		else {
			cout << mp[x][y] << "\n";
		}
	}

	return 0;
}
