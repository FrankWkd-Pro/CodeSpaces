/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-07-25
 * @Network   ""
 * @License   GNU General Public License 2.0
 * @Platform  Win 7
 * @FileName  T4.cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/OI/Accoders/Contest-2025-07-25/T4.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int pre[N], k, n, m, x, y;
struct node {
    int x, y;
} a[N];

void add(int u, int v) {
    a[++k] = {v, pre[u]};
    pre[u] = k;
}
int dijkstra(int u, int v) {
    vector<int> dis(n + 1, INT_MAX);
    dis[u] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, u});
    while (!pq.empty()) {
        pair<int, int> d = pq.top();
        pq.pop();
        if (d.first > dis[d.second])
            continue;
        for (int i = pre[d.second]; i; i = a[i].y) {
            int y = a[i].x;
            if (dis[y] > d.first + 1) {
                dis[y] = d.first + 1;
                pq.push({dis[y], y});
            }
        }
    }
    return dis[v];
}
int bfs(int a, int b, int c, int d) {
    int tot = dijkstra(a, b) + dijkstra(b, c) + dijkstra(c, d);
    cout << a << " " << b << " " << c << " " << d << " : " << tot << endl;
    return tot;
}
int main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                continue;
            for (int k = 1; k <= n; k++) {
                if (i == k or j == k)
                    continue;
                for (int l = 1; l <= n; l++) {
                    if (i == l or j == l or k == l)
                        continue;
                    ans = max(bfs(i, j, k, l), ans);
                }
            }
        }
    }
    cout << ans << endl;
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}