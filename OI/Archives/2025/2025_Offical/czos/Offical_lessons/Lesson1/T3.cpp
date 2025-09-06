#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
int ans[1010100];
int n, m, k;
int p[100010], x[100010];
int l[100010], r[100010];
int all[600010];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> p[i] >> x[i];
        all[++k] = p[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> l[i] >> r[i];
        all[++k] = l[i];
        all[++k] = r[i];
    }
    sort(all + 1, all + 1 + k);
    k = unique(all + 1, all + 1 + k) - all - 1;
    for (int i = 1; i <= n; i++) {
        p[i] = lower_bound(all + 1, all + 1 + k, p[i]) - all;
        ans[p[i]] += x[i];
    }
    for (int i = 1; i <= m; i++) {
        l[i] = lower_bound(all + 1, all + k + 1, l[i]) - all;
        r[i] = lower_bound(all + 1, all + k + 1, r[i]) - all;
    }
    for (int i = 1; i <= k; i++) {
        ans[i] += ans[i - 1];
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[r[i]] - ans[l[i] - 1] << endl;
    }
}
