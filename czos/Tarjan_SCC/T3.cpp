/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-06-27
 * @Network   "https://oj.czos.cn/contest/problem?id=24790&pid=2"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  T3.cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/czos/Tarjan_SCC/T3.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int N = 110, M = 1e4 + 10;
struct node {
    int to, nxt;
} a[M];
int id[N], si[N];
int pre[N], k, n, m;
int dfn[N], low[N], sccnt, times;
int x, y;

void add(int u, int v) {
    a[++k] = {v, pre[u]};
    pre[u] = k;
}
bool inst[N];
stack<int> st;
void tarjan(int x) {
    dfn[x] = low[x] = ++times;
    st.push(x);
    inst[x] = 1;
    for (int i = pre[x]; i; i = a[i].nxt) {
        int to = a[i].to;
        if (!dfn[to]) {
            tarjan(to);
            low[x] = min(low[x], low[to]);
        } else if (inst[to]) {
            low[x] = min(low[x], dfn[to]);
        }
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
        } while (t != x);
    }
}
int inn[N], outt[N];
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t = 1;
        while (1) {
            cin >> t;
            if (t == 0)
                break;
            else
                add(i, t);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i])
            tarjan(i);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = pre[i]; j; j = a[j].nxt) {
            int x = id[i];
            int y = id[a[j].to];
            if (x != y) {
                inn[y]++, outt[x]++;
            }
        }
    }
    int in = 0, out = 0;
    for (int i = 1; i <= sccnt /*这里必须是sccnt！统计的是缩点之后的图！*/; i++) {
        if (inn[i] == 0) {
            in++;
        }
        if (outt[i] == 0) {
            out++;
        }
    }
    cout << in << endl;
    if (sccnt == 1)
        cout << 0;
    else
        cout << max(in, out);
    return 0;
}