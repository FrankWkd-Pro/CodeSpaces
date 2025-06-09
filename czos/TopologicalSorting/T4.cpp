/*
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-06-09
 * @Source    https://oj.czos.cn/contest/problem?id=24562&pid=3
 * @License   GNU General Public License 2.0
 * @FileName  T4.cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/czos/TopologicalSorting/T4.cpp
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10, M = 2e4 + 10;
int pre[N], in[N], f[N], n, m, k;
struct node {
    int to, nxt;
} a[M];
void add(int u, int v) {
    a[++k] = {v, pre[u]};
    pre[u] = k;
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        add(x, y);
        in[y]++;
    }
    queue<int> q;
    int t = 0;  // 因为还要判环，所以还要加一个记录入队节点数的计数器
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            q.push(i);
            f[i] = 100;
            t++;
        }
    }
    while (!q.empty()) {
        int h = q.front();
        q.pop();
        for (int i = pre[h]; i; i = a[i].nxt) {
            int to = a[i].to;
            f[to] = max(f[to], f[i] + 1);
            in[to]--;
            if (in[to] == 0) {
                q.push(to);
                t++;
            }
        }
    }
    if (t != n) {
        cout << "impossible\n";
        return 0;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += f[i];
    }
    cout << ans << endl;
    return 0;
}