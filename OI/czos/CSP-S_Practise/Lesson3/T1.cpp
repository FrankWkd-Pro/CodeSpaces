/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-07-19
 * @Network   "https://oj.czos.cn/contest/problem?id=25664&pid=0"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  T1.cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/czos/CSP-S_Practise/Lesson3/T1.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
long long n, ans;
int cnt[110][100];

int main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> n;
    int x, y;
    for (int i = 1; i <= n; i++) {
        y = i % 10;
        x = i;
        while (x >= 10) {
            x /= 10;
        }
        cnt[x][y]++;
    }
    for (int i = 1; i <= n; i++) {
        y = i % 10;
        x = i;
        while (x >= 10) x /= 10;
        ans += cnt[y][x];
    }
    cout << ans << endl;
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}