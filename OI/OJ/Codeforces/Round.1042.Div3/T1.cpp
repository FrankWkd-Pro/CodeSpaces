/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author     FrankWKD
 * @Date       2025-08-10
 * @Network    "https://codeforces.com/contest/2131/problem/0"
 * @License    GNU General Public License 2.0
 * @Platform   [Frank]iMac Ubuntu Pro 24.04 LTS
 * @Name       T1.cpp
 * @Path       /media/frank/FrankW1/_default/Mine/Working/code-spaces/OI/OJ/Codeforces/Round.1042.Div3/T1.cpp
 * @Sol        --
 */

// #pragma GCC optimize(3)
#define _for(cc, ba, ab) for (int cc = (ba); cc <= (ab); cc++)
#define for_(cc, ba, ab) for (int cc = (ba); cc >= (ab); cc--)
#include <bits/stdc++.h>
using namespace std;
// #define int long long
int n, a[101000], b[101000], ans, t;
int main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        ans = 1;
        _for(i, 1, n) cin >> a[i];
        _for(i, 1, n) cin >> b[i];
        _for(i, 1, n) {
            if (a[i] > b[i])
                ans += a[i] - b[i];
        }
        cout << ans << "\n";
    }
    return 0;
}