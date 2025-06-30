#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct node {
    int to, nxt;
} a[N], b[N];

int pre[N], k, dfn[N], low[N], n, m, x, y, dp[N], inst[N], id[N], si[N], v[N], vD[N];
stack<int> st;
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
        int t;
        sccnt++;
        do {
            t = st.top();
            st.pop();
            inst[t] = 0;
            id[t] = sccnt;
            si[sccnt]++;
            vD[sccnt] += v[t];
        } while (t != x);
    }
}
void add(int u, int v) {
    a[++k] = {v, pre[u]};
    pre[u] = k;
}
int preD[N], kb;
void addD(int u, int v) {
    b[++kb] = {v, preD[u]};
    preD[u] = kb;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        add(x, y);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i])
            tarjan(i);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = pre[i]; j; j = a[j].nxt) {
            int x = id[i], y = id[a[j].to];
            if (x != y) {
                addD(x, y);
            }
        }
    }
    for (int i = 1; i <= sccnt; i++) {
        dp[i] = vD[i];
    }
    int ans = 0;
    for (int i = sccnt; i >= 1; i--) {
        for (int j = preD[i]; j; j = b[j].nxt) {
            dp[b[j].to] = max(dp[b[j].to], dp[i] + vD[b[j].to]);
        }
    }
    for (int i = sccnt; i >= 1; i--) {
        ans = max(ans, dp[i]);
    }
    cout << ans;
}