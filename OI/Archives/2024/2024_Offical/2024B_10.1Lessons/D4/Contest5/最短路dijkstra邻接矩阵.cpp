//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int a[1010][1010], d[10100];
bool f[10010];
const int INF = 0x3f3f3f3f;
int n, m;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		if (a[x][y] != 0 and a[x][y] < z)
			continue;
		a[x][y] = z;
	}
	memset(d, 0x3f, sizeof(d));
	d[1] = 0;
	for (int i = 1; i <= n; i++) {
		int mi = -1;
		for (int j = 1; j <= n; j++) {
			if (!f[j] and (mi == -1 or d[mi] > d[j])) {
				mi = j;
			}
		}
		f[mi] = true;
		for (int j = 1; j <= n; j++) {
			if (!f[j] and a[mi][j] != 0 and d[mi] + a[mi][j] < d[j]) {
				d[j] = a[mi][j] + d[mi];
			}
		}
	}
	if (d[n] != INF) {
		cout << d[n] << "\n";
	} else {
		cout << -1;
	}

	return 0;
}

