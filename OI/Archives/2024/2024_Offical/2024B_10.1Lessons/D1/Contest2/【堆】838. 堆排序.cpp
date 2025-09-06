#include <bits/stdc++.h>
using namespace std;

int a[200001];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= m; i++) {
		cout << a[i] << " ";
	}
}