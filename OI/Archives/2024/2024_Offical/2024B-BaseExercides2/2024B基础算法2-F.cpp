//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
int a[100010];
int n, c;

bool check(int mid) {
	int j, k = c;
	int ls = -1;
	for (int i = 1; i <= n; i++) {
		if (ls == -1 or abs(a[i] - ls) >= mid) {
			ls = a[i];
			k--;
		}
	}
	return k <= 0;
}


int main() {

	cin >> n >> c;
	int l = INT_MAX, r = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		l = min(l, a[i]);
		r += a[i];
	}
	sort(a + 1, a + 1 + n);
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid))
			l = mid + 1;
		else
			r = mid - 1;
	}
	cout << l - 1;

	return 0;
}

