/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-10-02
 * @Network   "http://www.accoders.com/problem.php?cid=5135&pid=2"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  T3.cpp
 * @FilePath  /workspaces/CodeSpaces/OI/OJ/Accoders/Contest-2025-10-02/T3.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#define _for(aa, bb, cc) for (auto aa = bb; aa <= cc; aa++)
#define for_(aa, bb, cc) for (auto aa = bb; aa >= cc; aa--)
#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N = 1010;
struct node {
    int to, nxt, len;
} a[N];
struct ans {
    int d1, d2, len;
};
vector<ans> v;
int pre[N], k, din[N], dout[N], n, p, inque[N];
void add(int u, int v, int l) {
    a[++k] = {v, pre[u], l};
    pre[u] = k;
}
void bfs(int x) {
    memset(inque, 0, sizeof inque);
    queue<pair<int, int>> q;
    inque[x] = 1;
    q.push({x, INT_MAX});
    while (!q.empty()) {
        pair<int, int> t = q.front();
        q.pop();
        for (int i = pre[t.first]; i; i = a[i].nxt) {
            int to = a[i].to;
            if (dout[to] == 0) {
                v.push_back({x, to, min(t.second, a[i].len)});
            } else {
                if (!inque[to]) {
                    inque[to] = 1;
                    q.push({to, min(t.second, a[i].len)});
                }
            }
        }
    }
}
int main() {
    freopen("water.in", "r", stdin);
    freopen("water.out", "w", stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> n >> p;
    _for(i, 1, p) {
        int x, y, l;
        cin >> x >> y >> l;
        add(x, y, l);
        din[y]++;
        dout[x]++;
    }
    _for(i, 1, n) {
        if (din[i] == 0) {
            bfs(i);
        }
    }
    cout << v.size() << "\n";
    for (auto it : v) {
        cout << it.d1 << " " << it.d2 << " " << it.len << "\n";
    }
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}