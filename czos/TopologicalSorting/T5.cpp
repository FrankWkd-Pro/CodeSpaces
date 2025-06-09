/*
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-06-09
 * @Source    https://oj.czos.cn/contest/problem?id=24562&pid=4
 * @License   GNU General Public License 2.0
 * @FileName  T5.cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/czos/TopologicalSorting/T5.cpp
 * @Solution  首先这肯定是一个图上DP。i节点的值为其最早到达时间，记为dp[i],初始值为a[i].那么拓扑排序使用c更新dp即可。
 */

#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, t, in[N], pre[N], k, dp[N], a[N];
struct node {
    int to, nxt, len;
} e[N];
void add(int u, int v, int ll) {
    e[++k] = {v, pre[u], ll};
    pre[u] = k;
}
int main() {
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        dp[i] = a[i];
    }
    for (int i = 1; i <= t; i++) {
        int x, y, l;
        scanf("%d%d%d", &x, &y, &l);
        add(x, y, l);
        in[y]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int h = q.front();
        q.pop();
        for (int i = pre[h]; i; i = e[i].nxt) {
            int to = e[i].to;
            in[to]--;
            dp[to] = max(dp[to], dp[h] + e[i].len);
            if (in[to] == 0) {
                q.push(to);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d\n", dp[i]);
    }
    return 0;
}