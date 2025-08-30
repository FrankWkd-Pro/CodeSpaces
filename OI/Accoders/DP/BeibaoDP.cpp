/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-07-28
 * @Network   "http://www.accoders.com/problem.php?cid=5111&pid=1"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  beibapDP.cpp
 * @FilePath  /media/frank/FrankW/_default/Mine/Working/code-spaces/OI/OJ/Accoders/DP/beibaoDP.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, v[1010100], w[1010100], dp[1010000];
signed main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = w[i]; j <= m; j++) dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    }
    cout << "max=" << dp[m];
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}