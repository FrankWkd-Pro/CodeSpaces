
/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-07-24
 * @Network   "https://www.luogu.com.cn/problem/P7078"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  P_7078_CSP_S_2020_贪吃蛇.cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/P_7078_CSP_S_2020_贪吃蛇.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int N = 1e6 + 10;
#define endl '\n'
pi q1[N], q2[N];
int h1, t1, h2, t2;
int n, m, t, a[N];
pi get_min() {
    pi res = {INT_MAX, INT_MAX};
    if (h1 <= t1)
        res = q1[h1];
    if (h2 <= t2 and q2[h2] < res)
        res = q2[h2];
    return res;
}
pi get_max() {
    pi res = {0, 0};
    if (h1 <= t1)
        res = q1[t1];
    if (h2 <= t2 and res < q2[t2])
        res = q2[t2];
    return res;
}
bool dfs(int x) {
    if (x == 1)
        return 0;
    if (x == 2)
        return 1;
    pi mi = get_min(), ma = get_max();
    if (h1 <= t1 and mi == q1[h1])
        h1++;
    else
        h2++;
    if (h1 <= t1 and ma == q1[t1])
        t1--;
    else
        t2--;
    ma.first -= mi.first;
    if (ma > get_min())
        return true;
    q2[--h2] = ma;
    return !dfs(x - 1);
}
int get() {
    h1 = 1, t1 = 0;
    h2 = n + 1, t2 = n;
    for (int i = 1; i <= n; i++) q1[++t1] = {a[i], i};
    int res = n;
    for (int i = 1; i <= n - 1; i++) {
        pi mi = get_min(), ma = get_max();
        if (h1 <= t1 and mi == q1[h1])
            h1++;
        else
            h2++;
        if (h1 <= t1 and ma == q1[t1])
            t1--;
        else
            t2--;
        ma.first -= mi.first;
        q2[--h2] = ma;
        res--;
        if (ma == get_min())
            break;
    }
    res += dfs(res);
    return res;
}
int work3() {
    if (a[3] - a[1] < a[2])
        return 3;
    else
        return 1;
}
int main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    bool fl = 1;
    int x, y;
    while (t--) {
        if (fl) {
            cin >> n;
            for (int i = 1; i <= n; i++) {
                cin >> a[i];
            }
            fl = 0;
        } else {
            cin >> m;
            for (int i = 1; i <= m; i++) {
                cin >> x >> y;
                a[x] = y;
            }
        }
        if (n == 3)
            cout << work3() << endl;
        else
            cout << get() << endl;
    }
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}