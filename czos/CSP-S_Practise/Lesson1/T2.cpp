/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-07-09
 * @Network   "https://oj.czos.cn/contest/problem?id=25410&pid=1"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  T2.cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/czos/CSP-S_Practise/Lesson1/T2.cpp
 * @Solution  这真的不配来S。不难发现，最优策略就是我们先排序，然后第二小的打败第一小的，第三小的打败第二小的...以此类推。使用队列模拟即可。
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int a[N], n;
bool cmp(int m, int b) {
    return m > b;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1, cmp);
    int ans = n;
    for (int i = n, j = n; i >= 1; i--) {
        if (a[i] > a[j]) {
            j--;
            ans--;
        }
    }
    printf("%d", ans);
    return 0;
}