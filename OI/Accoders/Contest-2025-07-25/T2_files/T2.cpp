/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-07-25
 * @Network   ""
 * @License   GNU General Public License 2.0
 * @Platform  Win 7
 * @FileName  T2.cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/OI/Accoders/Contest-2025-07-25/T2.cpp
 * @Solution  --
 */

#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
priority_queue<long long> qd;
priority_queue<long long, vector<long long>, greater<long long>> qx;
int da[100010], xi[100100];
int k1, k2;
long long n, x, y, sum;
int main() {
    freopen("mali.in", "r", stdin);
    freopen("mali.out", "w", stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld", &x, &y);
        qd.push(x);
        qx.push(y);
        for (int j = 1; j <= i; j++) {
            x = qd.top();
            y = qx.top();
            qd.pop();
            qx.pop();
            sum = max(sum, y + x);
            da[++k1] = x;
            xi[k1] = y;
        }
        for (int j = 1; j <= i; j++) {
            qd.push(da[j]);
            qx.push(xi[j]);
        }
        printf("%lld\n", sum);
        sum = 0;
        k1 = 0;
    }
    return 0;
}