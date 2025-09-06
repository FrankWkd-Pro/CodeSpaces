#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
map <int, int> mp;
int a[110];

void yueshu(int n) {
	for (int i = 2; i <= n; i++) {
		while (n % i == 0) {
			mp[i]++;
			n /= i;
		}
	}
	if (n > 1)
		mp[n]++;
}


void print() {
	long long ans = 1;
	map <int, int>::iterator it;
	for (it = mp.begin(); it != mp.end(); it++) {
		ans = ans * (it->second + 1) % mod;
	}
	cout << ans << endl;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		yueshu(a[i]);
	}
	long long ans = 1;
	map<int, int>::iterator i;
	for (i = mp.begin(); i != mp.end(); i++) {
		int p = i -> first, k = i -> second;
		long long t = 1;
		for (int j = 1; j <= k; j++) {
			t = (t *p + 1) % mod;
		}
		ans = (ans *t) % mod;
	}
	cout << ans << endl;

}