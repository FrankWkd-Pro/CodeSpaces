/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-06-29
 * @Network   "https://oj.czos.cn/contest/problem?id=25122&pid=0"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  T1.cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/czos/TreeDP/T1.cpp
 * @Solution  f[i][0]代表第i个数不选，f[i][1]代表这个数选的最大收益
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 10;
int n, a[N];
int f[N][2];
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        f[i][0] = max(f[i - 1][0], f[i - 1][1]);  // 第i个数不要，可以来自第i-1个数要或者第i-1个数不要
        f[i][1] = f[i - 1][0] + a[i];             // 第i个数要，第i-1个数一定不能要
    }
    cout << max(f[n][0], f[n][1]);
    return 0;
}