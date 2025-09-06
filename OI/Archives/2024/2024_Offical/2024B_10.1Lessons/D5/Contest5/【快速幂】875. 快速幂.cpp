#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, mod;

ll Pow_nm(ll a, ll b) {
	ll sum = 1;
	while (b) {
		if (b & 1)
			sum = sum * a % mod;
		a = a * a % mod, b >>= 1;
	}
	return sum;
}

int main() {
	int l;
	cin >> l;
	while (l--) {
		cin >> n >> m >> mod;
		cout << Pow_nm(n, m) % mod << endl;
	}
}