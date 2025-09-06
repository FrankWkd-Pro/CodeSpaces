#include <bits/stdc++.h>
using namespace std;

int l[20010], r[20010];
int n, x, y, z;
int all[100100];
int k;
int ans[100100];
int main() {
    cin >> n >> x >> y >> z;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
        all[++k] = l[i], all[++k] = r[i];
    }
    sort(all + 1, all + 1 + k);
    k = unique(all + 1, all + 1 + k) - all - 1;
    for (int i = 1; i <= n; i++) {
        l[i] = lower_bound(all + 1, all + 1 + k, l[i]) - all;
        r[i] = lower_bound(all + 1, all + 1 + k, r[i]) - all;
        ans[1] += x, ans[l[i]] -= x;
        ans[l[i]] += y, ans[r[i] + 1] -= y;
        ans[r[i] + 1] += z;
    }
    int maxx = 0;
    for (int i = 1; i <= k; i++) {
        ans[i] += ans[i - 1];
        maxx = max(maxx, ans[i]);
    }
    cout << maxx << endl;
}