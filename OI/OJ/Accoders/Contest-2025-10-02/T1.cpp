/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author     FrankWKD
 * @Date       2025-10-02
 * @Network    "http://www.accoders.com/problem.php?cid=5135&pid=0"
 * @License    GNU General Public License 2.0
 * @Platform   [Frank]iMac Ubuntu Pro 24.04 LTS
 * @Name       T1.cpp
 * @Path       /workspaces/CodeSpaces/OI/OJ/Accoders/Contest-2025-10-02/T1.cpp
 * @Sol        --
 */

// #pragma GCC optimize(3)
#define _for(cc, ba, ab) for (auto cc = (ba); cc <= (ab); cc++)
#define for_(cc, ba, ab) for (auto cc = (ba); cc >= (ab); cc--)
#include <bits/stdc++.h>
using namespace std;
// #define int long long
string s1, s2 = "heidi";
int i1, i2;
int main() {
    freopen("delstr.in", "r", stdin);
    freopen("delstr.out", "w", stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> s1;
    while (i1 < s1.size() and i2 < s2.size()) {
        if (s1[i1] == s2[i2])
            i2++;
        i1++;
        // cout << i1 << " " << i2 << endl;
    }
    if (i2 == s2.size())
        cout << "YES";
    else
        cout << "NO";
    return 0;
}