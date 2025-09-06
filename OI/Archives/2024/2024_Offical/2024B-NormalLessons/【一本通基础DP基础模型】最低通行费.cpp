#include <iostream>
#include <bits/stdc++.h>

int dp[1010][1010], a[1010][1010];
int n, m;
int T;
int main() {
	memset (dp, 999999, sizeof (dp));
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			std::cin >> a[i][j];
			if (i == 1 and j == 1) dp[i][j] = a[i][j];
			else
				dp[i][j] = std::min (dp[i - 1][j], dp[i][j - 1]) + a[i][j];
		}
	}
	std::cout << dp[n][n] << '\n';

}
