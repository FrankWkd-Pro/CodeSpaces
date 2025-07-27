/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-06-28
 * @Network   "https://www.luogu.com.cn/problem/T589768?contestId=235738"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  T589768-Namid[A]me.cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/Luogu/T589768-Namid[A]me.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
int a[10101000];
int n;
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n + 1 >> 1; i++) a[i] = n * i - i * (i - 1);
    for (int i = (n + 1 >> 1) + 1; i <= n; i++) a[i] = a[n - i + 1];
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += a[i] * i;
        // cout << a[i] << endl;
    }
    cout << ans << endl;
    return 0;
}