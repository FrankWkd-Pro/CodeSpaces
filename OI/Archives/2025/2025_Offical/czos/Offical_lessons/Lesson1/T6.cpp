#include <bits/stdc++.h>
using namespace std;

long long f[2000010], k = 1, a, b, c, ans[2000010];
long long all[2000010];
int main() {
    cin >> a >> b >> c;
    f[1] = 1, all[1] = 1;
    for (int i = 2; i <= 2000000; i++) {
        f[i] = (a * f[i - 1] + f[i - 1] % b) % c;
        all[++k] = f[i];
    }
    sort(all + 1, all + 2000001);
    k = unique(all + 1, all + 2000001) - all - 1;
    for (int i = 1; i <= 2000000; i++) {
        f[i] = lower_bound(all + 1, all + 1 + k, f[i]) - all;
        ans[f[i]]++;
        if (ans[f[i]] > 1) {
            cout << i - 1;
            return 0;
        }
    }
    cout << -1;
}