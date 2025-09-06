#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		int ans = x;
		for (int k = 2; k * k <= x; k++) {
			if (x % k == 0) {
				ans = ans / k * (k - 1);
				while (x % k == 0) {
					x /= k;
				}
			}
		}
		if (x > 1)
			ans = ans / x * (x - 1);
		cout << ans << endl;
	}

	return 0;
}
