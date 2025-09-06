/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author     FrankWKD
 * @Date       2025-08-21
 * @Network    ""
 * @License    GNU General Public License 2.0
 * @Platform   [Frank]iMac Ubuntu Pro 24.04 LTS
 * @Name       D.cpp
 * @Path       /media/frank/FrankW1/_default/Mine/Working/code-spaces/OI/OJ/czos/Algorithm_Lessons/Bitset+DP/D.cpp
 * @Sol        --
 */

// #pragma GCC optimize(3)
#define _for(cc, ba, ab) for (int cc = (ba); cc <= (ab); cc++)
#define for_(cc, ba, ab) for (int cc = (ba); cc >= (ab); cc--)
#include <bits/stdc++.h>
using namespace std;
// #define int long long
bitset<1100000> f[110];
int n, a[110], b[110];
int main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    f[0][0] = 1;
    cin >> n;
    _for(i, 1, n) {
        cin >> a[i] >> b[i];
        _for(j, a[i], b[i]) {
            f[i] = f[i] | (f[i - 1] << j * j);
        }
    }
    cout << f[n].count();
    return 0;
}