/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-09-16
 * @Network   "http://www.accoders.com/problem.php?cid=5134&pid=0"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  T1.cpp
 * @FilePath  /workspaces/CodeSpaces/OI/OJ/Accoders/Tarjan/T1.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#define _for(aa, bb, cc) for (int aa = bb; aa <= cc; aa++)
#define for_(aa, bb, cc) for (int aa = bb; aa >= cc; aa--)
#include <bits/stdc++.h>
using namespace std;
const int N = 50010, MOD = 1e9 + 7;
const int P = 131;
struct node {
    int to, nxt;
} a[N];
int pre[N], dfn[N], low[N], in[N], k, n, m;
bool inst[N];
void add(int u, int v) {
    a[++k] = {v, pre[u]};
    pre[u] = k;
}
int id[N], siz[N], sccnt, times;
stack<int> st;
void tarjan(int x) {
    dfn[x] = low[x] = ++times;
    inst[x] = 1;
    st.push(x);
    for (int i = pre[x]; i; i = a[i].nxt) {
        int to = a[i].to;
        if (!dfn[to]) {
            tarjan(to);
            low[x] = min(low[x], low[to]);
        } else if (inst[to])
            low[x] = min(low[x], dfn[to]);
    }
    if (dfn[x] == low[x]) {
        ++sccnt;
        int tp;
        do {
            tp = st.top();
            inst[tp] = 0;
            st.pop();
            id[tp] = sccnt;
            siz[sccnt]++;
        } while (tp != x);
    }
}
int out[N];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        add(x, y);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i])
            tarjan(i);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = pre[i]; j; j = a[j].nxt) {
            int to = a[j].to;
            int x = id[i], y = id[to];
            if (id[i] != id[to])
                out[id[i]]++;
        }
    }
    int zeros = 0, sum = 0;
    for (int i = 1; i <= sccnt; i++) {
        if (!out[i]) {
            zeros++;
            sum += siz[i];
            if (zeros > 1) {
                sum = 0;
                break;
            }
        }
    }
    cout << sum;
    return 0;
}