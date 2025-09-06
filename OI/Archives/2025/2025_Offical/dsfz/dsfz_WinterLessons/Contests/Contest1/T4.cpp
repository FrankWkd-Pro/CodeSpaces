#include <bits/stdc++.h>
using namespace std;
long long a[1000010], n;
int main() {
    cin >> n;
    for (long long i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long ans = 0;
    //	0+H(n+1) = 2*E(n)
    for (long long i = n; i >= 1; i--) {
        ans = (ans + a[i]) / 2;
    }
    cout << ans + 1 << endl;
}