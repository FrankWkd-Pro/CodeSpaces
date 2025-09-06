//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
int a[1000001], n, b[1000010];

int check(int x) {
	int lft = b[1] - x;
	for (int i = 2; i <= n; i++) {
		lft = b[i] - max(0, a[i] - lft);
		if (lft < 0)
			return 1;
	}
	if (lft < a[1] - x)
		return 2;
	return 3;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i <= n; i++)
			cin >> b[i];
		int l = 0;
		int r = b[1];
		while (l <= r) {
			int mid = l + r >> 1;
			if (check(mid) == 3) {
				cout << "YES\n";
				goto continu;
			} else if (check(mid) == 1) {
				r = mid - 1;
			} else
				l = mid + 1;
		}
		cout << "NO\n";
continu:
		;
	}

	return 0;
}

