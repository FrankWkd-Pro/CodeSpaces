/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-07-26
 * @Network   "https://www.luogu.com.cn/problem/T624736?contestId=261525"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  T624736-[MX-X14-T2].cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/OI/Luogu/T624736-[MX-X14-T2].cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
int n, a[100010];
int dp[100010][2];  // 0是上升态最大长度，1反之
int main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    // 乱搞做大 DP
    dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] > a[i - 1]) {
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + 1);
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
        } else {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][0]) + 1;
            dp[i][1] = min(dp[i - 1][0] + 1, dp[i - 1][1]);
        }
        // cout << dp[i][0] << " " << dp[i][1] << endl;
    }
    cout << min(dp[n][0], dp[n][1]);
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}