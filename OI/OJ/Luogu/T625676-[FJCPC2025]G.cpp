/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-07-06
 * @Network   "https://www.luogu.com.cn/problem/T625676?contestId=254970"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  T625676-[FJCPC2025]G.cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/Luogu/T625676-[FJCPC2025]G.cpp
 * @Solution  贪心暴力拿部分分
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int a[N], k, n, m, l[N], r[N];
int f[N], val[N];
int main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] > a[i - 1])
            f[i] = a[i] - a[i - 1];
    }
    for (int i = 2; i <= n; i++) {
        val[i] = f[i] + val[i - 1];
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << val[i] << endl;
    // }
    cin >> k;
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        cout << k + (val[r] - val[l]) << "\n";
    }

    // fclose(stdin);
    // fclose(stdout);
    return 0;
}