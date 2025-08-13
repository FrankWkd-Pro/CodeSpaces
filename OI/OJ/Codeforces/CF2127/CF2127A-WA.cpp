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
// int sol(int i, int mi) {
//     if (mi != 0)
//         return 0;
//     if (mi + 1 != a[i + 1] and mi + 1 != a[i + 2] and mi + 1 != a[i])
//         return mi + 1;
//     if (mi + 2 != a[i + 1] and mi + 2 != a[i + 2] and mi + 2 != a[i])
//         return mi + 2;
//     return mi + 3;
// }
int main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        bool f = 1;
        _for(i, 1, n) cin >> a[i];
        _for(i, 1, n - 2) {
            int cnt = 0;
            if (a[i] == 0 or a[i + 1] == 0 or a[i + 2] == 0) {
                f = 0;
                break;
            }
            if (a[i] == -1)
                cnt++;
            if (a[i + 1] == -1)
                cnt++;
            if (a[i + 2] == -1)
                cnt++;
            if (cnt >= 2)
                continue;

            if (a[i] == -1) {
                if (a[i + 1] != a[i + 2]) {
                    f = 0;
                    break;
                } else
                    continue;
            }
            if (a[i + 1] == -1) {
                if (a[i] != a[i + 2]) {
                    f = 0;
                    break;
                } else
                    continue;
            }
            if (a[i + 2] == -1) {
                if (a[i] != a[i + 1]) {
                    f = 0;
                    break;
                } else
                    continue;
            }
            int mi = min(a[i], min(a[i + 1], a[i + 2]));
            int ma = max(a[i], max(a[i + 1], a[i + 2]));
            if (ma != mi) {
                f = 0;
                break;
            }
        }
        cout << (f == 1 ? "YES" : "NO") << "\n";
    }
    return 0;
}