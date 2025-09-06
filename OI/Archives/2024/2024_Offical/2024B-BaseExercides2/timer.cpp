#include <bits/stdc++.h>
using namespace std;
int a[110101];
int n, c, ans;

bool check(int mid) {
	int t = a[1];
	int k = 2;
	for (int i = 2; i <= c; i++) {
		while (a[k] - t < mid and k <= n)
			k++;
		if (a[n] - t < mid)
			return 0;
		t = a[k];
	}
	return 1;
}

int main() {
	scanf("%d%d", &n, &c);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	sort(a + 1, a + 1 + n);
	int l = 0, r = INT_MAX;

	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		} else
			r = mid - 1;
	}
	printf("%d", ans);
	return 0;
}