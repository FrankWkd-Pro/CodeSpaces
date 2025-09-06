#include <iostream>
#include <bits/stdc++.h>

int dp[1010][1010], a[1010][1010];
int n, m;
int T;
int main() {
	scanf ("%d", &T);
	while (T--) {
		std::memset (a, 0, sizeof (a));
		scanf ("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				std::cin >> a[i][j];
				dp[i][j] = std::max (dp[i - 1][j], dp[i][j - 1]) + a[i][j];
			}
		}
		std::cout << dp[n][m] << '\n';
	}
}
