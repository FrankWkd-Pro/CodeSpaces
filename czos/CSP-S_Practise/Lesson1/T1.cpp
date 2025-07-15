/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-07-09
 * @Network   "https://oj.czos.cn/contest/problem?id=25410&pid=0"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  T1.cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/czos/CSP-S_Practise/Lesson1/T1.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
int a[1010100];
int n;
bool f[1010100];
int ans;
int main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    if (a[1] == 1) {
        if (a[2] != 1)
            cout << 1;
        else
            cout << 0;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if (!f[a[i]] and a[i] != a[i + 1])  // 如果相邻的相等还不行呢
            ans++;
        for (int j = a[i]; j <= a[n]; j += a[i]) {
            f[j] = 1;
        }
    }
    cout << ans << endl;
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}