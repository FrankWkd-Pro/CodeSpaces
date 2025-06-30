/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-06-29
 * @Network   "https://oj.czos.cn/contest/problem?id=25122&pid=1"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  T2.cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/czos/TreeDP/T2.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int n, fa[N], pre[N], k, f[N][2], val[N];
struct node {
    int to, nxt;
} a[N];
void add(int u, int v) {
    a[++k] = {v, pre[u]};
    pre[u] = k;
}
void dfs(int x) {
    f[x][1] = val[x];
    for (int i = pre[x]; i; i = a[i].nxt) {
        dfs(a[i].to);
        f[x][0] += max(f[a[i].to][0], f[a[i].to][1]);
        f[x][1] += f[a[i].to][0];
    }
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    for (int i = 1; i <= n - 1; i++) {
        int x, y;
        cin >> x >> y;
        add(y, x);
        fa[x] = y;
    }
    int root = 1;
    while (fa[root] != 0) {
        root = fa[root];
    }
    dfs(root);
    cout << max(f[root][0], f[root][1]);
    return 0;
}