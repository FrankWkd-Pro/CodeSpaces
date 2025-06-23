/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-06-23
 * @Network   "https://www.luogu.com.cn/problem/P3387"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  P3387-Tarjan.cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/Luogu/P3387-Tarjan.cpp
 * @Solution  [Sol-Luogu-P3387[模板]缩点] 先跑Tanjan缩点，然后利用DAG的性质求最长路（拓扑排序）
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10, M = 1e5 + 10;
struct node {
    int to, nxt;
} a[M];

int pre[N], k, inn[N], dfn[N], low[N], n, m, x, y, dp[N], inst[N], id[N], si[N];
stack<int> st;
queue<int> q;
int times, sccnt;
void tarjan(int x) {
    inst[x] = 1;
    dfn[x] = low[x] = ++times;
    st.push(x);
    for (int i = pre[x]; i; i = a[i].nxt) {
        if (!dfn[a[i].to]) {
            tarjan(a[i].to);
            low[x] = min(low[x], low[a[i].to]);
        } else if (inst[a[i].to]) {
            low[x] = min(low[x], dfn[a[i].to]);
        }
    }
    if (dfn[x] == low[x]) {
        // 检测到当前节点为SCC的Root
        int t;
        sccnt++;
        do {
            t = st.top();
            st.pop();
            inst[t] = 0;
            id[t] = sccnt;
            si[sccnt]++;
        } while (t != x);  // 栈内可能还有不属于当前SCC的节点
    }
}
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
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i])
            tarjan(i);
    }
    for (int i = 1; i <= n; i++) {
        if (inn[i] == 0) {
            dp[i] = 0;
            q.push(i);
        }
    }

    return 0;
}