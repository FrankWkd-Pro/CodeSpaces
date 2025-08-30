/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-07-27
 * @Network   ""
 * @License   GNU General Public License 2.0
 * @Platform  Win 7
 * @FileName  T2.cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/OI/OJ/Accoders/Contest-2025-07-27/T2/T2.cpp
 * @Solution  考虑贪心。统计每个数字的出现次数？，从小到大枚举，如果大于2就考虑状态转移，否则操作1或许可以？
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
int t[500100];  // trick
int n;
int _minus(int x) {
    int nowi = n + n;
    for (int i = 1; i <= n; i++) {
        if (t[i] != 0) {
            t[i - x] = t[i];  // i-x > 0一定成立
            t[i] = 0;
            nowi = min(nowi, i - x);
        }
    }
    // cout << "nowi: " << nowi << endl;
    // exit(0);
    return nowi;
}
int main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);

    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x >= n)
            ans++;
        else
            t[x]++;
    }
    for (int i = 1; i <= n; i++) {
        if (t[i] == 1)
            ans++;
        else if (t[i] > 1) {
            if (i <= t[i]) {
                ans += i;
                t[i] = 0;
                i = _minus(i) - 1;
            } else
                ans += t[i];
        }
        // cout << i << endl;
    }
    cout << n << endl;
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}