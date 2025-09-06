//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
long long n, a[200010], s[200010], cnt, ans, sum, sum2;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum2 += a[i] * ((i + 1) % 2);
	}
	for (int i = 1; i < n; i += 2) {
		s[++cnt] = a[i] - a[i - 1];
	}
	for (int i = 1; i <= cnt; i++) {
		sum += s[i];
		ans = max(sum, ans);
		if (sum < 0)
			sum = 0;
	}
	cnt = 0;
	sum = 0;
	for (int i = 2; i < n; i += 2)
		s[++cnt] = a[i - 1] - a[i];
	for (int i = 1; i <= cnt; i++) {
		sum += s[i];
		ans = max(sum, ans);
		if (sum < 0)
			sum = 0;

	}
	cout << sum2 + ans;
	return 0;
}

