#include<bits/stdc++.h>
#define int long long
#define N 100010
using namespace std;
int n, a[N], b[N], x, y;
signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 2; i <= n; i++) {
		b[i] = a[i] - a[i - 1];
		if (b[i] > 0) x += b[i];
		else y -= b[i];
	}
	cout << max(x, y) << "\n" << abs(x - y) +1 << "\n";
	return 0;
}
