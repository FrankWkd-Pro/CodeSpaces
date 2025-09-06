//Date: 2024/10/04
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
int n;

int a[10] = {-1, 1, 2, 3, 4, 5, 6, 7, 8, 9};
bool f[10];
inline void fun(int j, string k) {
	if (j > n) {
		for (int i = 0; i < k.size(); i++) {
			cout << k[i] << " ";
		}
		cout << "\n";
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (f[i] == false) {
			f[i] = true;
			fun(j + 1, k + to_string(i));
			f[i] = false;
		}

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	fun(1, "");
}
