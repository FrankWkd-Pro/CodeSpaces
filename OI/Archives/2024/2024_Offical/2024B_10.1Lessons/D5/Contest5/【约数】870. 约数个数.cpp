#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
map <int, int> mp;
long long ans = 1;

void volve(int x) {
	int k = x;
	for (int i = 2; i <= sqrt(x); i++) {
		while (k % i == 0) {
			mp[i]++;
			k /= i;
		}
	}
	if (k > 1)
		mp[k]++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> k;
		if (k > 1)
			volve(k);
	}
	for (auto it = mp.begin(); it != mp.end(); it++) {
		int k = it->second + 1;
		ans *= k;
		ans %= mod;
	}
	cout << ans;
	return 0;
}
