/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author     FrankWKD
 * @Date       2025-08-10
 * @Network    "https://codeforces.com/contest/2131/problem/C"
 * @License    GNU General Public License 2.0
 * @Platform   [Frank]iMac Ubuntu Pro 24.04 LTS
 * @Name       T3.cpp
 * @Path       /media/frank/FrankW1/_default/Mine/Working/code-spaces/OI/OJ/Codeforces/Round.1042.Div3/T3.cpp
 * @Sol        --
 */

// #pragma GCC optimize(3)
#define _for(cc, ba, ab) for (int cc = (ba); cc <= (ab); cc++)
#define for_(cc, ba, ab) for (int cc = (ba); cc >= (ab); cc--)
#include <bits/stdc++.h>
using namespace std;
// #define int long long
int s[200010], t[200010], n, T, k, vak;
map<long long, int> ton;
int main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> T;
    while (T--) {
        ton.clear();
        cin >> n >> vak;
        bool fl = 1;
        _for(i, 1, n) cin >> s[i], s[i] %= vak;
        _for(i, 1, n) cin >> t[i], t[i] %= vak, ton[t[i]]++;

        _for(i, 1, n) {
            if (ton[s[i]])
                ton[s[i]]--;
            else if (ton[vak - s[i]] > 0)
                ton[vak - s[i]]--;
            else {
                fl = 0;
                break;
            }
        }
        cout << ((fl == 1) ? "YES" : "NO") << "\n";
    }
    return 0;
}