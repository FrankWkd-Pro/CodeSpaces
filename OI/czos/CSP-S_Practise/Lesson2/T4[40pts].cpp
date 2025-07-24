/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-07-17
 * @Network   "https://oj.czos.cn/contest/problem?id=25573&pid=3"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  T4[40pts].cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/czos/CSP-S_Practise/Lesson2/T4[40pts].cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
struct node {
    int from, to, nxt;
} a[N];
int pre[N], k;
int din[N];
int n, m, q, t, x, y;
typedef pair<int, int> pii;
map<pii, int> f;
void add(int u, int v) {
    a[++k] = {u, v, pre[u]};
    pre[u] = k;
}
int main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        add(y, x);
        din[x]++;
        f[{y, x}] = 1;
    }
    cin >> q;
    while (q--) {
        cin >> t >> x;
        if (t == 1 or t == 3)
            cin >> y;
        if (t == 1) {
            din[x]--;
            f[{y, x}] = 2;
        } else if (t == 2) {
            for (int i = pre[x]; i; i = a[i].nxt) {
                int to = a[i].to;
                if (f[{x, to}] == 1) {
                    din[to]--;
                    f[{x, to}] = 2;
                }
            }
        } else if (t == 3) {
            f[{y, x}] == 1;
            din[x]++;
        } else if (t == 4) {
            for (int i = pre[x]; i; i = a[i].nxt) {
                int to = a[i].to;
                if (f[{x, to}] == 2) {
                    din[to]++;
                    f[{x, to}] = 1;
                }
            }
        }
        bool fl = 1;
        for (int i = 1; i <= n; i++) {
            if (din[i] != 1) {
                fl = 0;
                break;
            }
        }
        if (fl)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    // fclose(stdin);
    // fclose(stdout);
    return 0;
}