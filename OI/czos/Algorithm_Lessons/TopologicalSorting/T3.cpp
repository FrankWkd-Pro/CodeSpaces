/*
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-06-09
 * @Source    https://oj.czos.cn/contest/problem?id=24562&pid=2
 * @FileName  T3.cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/czos/TopologicalSorting/T3.cpp
 * @Note      本质上就是树上DP，优化了一下这个DP的顺序。
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 2e5 + 10;
int in[N], out[N], x, y, n, m, pre[N], clonein[N], k;
int dp[N];
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
        cin >> x >> y;
        add(x, y);
        in[y]++;
        clonein[y]++;
        out[x]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            q.push(i);
            dp[i] = 1;
        }
    }
    while (!q.empty()) {
        int h = q.front();
        q.pop();
        for (int i = pre[h]; i; i = a[i].nxt) {
            int to = a[i].to;
            dp[to] += dp[h];
            in[to]--;
            if (in[to] == 0) {
                q.push(to);
            }
        }
    }
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        if (clonein[i] != 0 and out[i] == 0) {
            tot += dp[i];
        }
    }
    cout << tot << endl;
    return 0;
}