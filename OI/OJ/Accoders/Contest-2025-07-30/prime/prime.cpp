#pragma GCC optimize(3)

#define _for(cc, ba, ab) for (int cc = (ba); cc <= (ab); cc++)
#define for_(cc, ba, ab) for (int cc = (ba); cc >= (ab); cc--)
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
#define int long long
int p[N], n, k, lst, cnt;
priority_queue<int, vector<int>, greater<int> > q;
void solve() {
    int ans = q.top();
    q.pop();
    if (lst == ans)
        return;
    lst = ans, cnt++;
    if (cnt == k - 1) {
        cout << ans;
        exit(0);
    }
    _for(i, 1, n) if (1ll * ans * p[i] < 1e18)
        q.push(ans * p[i]);
}
signed main() {
    //    freopen("prime.in", "r", stdin);
    //    freopen("prime.out", "w", stdout);
    cin >> n;
    _for(i, 1, n) cin >> p[i], q.push(p[i]);
    cin >> k;
    while (!q.empty()) {
        solve();
    }
}
