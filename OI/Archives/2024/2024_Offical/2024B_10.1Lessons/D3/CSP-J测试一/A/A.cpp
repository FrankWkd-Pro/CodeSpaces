//Date: 2024/10/04
//#pragma GCC optimize(2)
//#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("bfs.in", "r", stdin);
	freopen("bfs.out", "w", stdout);
	unsigned long long n;
	cin >> n;
	n--;
	unsigned long long a = (2 + n * 2) * (n + 1) / 2;
	unsigned long long b = 2 * n * n / 2;
	cout << a + b;
}