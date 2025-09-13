/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-09-09
 * @Network   "https://www.luogu.com.cn/problem/P4878"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  T2.cpp
 * @FilePath  /workspaces/CodeSpaces/OI/OJ/Accoders/diff-constraints/T2.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
int n, m1, m2;
const int N = 1e5 + 10;
int main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> n >> m1 >> m2;
    for (int i = 1; i < n; i++) add(i + 1, i, 0);
    while (m1--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (b < a)
            swap(a, b);
        add(a, b, c);
    }
    while (m2--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (b < a)
            swap(a, b);
        add(b, a, -c);
    }
    if (!spfa(n))
        cout << -1;
    else {
        spfa(1);
        if (dis[n] == INF)
            cout << -2;
    }
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}  // TODO: 差分约束系统题目2，未完成。