/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-07-19
 * @Network   "https://oj.czos.cn/contest/problem?id=25937&pid=0"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  T1.cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/czos/CSP-S_Practise/Lesson4/T1.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N], b[N];
int x, y, z[N], n, m, q;
int main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        memset(z, 0, sizeof z);
        cin >> n >> m >> q;
        for (int j = 1; j <= q; j++) {
            cin >> x >> y >> z[j];
            if (x == 1) {
                b[y] = j;
            } else
                a[y] = j;
        }
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                cout << z[max(a[j], b[k])];
            }
            cout << "\n";
        }
    }
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}