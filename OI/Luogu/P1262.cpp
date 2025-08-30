/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-06-29
 * @Network   "https://www.luogu.com.cn/problem/P1262"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  P1262.cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/Luogu/P1262.cpp
 * @Solution  要贿赂就要贿赂所有的叶子节点，如果该点不能被贿赂，即无解。如果该点是环，则取环内最小值，否则取该点的点权。
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10, M = 1e4 + 10;
struct node {
    int to, nxt;
} a[M], b[M];
int pre[N], k, pd[N], kd;
int dfn[N], low[N], si[N], id[N], inn[N];
int n, m, x, y;
void add(int u, int v) {
    a[++k] = {v, pre[u]};
    pre[u] = k;
}
void addDAG(int u, int v) {
    b[++kd] = {v, pd[u]};
    pd[++kd] = {v, pd[u]};
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);

    return 0;
}