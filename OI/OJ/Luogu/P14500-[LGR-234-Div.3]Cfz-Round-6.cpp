/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-07-27
 * @Network   "https://www.luogu.com.cn/contest/255793"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  T3.cpp
 * @FilePath  /media/frank/FrankW/_default/Mine/Working/code-spaces/OI/OJ/Luogu/[LGR-234-Div.3]Cfz-Round-6/T3.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
long long n, l, r, k;
long long a[1010100];
bool check(long long x) {
    long long kuan = 0, maxx = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] - x > 0)
            continue;
        kuan++;
        maxx = max(maxx, x - a[i] + 1);
        sum += x - a[i] + 1;
    }
    // cout << kuan << " " << maxx << " " << k << " " << x << endl;
    return (sum <= k * x and maxx <= x);
}
int main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> n >> k;
    long long max_ai = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        max_ai = max(max_ai, a[i]);
    }
    int l = 1, r = n * max_ai;
    while (l <= r) {
        long long mid = l + r >> 1;
        // cout << l << " " << r << " " << mid << " -> check: ";
        if (check(mid))
            l = mid + 1;
        else
            r = mid - 1;
        // cout << l << " " << r << endl;
    }
    cout << l - 1;
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}