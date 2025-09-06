#include <bits/stdc++.h>
using namespace std;
long long a[10101010];
long long n, w;
int main() {
    cin >> w >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int ans = 0, i = 1;
    for (int i = 1; i <= n; i++) {
        if (w >= a[i]) {
            w -= a[i];
            ans++;
        }
    }
    cout << ans << endl;
}