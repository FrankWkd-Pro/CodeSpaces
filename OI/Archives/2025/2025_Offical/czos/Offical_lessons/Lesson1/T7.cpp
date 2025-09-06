#include <bits/stdc++.h>
using namespace std;

int ans[1000100];
int n, a[1000100];
int all[1000100], k;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        all[++k] = a[i];
    }
    sort(all + 1, all + 1 + k);
    k = unique(all + 1, all + 1 + k) - all - 1;
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(all + 1, all + 1 + k, a[i]) - all;
    }
    int i = 1, j = 0;
    int maxx = 0;
    while (j <= n) {
        j++;
        ans[a[j]]++;
        while (ans[a[j]] > 1) {
            ans[a[i++]]--;
        }
        // for (int l = 1; l <= n; l++) {
        //     cout << l << " " << ans[l] << endl;
        // }
        // cout << 2 << " " << i << " " << j << endl;
        if (j - i + 1 > maxx and j <= n)
            maxx = j - i + 1;
    }
    cout << maxx << endl;
}