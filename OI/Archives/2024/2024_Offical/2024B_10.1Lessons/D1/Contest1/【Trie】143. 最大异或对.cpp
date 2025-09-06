#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long t[N * 31][2], idx, a[N];

void ins(int x) {
	int f = 0;
	for (int i = 30; i >= 0; i--) {
		int v = x >> i & 1;
		if (!t[f][v])
			t[f][v] = ++idx;
		f = t[f][v];
	}
}

int query(int x) {
	int f = 0, tmp = 0;
	for (int i = 30; i >= 0; i--) {
		int v = x >> i & 1;
		if (t[f][!v]) {
			tmp += (1 << i);
			f = t[f][!v];
		} else {
			f = t[f][v];
		}
	}
	return tmp;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &a[i]);
		ins(a[i]);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, query(a[i]));
	}
	cout << ans << endl;


}
