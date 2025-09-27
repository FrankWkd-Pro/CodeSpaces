/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-09-16
 * @Network   "null"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  Tarjan.Templete.cpp
 * @FilePath  /workspaces/CodeSpaces/OI/OJ/Accoders/Tarjan/Tarjan.Templete.cpp
 * @Solution  A templete for tarjan scck
 */

// #pragma GCC optimize(3)
#define _for(aa, bb, cc) for (int aa = bb; aa <= cc; aa++)
#define for_(aa, bb, cc) for (int aa = bb; aa >= cc; aa--)
#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N = 1e5 + 10, M = 5e5 + 10;
int dfn[N], low[N], pre[x], siz[N], id[N], times, sccnt, k, n, m;
bool inst[N];
stack<int> st;
struct node {
    int to, nxt;
} a[M];
void tarjan(int x) {
    dfn[x] = low[x] = ++times;
    inst[x] = 1;
    st.push(x);
    for (int i = pre[x]; i; i = a[i].nxt) {
        int to = a[i].nxt;
        if (!dfn[to]) {
            tarjan(to);
            low[x] = min(low[x], low[to]);
        } else if (inst[to]) {
            low[x] = min(low[x], dfn[x]);
        }
    }
    if (dfn[x] == low[x]) {
        int tp;
        do {
            tp = st.top();
            st.pop();
            inst[tp] = 0;
        }
    }
}
int main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);

    // fclose(stdin);
    // fclose(stdout);
    return 0;
}