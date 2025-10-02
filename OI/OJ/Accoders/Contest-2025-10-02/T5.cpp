/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-10-02
 * @Network   "http://www.accoders.com/problem.php?cid=5135&pid=4"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  T5.cpp
 * @FilePath  /workspaces/CodeSpaces/OI/OJ/Accoders/Contest-2025-10-02/T5.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#define _for(aa, bb, cc) for (int aa = bb; aa <= cc; aa++)
#define for_(aa, bb, cc) for (int aa = bb; aa >= cc; aa--)
#include <bits/stdc++.h>
using namespace std;
const int N = 1100000;
int t, n, flag = 0;
long long a[N], b[N], aa[N], bb[N];
long long l, r, mid;
int pd(long long x) {
    for (int i = 1; i <= n; i++) {
        aa[i] = a[i];
        bb[i] = b[i];
    }
    long long temp;
    bb[0] = bb[n] - x;
    for (int i = 1; i <= n; i++) {
        aa[i] -= bb[i - 1];
        if (aa[i] < 0)
            continue;
        if (i == n) {
            if (aa[i] > x)
                return (1);
            else
                return (0);
        } else {
            if (aa[i] > bb[i])
                return (2);
            else {
                bb[i] -= aa[i];
                aa[i] = 0;
            }
        }
    }
    return 0;
}
int main() {
    freopen("network.in", "r", stdin);
    freopen("network.out", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        flag = 0;
        for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
        for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
        l = 0;
        r = b[n];
        while (l < r) {
            mid = (l + r + 1) / 2;
            int temp = pd(mid);
            if (temp == 0) {
                flag = 1;
                break;
            } else if (temp == 1)
                l = mid;
            else
                r = mid - 1;
        }
        if (pd(l) == 0)
            flag = 1;
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}