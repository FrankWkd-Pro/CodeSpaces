#include <bits/stdc++.h>
using namespace std;
int n, a[1010101];
int ans;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i < n; i += 2) {
        ans += abs(a[i] - a[i + 1]);
    }
    cout << ans;
}