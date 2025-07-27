#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10, M = 5e4 + 10;
struct node {
    int to, nxt;
} a[M];
int pre[N], in[N], c[N], dp[N], k;
int n, m;
void add(int u, int v) {
    a[++k] = {v, pre[u]};
    pre[u] = k;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        add(x, y);
        in[y]++;
    }
    queue<int> q;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            q.push(i);
            cnt++;
            dp[i] = c[i];
        }
    }
    while (!q.empty()) {
        int h = q.front();
        q.pop();
        for (int i = pre[h]; i; i = a[i].nxt) {
            // 使用当前节点松弛其他节点
            int to = a[i].to;
            dp[to] = max(dp[to], dp[h] + c[to]);
            in[to]--;
            if (in[to] == 0)
                q.push(to);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}