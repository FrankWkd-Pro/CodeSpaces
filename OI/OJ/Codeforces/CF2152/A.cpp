/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-10-03
 * @Network   "https://codeforces.com/contest/2152/problem/A"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  A.cpp
 * @FilePath  /workspaces/CodeSpaces/OI/OJ/Codeforces/CF2152/A.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#define _for(aa, bb, cc) for (int aa = bb; aa <= cc; aa++)
#define for_(aa, bb, cc) for (int aa = bb; aa >= cc; aa--)
#include <bits/stdc++.h>
using namespace std;
// #define int long long
int n, t;
int a[110];
int main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> n;
        _for(i, 1, n) {
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n);
        n = unique(a + 1, a + 1 + n) - a - 1;
        cout << n + (n - 1) << "\n";
    }

    // fclose(stdin);
    // fclose(stdout);
    return 0;
}