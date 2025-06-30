/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-06-30
 * @Network   "https://www.luogu.com.cn/problem/P1226"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  P1226-FastPow.cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/Luogu/P1226-FastPow.cpp
 * @Solution  快速幂模板
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
int n, m, p;
long long fastpow(long long x, long long y) {
    long long ans = 1;
    while (y > 0) {
        if (y & 1) {
            ans = (x * ans) % p;
        }
        y >>= 1;
        x = (x * x) % p;
    }
    return ans;
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> n >> m >> p;
    printf("%d^%d mod %d=%lld", n, m, p, fastpow(n, m));
    return 0;
}