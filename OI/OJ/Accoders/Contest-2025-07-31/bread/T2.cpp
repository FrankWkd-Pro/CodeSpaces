#pragma GCC optimize(3)

#define _for(cc, ba, ab) for (int cc = (ba); cc <= (ab); cc++)
#define for_(cc, ba, ab) for (int cc = (ba); cc >= (ab); cc--)
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, tmax, a[101010], l, r;
priority_queue<int, vector<int>, greater<int>> q;
bool check(int m) {
    while (!q.empty()) q.pop();
    _for(i, 1, n) {
        if (q.size() < m)
            q.push(a[i]);
        else {
            int tmp = q.top();
            q.pop();
            q.push(tmp + a[i]);
        }
    }
    int maxx = 0;
    while (!q.empty()) {
        maxx = max(maxx, q.top());
        q.pop();
    }
    return maxx <= tmax;
}
signed main() {
    freopen("bread.in", "r", stdin);
    freopen("bread.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> tmax;
    _for(i, 1, n) cin >> a[i];
    l = 1, r = n;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << l;
    return 0;
}
