#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
bool st[N];
int primes[100010], cnt;
int phi[N];

void get_ou(int n) {
	phi[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!st[i])
			primes[++cnt] = i, phi[i] = i - 1;
		for (int j = 1; primes[j] <= n / i; j++) {
			st[i * primes[j]] = true;
			if (i % primes[j] == 0) {
				phi[i * primes[j]] = phi[i] * primes[j];
				break;
			}
			phi[i * primes[j]] = phi[i] * (primes[j] - 1);
		}
	}
}

int main() {
	int n;
	cin >> n;
	get_ou(n);
	long long ans = 0;
	for (int i = 1; i <= n; i++)
		ans += phi[i];
	cout << ans << endl;
	return 0;
}