/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-07-28
 * @Network   "https://codeforces.com/problemset/problem/2128/B"
 * @License   GNU General Public License 3.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  CF2128B.cpp
 * @FilePath  /media/frank/FrankW/_default/Mine/Working/code-spaces/OI/OJ/Codeforces/CF2128B.cpp
 * @Solution  dp[i][j]代表第i个数选左0/右1的连续上升/下降长度，同时也存储上一个的操作（L/R）
 */

// #pragma GCC optimize(3)
// #define int long long
#define _for(cc, ba, ab) for (int cc = (ba); cc <= (ab); cc++)
#define for_(cc, ba, ab) for (int cc = (ba); cc >= (ab); cc--)
#include <bits/stdc++.h>
using namespace std;
struct dpnode {
    char op_last;
    int up_len, dw_len;
} dp[101000][2];
int n, a[100010];
int main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> n;
    while (n--) {
        int m;
        cin >> m;
        _for(i, 1, m) cin >> a[i];
        int up = 0, down = 0;  // q的连续上升/下降情况
        int ls = 0;            // q的上一个值
        _for(i, 1, m) {
        }
    }
    return 0;
}