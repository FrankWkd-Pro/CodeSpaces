/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-09-13
 * @Network   "https://www.luogu.com.cn/problem/T664113?contestId=275290"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  T664113-[MX-X20-T2][FAOI-R7]T2.cpp
 * @FilePath  /workspaces/CodeSpaces/OI/OJ/Luogu/T664113-[MX-X20-T2][FAOI-R7]T2.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#define _for(aa, bb, cc) for (int aa = bb; aa <= cc; aa++)
#define for_(aa, bb, cc) for (int aa = bb; aa >= cc; aa--)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int b[N], c[N], n, m, t, l, r;
int main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        _for(i, 1, n) {
            cin >> b[i];
        }
        _for(i, 1, m) {
            cin >> l >> r;
            c[l]++, c[r + 1]--;
        }
        int mid = 0;
        _for(i, 1, n) c[i] += c[i - 1], mid += b[i];
        mid /= n;
        int mi = -1, ma = -1;
        _for(i, 1, n) {
            if ()
        }
    }
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}