//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		ans += x;
	}
	cout << ans << endl;
	cout << (n - 1) - (ans % (n - 1));
	return 0;
}

