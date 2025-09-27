/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author     FrankWKD
 * @Date       2025-09-27
 * @Network    "http://www.accoders.com/problem.php?cid=5149&pid=2"
 * @License    GNU General Public License 2.0
 * @Platform   [Frank]iMac Ubuntu Pro 24.04 LTS
 * @Name       T3.cpp
 * @Path       ~/桌面/Contest-2025-09-27/T3/T3.cpp
 * @Sol        --
 */

// #pragma GCC optimize(3)
#define _for(cc, ba, ab) for (int cc = (ba); cc <= (ab); cc++)
#define for_(cc, ba, ab) for (int cc = (ba); cc >= (ab); cc--)
#include <bits/stdc++.h>
using namespace std;
// #define int long long

int a[1010], n, p[1010], s[1010], k, ans;

int main() {
    freopen("gifts.in", "r", stdin);
    freopen("gifts.out", "w", stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> n >> k;
    _for(i, 1, n) cin >> p[i] >> s[i];
    _for(i, 1, n) a[i] = p[i] + s[i];
    _for(i, 1, n) {
        a[i] = p[i] / 2 + s[i];
        sort(a + 1, a + 1 + n);
        int k_copy = k, res = 0;
        _for(j, 1, n) {
            if (a[j] <= k_copy)
                k_copy -= a[j],
                    res++;
            // cout << a[j] << endl;
        }
        ans = max(ans, res);
        a[i] = p[i] + s[i];
    }
    cout << ans << endl;
    return 0;
}