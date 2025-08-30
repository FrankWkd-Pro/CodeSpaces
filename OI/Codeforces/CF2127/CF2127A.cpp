/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author     FrankWKD
 * @Date       2025-08-07
 * @Network    "https://codeforces.com/contest/2127/problem/A"
 * @License    OFF
 * @Platform   [Frank]iMac Ubuntu Pro 24.04 LTS
 * @Name       CF2127A.cpp
 * @Path       /media/frank/FrankW1/_default/Mine/Working/code-spaces/OI/OJ/Codeforces/CF2127A.cpp
 * @Sol        --
 */

#pragma GCC optimize(3)
#define _for(cc, ba, ab) for (int cc = (ba); cc <= (ab); cc++)
#define for_(cc, ba, ab) for (int cc = (ba); cc >= (ab); cc--)
#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N = 510;
int a[N], t, n;

int main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        bool f = 1;
        int non_zero = -1;
        _for(i, 1, n) cin >> a[i];
        _for(i, 1, n) {
            if (a[i] == 0) {
                f = 0;
                break;
            }
            if (non_zero == -1 and a[i] != -1)
                non_zero = a[i];
            else if (non_zero != a[i] and a[i] != -1) {
                f = 0;
                break;
            }
        }
        cout << (f == 1 ? "YES" : "NO") << "\n";
    }
    return 0;
}