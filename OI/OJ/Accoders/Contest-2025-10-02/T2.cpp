/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-10-02
 * @Network   "http://www.accoders.com/problem.php?cid=5135&pid=1"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  T2.cpp
 * @FilePath  /workspaces/CodeSpaces/OI/OJ/Accoders/Contest-2025-10-02/T2.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#define _for(aa, bb, cc) for (auto aa = bb; aa <= cc; aa++)
#define for_(aa, bb, cc) for (auto aa = bb; aa >= cc; aa--)
#include <bits/stdc++.h>
using namespace std;
int T, n;
int main() {
    freopen("nums.in", "r", stdin);
    freopen("nums.out", "w", stdout);
    cin >> T;
    while (T--) {
        cin >> n;
        int cnt = 0, tmp = n, m;
        while (tmp != 0) {
            cnt++;
            m = tmp % 10;
            tmp /= 10;
        }
        int temp = m;
        for (int i = 0; i < cnt - 1; i++) {
            temp = temp * 10 + m;
        }
        if (n >= temp)
            cout << (cnt - 1) * 9 + m << "\n";
        if (n < temp)
            cout << (cnt - 1) * 9 + m - 1 << "\n";
    }
    return 0;
}
