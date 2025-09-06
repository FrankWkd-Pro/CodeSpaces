#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
int maxx, a[101010];
int n, ans, dep;
int s[101010];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int k = 1;
    for (int i = 1; i <= n; i++) {
        s[i] = k + s[i - 1];
        k *= 2;
    }
    s[0] = 0;
    for (int i = 1; s[i - 1] <= n; i++) {
        // cout << s[i - 1] + 1 << " " << s[i] << endl;
        int cnt = 0;
        for (int j = s[i - 1] + 1; j <= s[i] and j <= n; j++) {
            cnt += a[j];
        }
        if (maxx < cnt)
            maxx = cnt, ans = i;
    }
    cout << ans << endl;
    return 0;
}