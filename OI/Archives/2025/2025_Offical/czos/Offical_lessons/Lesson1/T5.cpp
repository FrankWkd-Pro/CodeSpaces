#include <bits/stdc++.h>
using namespace std;

int a[100010];
int n;
int k, ans[100010];
int all[100010];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        all[++k] = a[i];
    }
    sort(all + 1, all + k + 1);
    k = unique(all + 1, all + k + 1) - all - 1;
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(all + 1, all + 1 + k, a[i]) - all;
        ans[a[i]]++;
        if (ans[a[i]] > 1) {
            cout << 1;
            return 0;
        }
    }
    cout << 0;
}