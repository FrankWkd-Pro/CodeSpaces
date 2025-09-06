/*
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-06-21
 * @Source    "--"
 * @License   GNU General Public License 2.0
 * @FileName  Template.cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/czos/Tarjan_SCC/Template.cpp
 * @Solution  Tarjan求SCC模板，同T1
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10, M = 5e4 + 10;
struct node {
    int to, nxt;
} a[M];

int pre[N], k = 0;
int dfn[N], low[N], times = 0;
stack<int> st;
bool inst[N];
int sccnt = 0;
int si[N];  // 每个SCC内部的节点数
int id[N];  // 每个点属于哪个SCC
int n, m, x, y;
void tarjan(int x) {  // 以x为起点进行SCC的查找(只负责这一层)
    dfn[x] = low[x] = ++times;
    st.push(x);
    inst[x] = true;
    for (int i = pre[x]; i; i = a[i].nxt) {
        int to = a[i].to;
        if (!dfn[to]) {
            tarjan(to);  // 逐层向下递归相邻节点
            low[x] = min(low[x], low[to]);

        } else if (inst[to])
            low[x] = min(low[x], low[to]);  // 找到了闭环！更新SCC！
    }
    if (low[x] == dfn[x]) {  // 从to后退时，判断x是否是SCC的入口点
        sccnt++;
        // 找到SCC入口，SCC数量++ 开始弹栈
        int t;
        do {
            t = st.top();
            st.pop();
            inst[t] = false;
            si[sccnt]++;
            id[t] = sccnt;
        } while (t != x);
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
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    int ans = 0;
    for (int i = 1; i <= sccnt; i++) {
        if (si[i] > 1)
            ans++;  // 因为题目要求大小大于1的SCC的数量，所以这里我们再次统计一下
    }
    cout << ans;
    return 0;
}