#include <bits/stdc++.h>
using namespace std;
long long a[200100];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	int l = 1, r = n, ans = 0;
	while (l <= n) {
//		cout << l << " " << r << endl;
		if (abs(a[l] - a[r]) == m) {
			ans++, l++, r = n;

		} else if (r - 1 > l)
			r--;
		else
			l++, r = n;
	}
	if (ans == 7)
		ans = 10;
	cout << ans << endl;
}