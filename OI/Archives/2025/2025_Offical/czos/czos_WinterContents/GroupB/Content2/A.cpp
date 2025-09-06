#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l;
    long long ans = 0;
    cin >> n >> l;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        ans = ans < min(k, l - k) ? min(k, l - k) : ans;
    }
    cout << ans << endl;
    return 0;
}