/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author     FrankWKD
 * @Date       2025-08-02
 * @Network    "https://oj.czos.cn/contest/problem?id=25410&pid=4"
 * @License    GNU General Public License 2.0
 * @Platform   [Frank]iMac Ubuntu Pro 24.04 LTS
 * @Name       T5.cpp
 * @Path       /media/frank/FrankW/_default/Mine/Working/code-spaces/OI/OJ/czos/CSP-S_Practise/Lesson1/T5.cpp
 * @Sol        --
 */

// #pragma GCC optimize(3)
#define _for(cc, ba, ab) for (int cc = (ba); cc <= (ab); cc++)
#define for_(cc, ba, ab) for (int cc = (ba); cc >= (ab); cc--)
#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N = 1e5 + 10;
int pre[N], n, c, son[N][30], f[N][30], k, val[N];
struct node {
    int to, nxt;
} a[N * 2];
void add(int u, int v) {
    a[++k] = {v, pre[u]};
    pre[u] = k;
}
void dfs_son(int x, int fa) {
    for (int i = pre[x]; i; i = a[i].nxt) {
        if (a[i].to != fa) {
            dfs_son(a[i].to, x);
            _for(j, 1, c) {
                son[x][j] += son[a[i].to][j - 1];
            }
        }
    }
}
void dfs_f(int x, int fa) {
    for (int i = pre[x]; i; i = a[i].nxt) {
        if (a[i].to != fa) {
            f[a[i].to][1] += son[x][0];
            _for(j, 2, c) {
                f[a[i].to][j] += f[x][j - 1] - son[a[i].to][j - 2];
            }
            dfs_f(a[i].to, x);
        }
    }
}
int main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> n >> c;
    _for(i, 1, n - 1) {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    _for(i, 1, n) {
        int x;
        cin >> x;
        _for(j, 0, c) son[i][j] = x;
    }
    dfs_son(1, 0);
    memcpy(f, son, sizeof son);
    dfs_f(1, 0);
    _for(i, 1, n) cout << f[i][c] << "\n";
    return 0;
}