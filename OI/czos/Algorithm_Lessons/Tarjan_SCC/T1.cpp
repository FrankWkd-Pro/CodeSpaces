/*
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-06-15
 * @Source    "https://oj.czos.cn/contest/problem?id=24790&pid=0"
 * @License   GNU General Public License 2.0
 * @FileName  T1.cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/czos/Tarjan_SCC/T1.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10, M = 5e4 + 10;
struct node {
    int to, nxt;
} a[M];
int pre[N], k;
int dfn[N], low[N], times = 0;
stack<int> st;
bool ins[N];
int cnt, id[N], si[N];
int n, m;
void add(int u, int v) {
    a[++k] = {v, pre[u]};
    pre[u] = k;
}
void tarjan(int x) {
    dfn[x] = low[x] = times + 1;
    times++;
    st.push(x);
    ins[x] = 1;
    for (int i = pre[x]; i; i = a[i].nxt) {
        int to = a[i].to;
        if (!dfn[to]) {
            tarjan(to);
            low[x] = min(low[x], low[to]);

        } else if ()
            low[x] = min(low[x], low[to]);
    }
    // 从to后退时，判断x是否是SCC的入口点
    if (low[x] == dfn[x]) {
        cnt++;
        int t;
        do {
            t = st.top();
            st.pop();
            ins[t] = 0;
            si[cnt]++;
            id[t] = cnt;

        } while (t != x);
    }
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        add(x, y);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    int ans = 0;
    for (int i = 1; i <= cnt; i++) {
        if (si[i] > 1) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}