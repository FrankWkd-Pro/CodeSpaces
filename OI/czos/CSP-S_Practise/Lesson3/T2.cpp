/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-07-19
 * @Network   "https://oj.czos.cn/contest/problem?id=25664&pid=1"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  T2.cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/czos/CSP-S_Practise/Lesson3/T2.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef pair<int, int> pii;
struct node {
    int x, y;
} a[N], b[N];
int res1[N], res2[N];
int n;
priority_queue<pii, vector<pii>, greater<pii>> pl;
priority_queue<int, vector<int>, greater<int>> bri;
bool cmp(node a, node b) {
    return a.x < b.x;
}
void calc(node t[], int m, int res[]) {
    while (!pl.empty()) pl.pop();
    while (!bri.empty()) bri.pop();
    for (int i = 1; i <= n; i++) {
        bri.push(i);
    }
    for (int i = 1; i <= m; i++) {
        while (!pl.empty() and t[i].x >= pl.top().first) {
            bri.push(pl.top().second);
            pl.pop();
        }
        if (bri.empty())
            continue;
        int num = bri.top();
        bri.pop();
        res[num]++;
        pl.push({t[i].y, num});
    }
    for (int i = 1; i <= n; i++) {
        res[i] += res[i - 1];
    }
}
int main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    int m1, m2;
    cin >> n >> m1 >> m2;
    for (int i = 1; i <= m1; i++) cin >> a[i].x >> a[i].y;
    for (int i = 1; i <= m2; i++) cin >> b[i].x >> b[i].y;
    sort(a + 1, a + m1 + 1, cmp);
    sort(b + 1, b + m2 + 1, cmp);
    calc(a, m1, res1);
    calc(b, m2, res2);
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = max(ans, res1[i] + res2[n - i]);
    }
    cout << ans << endl;
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}