/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-07-18
 * @Network   "https://oj.czos.cn/contest/problem?id=25573&pid=3&_pjax=%23p0"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  T4[100pts].cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/czos/CSP-S_Practise/Lesson2/T4[100pts].cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m, q, w[N], x, y, t;
long long din[N], t_din[N], tot, ans;
mt19937 rnd(time(0));
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) ans += (w[i] = rnd());
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        din[y] += w[x], t_din[y] = din[y], tot += w[x];
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> t >> x;
        if (t == 1) {
            cin >> y;
            din[y] -= w[x], tot -= w[x];
        } else if (t == 2)
            tot -= din[x], din[x] = 0;
        else if (t == 3) {
            cin >> y;
            din[y] += w[x], tot += w[x];
        } else if (t == 4)
            tot += t_din[x] - din[x], din[x] = t_din[x];
        if (tot == ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}