/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-06-28
 * @Network   "https://www.luogu.com.cn/problem/P3627"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  P3627-Tarjan.cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/Luogu/P3627-Tarjan.cpp
 * @Solution  同P3387,几乎是一个题，唯一要注意的就是这一题计算的是以s为起点的最长路，但是我们也可以用拓扑排序+dp的方法，因为缩点后的DAG是保证不存在环的，直接大胆dp就行。
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
struct node {
    int to, nxt;
} a[N], DAG[N];
int pre[N], pred[N], k, kd;
int n, m, s, p;
int x, y;
int dfn[N], low[N], si[N], id[N], times, sccnt;
int val[N], vald[N], dp[N];
bool pubd[N];
bool pub[N], inst[N];
stack<int> st;
inline void add(int u, int v) {
    a[++k] = {v, pre[u]};
    pre[u] = k;
}
inline void addDAG(int u, int v) {
    DAG[++kd] = {v, pred[u]};
    pred[u] = kd;
}
inline void tarjan(int x) {
    dfn[x] = low[x] = ++times;
    inst[x] = 1;
    st.push(x);
    for (int i = pre[x]; i; i = a[i].nxt) {
        int to = a[i].to;
        if (!dfn[to]) {
            tarjan(to);
            low[x] = min(low[to], low[x]);
        } else if (inst[to])
            low[x] = min(low[x], dfn[to]);
    }
    if (dfn[x] == low[x]) {
        int t;
        sccnt++;
        do {
            t = st.top();
            st.pop();
            si[sccnt]++;
            id[t] = sccnt;
            inst[t] = 0;
            vald[sccnt] += val[t];
            if (pub[t])
                pubd[sccnt] = 1;
        } while (t != x);
    }
}
int main() {
    // freopen("P3627-HackData.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    cout << n << m << endl;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        add(x, y);
    }
    for (int i = 1; i <= n; i++) cin >> val[i];
    cin >> s >> p;
    for (int i = 1; i <= p; i++) {
        cin >> x;
        pub[x] = 1;
    }

    tarjan(s);
    for (int i = 1; i <= n; i++) {
        for (int j = pre[i]; j; j = a[j].nxt) {
            int x = id[i];
            int y = id[a[j].to];
            if (x != y)
                addDAG(x, y);
        }
    }
    queue<int> q;
    q.push(id[s]);
    memset(dp, -0x3f, sizeof(dp));
    dp[id[s]] = vald[id[s]];
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int i = pred[t]; i; i = DAG[i].nxt) {
            dp[DAG[i].to] = max(dp[DAG[i].to], dp[t] + vald[DAG[i].to]);
            q.push(DAG[i].to);
        }
    }
    int ans = 0;
    for (int i = 1; i <= sccnt; i++) {
        if (pubd[i] == 1)
            ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}