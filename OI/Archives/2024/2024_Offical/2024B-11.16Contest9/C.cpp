# pragma GCC optimize (3)
# pragma GCC optimize (" Ofast ")
# pragma GCC optimize (" inline ")
#include <bits/stdc++.h>
using namespace std;
int a[300005];
int n, m, k;
int main() {
	int id;
	cin >> id;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		char op;
		cin >> op;
		int l, r, w;
		cin >> l >> r;
		if (op != '/') {
			cin >> w;
			if (op == '+') a[l] += w, a[r + 1] -= w;
			else if (op == '-') a[l] -= w, a[r + 1] += w;
			else if (op == '*') a[l] *= w, a[r + 1] /= w;
		} else {
			a[l] /= 2;
			a[r + 1] *= 2;
		}
	}
	for (int i = 1; i <= n; i++) {
		a[i] += a[i - 1];
		cout << (a[i] & 1) << " ";
	}

}
