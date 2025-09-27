/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author     FrankWKD
 * @Date       2025-09-27
 * @Network    ""
 * @License    GNU General Public License 2.0
 * @Platform   [Frank]iMac Ubuntu Pro 24.04 LTS
 * @Name       T4.cpp
 * @Path       ~/桌面/Contest-2025-09-27/T4/T4.cpp
 * @Sol        --
 */

// #pragma GCC optimize(3)
#define _for(cc, ba, ab) for (int cc = (ba); cc <= (ab); cc++)
#define for_(cc, ba, ab) for (int cc = (ba); cc >= (ab); cc--)
#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N = 2e5 + 10;
struct node {
    int to, nxt;
} a[N], rev[N];
int val[N], pre[N], n, k, m, din[N], cost[N], pre_rev[N], k_rev;
queue<int> q;
vector<int> ls;
void add(int u, int v) {
    a[++k] = {v, pre[u]};
    pre[u] = k;
}
void add_reverse(int u, int v) {
    rev[++k_rev] = {v, pre_rev[u]};
    pre_rev[u] = k_rev;
}
int main() {
    freopen("chores.in", "r", stdin);
    freopen("chores.out", "w", stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);

    cin >> n;
    _for(i, 1, n) {
        cin >> val[i];
        int m;
        cin >> m;
        _for(j, 1, m) {
            int x;
            cin >> x;
            add(x, i);
            add_reverse(i, x);
            din[i]++;
        }
    }
    _for(i, 1, n) {
        if (din[i] == 0) {
            q.push(i);
            // cout << "--" << i << endl;
        }
    }
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        ls.push_back(t);
        for (int i = pre[t]; i; i = a[i].nxt) {
            din[a[i].to]--;
            if (din[a[i].to] == 0)
                q.push(a[i].to);
        }
    }
    _for(i, 0, n - 1) {
        cost[ls[i]] = val[ls[i]];
        for (int j = pre_rev[ls[i]]; j; j = rev[j].nxt) {
            cost[ls[i]] = max(cost[ls[i]], cost[rev[j].to] + val[ls[i]]);
        }
    }
    int maxx = 0;
    _for(i, 0, n - 1) {
        // cout << ls[i] << endl;
        maxx = max(maxx, cost[ls[i]]);
    }
    cout << maxx << endl;
    return 0;
}