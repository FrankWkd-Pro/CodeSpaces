
#include <bits/stdc++.h>
using namespace std;
int n, ans, mi = INT_MAX;
int a[10101010];
int main() {
        cin >> n;
    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        mi = min(mi, x);
        ans = max(ans, x - mi);
    }
    cout << ans << endl;
}