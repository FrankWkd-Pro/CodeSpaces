/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-07-14
 * @Network   "https://oj.czos.cn/contest/problem?id=25410&pid=2"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  T3[40pts].cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/czos/CSP-S_Practise/Lesson1/T3[40pts].cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
struct node {
    int d, v, a;
} a[N];
int p[N];
int n, m, len, v;
int cnt, res, T;
int pf(int x) {
    return x * x;
}
bool check(int di, int vi, int ai, int ed) {
    return pf(vi) + 2 * ai * (ed - di) > pf(v);
}
int main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> m >> len >> v;
        for (int i = 1; i <= n; i++) {
            scanf("%d%d%d", &a[i].d, &a[i].v, &a[i].a);
        }
        for (int i = 1; i <= m; i++) {
            cin >> p[i];
        }
        cnt = 0;
        int c0 = 0, c1 = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i].a == 0)
                c0++;
            else if (a[i].a > 0)
                c1++;
            if (a[i].d > p[m])
                continue;
            if (a[i].v > v and a[i].a == 0) {
                cnt++;
                continue;
            }
            if (a[i].a > 0 and check(a[i].d, a[i].v, a[i].a, p[m])) {
                cnt++;
                continue;
            }
        }
        if (c0 == n or c1 == n) {
            if (cnt == 0)
                res = m;
            else
                res = m - 1;
        }
        cout << cnt << " " << res << endl;
    }
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}