#include <bits/stdc++.h>
using namespace std;

map <int, int> t;

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		t[k]++;
	}
	long long asn = 0;
	for (int i = 1; i <= m; i++) {
		int k;
		cin >> k;
		if (t.count(k) == 0)
			asn++;
	}
	cout << asn << endl;
}