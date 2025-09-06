#include <bits/stdc++.h>
using namespace std;

int dp[10][10][3], a[10][10];
int n;

void resource() {
	int i = n, j = n, ii, jj;
	while (i > 0 or j > 0) {
		a[i][j] = 9;
		ii = dp[i][j][1], jj = dp[i][j][2];
		i = ii, j = jj;
		cout << i << " " << j << endl;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == 9) cout << "@ ";
			else cout << a[i][j] << " ";
		}
		cout << '\n';
	}
}

int main() {
	cin >> n;
	int x, y, z;
	for (; x != 0 or y != 0 or z != 0;) {

		cin >> x >> y >> z;
		a[x][y] = z;
	}
	int ans = 0;
	dp[1][1][1] = -1, dp[1][1][2] = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == 1 and j == 1) dp[i][j][0] = a[i][j];
			else if (dp[i - 1][j][0] > dp[i][j - 1][0])
				dp[i][j][1] = i - 1, dp[i][j][2] = j, dp[i][j][0] = dp[i - 1][j][0] + a[i][j];
			else dp[i][j][1] = i, dp[i][j][2] = j - 1, dp[i][j][0] = dp[i][j - 1][0] + a[i][j];
		}
	}
	ans += dp[n][n][0];
	resource();
	memset (dp, 0, sizeof (dp));
	for (int i = n; i >= 1; i--) {
		for (int j = n; j >= 1; j--) {
			if (dp[i + 1][j][0] > dp[i][j + 1][0])
				dp[i][j][1] = i + 1, dp[i][j][2] = j, dp[i][j][0] = dp[i + 1][j][0] + a[i][j];
			else dp[i][j][1] = i, dp[i][j][2] = j + 1, dp[i][j][0] = dp[i][j + 1][0] + a[i][j];
		}
	}
	cout << ans + dp[1][1][0];
}
