/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author     FrankWKD
 * @Date       2025-08-10
 * @Network    "https://codeforces.com/contest/2131/problem/B"
 * @License    GNU General Public License 2.0
 * @Platform   [Frank]iMac Ubuntu Pro 24.04 LTS
 * @Name       T2.cpp
 * @Path       /media/frank/FrankW1/_default/Mine/Working/code-spaces/OI/OJ/Codeforces/Round.1042.Div3/T2.cpp
 * @Sol        --
 */

// #pragma GCC optimize(3)
#define _for(cc, ba, ab) for (int cc = (ba); cc <= (ab); cc++)
#define for_(cc, ba, ab) for (int cc = (ba); cc >= (ab); cc--)
#include <bits/stdc++.h>
using namespace std;
// #define int long long
int t, n;
int main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        if (n % 2 == 0) {
            _for(i, 1, n - 1) {
                if (i % 2 == 1)
                    cout << "-1 ";
                else
                    cout << "3 ";
            }
            cout << "2\n";
        } else {
            _for(i, 1, n) {
                if (i % 2 == 1)
                    cout << "-1 ";
                else
                    cout << "3 ";
            }
        }
    }
    return 0;
}