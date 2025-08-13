/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-07-30
 * @Network   ""
 * @License   GNU General Public License 3.0
 * @Platform  win
 * @FileName  lexi.cpp
 * @FilePath  /media/frank/FrankW/_default/Mine/Working/code-spaces/OI/OJ/Accoders/Contest-2025-07-30/lexi/lexi.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
// #define int long long
#define _for(cc, ba, ab) for (int cc = (ba); cc <= (ab); cc++)
#define for_(cc, ba, ab) for (int cc = (ba); cc >= (ab); cc--)
#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int main() {
    freopen("lexi.in", "r", stdin);
    freopen("lexi.out", "w", stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> s1 >> s2;
    _for(i, 0, s1.size()) {
        s1[i] = (s1[i] >= 'A' and s1[i] <= 'Z') ? s1[i] - 'A' + 'a' : s1[i];
        s2[i] = (s2[i] >= 'A' and s2[i] <= 'Z') ? s2[i] - 'A' + 'a' : s2[i];
        if (s1[i] < s2[i]) {
            cout << -1;
            return 0;
        }
        if (s1[i] > s2[i]) {
            cout << 1;
            return 0;
        }
    }
    cout << 0;
    return 0;
}