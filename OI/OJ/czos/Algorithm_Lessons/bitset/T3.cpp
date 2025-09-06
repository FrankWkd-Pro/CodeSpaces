// #pragma GCC optimize(3)
#define _for(cc, ba, ab) for (int cc = (ba); cc <= (ab); cc++)
#define for_(cc, ba, ab) for (int cc = (ba); cc >= (ab); cc--)
#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N = 4e4 + 10;
int n, c[N], ans;
bitset<N> f[N];
int main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> n;
    _for(i, 1, n) cin >> c[i];
    for_(i, n, 1) {
        f[i][c[i]] = 1;
        if (i + c[i] <= n)
            f[i] |= f[i + c[i]];
        if (i * 2 <= n)
            f[i] |= f[i * 2];
        ans = max(ans, (int)f[i].count());
    }
    cout << ans;
    return 0;
}