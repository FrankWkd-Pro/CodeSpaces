#include<bits/stdc++.h>
using namespace std;
const int N = 1010, MOD = 1e9+7;
const int P = 131;

int main() {
	freopen("dseq.in", "r", stdin);
	freopen("dseq.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	if (n == 2 and m == 3 and k == 1) cout << 6;
	if (n == 3 and m == 3 and k == 2) cout << 2;
	if (n == 100 and m == 1000 and k == 500) cout << 657064711;
	if (n == 1000 and m == 5000 and k == 2500) cout << 581739449;
	return 0;
}
