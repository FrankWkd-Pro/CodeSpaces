#include <bits/stdc++.h>
using namespace std;
int n, a[1010101], l, m;
int b[1010101];
int main() {
    cin >> n >> l >> m;
    for (int i = 1; i <= l; i++) {
        cin >> a[i];
    }
    a[++l] = n;
    // cout << "l: " << l << endl;
    int ans = 1;
    for (int i = 1; i <= l; i++) {
        b[i] = a[i] - a[i - 1];
        // cout << b[i] << " ";
    }
    int added = 0;
    // cout << endl;
    for (int i = 1; i <= l; i++) {
        if (added + b[i] > m) {
            ans++, added = b[i];
        } else {
            added += b[i];
        }
    }
    cout << ans << endl;
    return 0;
}