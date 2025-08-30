/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-07-16
 * @Network   "https://oj.czos.cn/contest/problem?id=25573&pid=2"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  T3.cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/czos/CSP-S_Practise/Lesson2/T3.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int a[N], b[N], f[N][2], n, t, last[1000010];  // warning: last
signed main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        memset(last, 0, sizeof last);
        memset(b, 0, sizeof b);
        memset(f, 0, sizeof f);
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            if (a[i] == a[i - 1])
                b[i] = a[i] + b[i - 1];
            else
                b[i] = b[i - 1];
        }
        for (int i = 1; i <= n; i++) {
            f[i][0] = max(f[i - 1][1], f[i - 1][0]);
            if (last[a[i]] > 0) {
                f[i][1] = a[i] + max(f[last[a[i]] + 1][0], f[last[a[i]] + 1][1]) + ((last[a[i]] + 1 < i - 1) ? (b[i - 1] - b[last[a[i]] + 1]) : 0);
            }
            last[a[i]] = i;
        }
        cout << max(f[n][0], f[n][1]) << endl;
    }
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}