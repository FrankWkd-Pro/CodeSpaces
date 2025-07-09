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
 * @Solution  额。。。没什么好方法，暴力吧。。。
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
        f[i] = 1;
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[j] % a[i] == 0)
                f[j] = 0;
            if (a[i] == a[j]) {
                f[i] = 0, f[j] = 0;
            }
        }
    }
    // for (int i = 1; i <= n; i++) cout << f[i] << " ";
    for (int i = 1; i <= n; i++)
        if (f[i] == 1)
            ans++;
    cout << ans << endl;
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}