#include <bits/stdc++.h>
using namespace std;

int a[200010];
int b[200010];
int ans[400010];
int all[400010];

int main() {
    int n;
    cin >> n;
    int k = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        all[++k] = a[i];
        all[++k] = b[i];
    }
    sort(all + 1, all + 1 + k);
    k = unique(all + 1, all + k + 1) - all - 1;
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(all + 1, all + 1 + k, a[i]) - all;
        b[i] = lower_bound(all + 1, all + 1 + k, b[i]) - all;
        ans[a[i]]++, ans[b[i] + 1]--;
    }
    int maxx = 0;
    for (int i = 1; i <= k; i++) {
        ans[i] += ans[i - 1];
        maxx = max(maxx, ans[i]);
    }
    cout << maxx << endl;
}