/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-07-28
 * @Network   "https://www.luogu.com.cn/problem/P1880"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  StoneMergeDP.cpp - P1880 [NOI1995] 石子合并
 * @FilePath  /media/frank/FrankW/_default/Mine/Working/code-spaces/OI/OJ/Accoders/DP/StoneMergeDP.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define _for(cc, ba, ab) for (int cc = (ba); cc <= (ab); cc++)
#define for_(cc, ba, ab) for (int cc = (ba); cc >= (ab); cc--)
int dp[210][210], n, a[110], sum[210], dpm[210][210], ans1 = INT_MAX, ans2;
int main() {
    cin >> n;
    _for(i, 1, n) cin >> a[i];
    _for(i, 1, n) a[i + n] = a[i];
    _for(i, 1, 2 * n) sum[i] = sum[i - 1] + a[i];
    _for(i, 1, 2 * n) _for(j, 1, 2 * n) if (i != j) dp[i][j] = INT_MAX;
    _for(len, 2, n) _for(i, 1, n * 2 - len) {
        int j = i + len - 1;
        _for(k, i, j - 1) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]), dpm[i][j] = max(dpm[i][j], dpm[i][k] + dpm[k + 1][j] + sum[j] - sum[i - 1]);
    }
    _for(i, 1, n) ans1 = min(dp[i][i + n - 1], ans1), ans2 = max(dpm[i][i + n - 1], ans2);
    cout << ans1 << endl
         << ans2;
}