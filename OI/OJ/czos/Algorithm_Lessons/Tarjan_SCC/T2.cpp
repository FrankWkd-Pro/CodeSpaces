/*
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-06-21
 * @Source    "https://oj.czos.cn/contest/problem?id=24790&pid=1"
 * @License   GNU General Public License 2.0
 * @FileName  T2.cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/czos/Tarjan_SCC/T2.cpp
 * @Solution  1.先找出所有SCC，将每个SCC缩成一个点。2.如果有大于1个入度为零的SCC，就输出0,否则输出唯一的入度为零的SCC包含的点的数量
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10, M = 5e4 + 10;
struct node {
    int to, nxt;
} a[M];
int pre[N], k, n, m;
int dfn[N], low[N];
int si[N], id[N];
bool inst[N];
stack<int> st;
void add(int u, int v) {
    a[++k] = {v, pre[u]};
    pre[u] = k;
}
int times, sccnt;
void tarjan(int x) {
    dfn[x] = low[x] = ++times;
    st.push(x);
    inst[x] = 1;
    for (int i = pre[x]; i; i = a[i].nxt) {
        int to = a[i].to;
        if (!dfn[to]) {
            tarjan(to);
            low[x] = min(low[x], low[to]);
        } else if (inst[to] == 1) {
            low[x] = min(low[x], dfn[to]);
        }
    }
    // 从to后退时，判断x是否是SCC的入口点
    if (dfn[x] == low[x]) {
        sccnt++;
        int t;  // 开始pop
        do {
            t = st.top();
            st.pop();
            inst[t] = 0;
            id[t] = sccnt;
            si[sccnt]++;
        } while (t != x);
    }
}
int inn[N];  // 每个SCC的入度
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
    for (int i = 1; i <= n; i++) {
        for (int j = pre[i]; j; j = a[j].nxt) {
            int x = i;
            int y = a[j].to;
            if (id[x] != id[y])
                inn[id[x]]++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= sccnt; i++) {
        if (inn[i] == 0) {
            if (ans != 0) {
                cout << 0;
                return 0;
            }
            ans = i;
        }
    }
    cout << si[ans];
    return 0;
}