#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
// NOIP马走日
int a[1010][1010];
int dp[1010][1010];
int T, n, m;
int main() {
    cin >> T;
    while (T--) {
        memset(dp, 0, sizeof(dp));
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
            }
        }
        cout << dp[n][m] << endl;
    }

    return 0;
}