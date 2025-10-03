/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-10-03
 * @Network   "https://www.luogu.com.cn/problem/P1086"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  P1086.cpp
 * @FilePath  /workspaces/CodeSpaces/OI/OJ/Luogu/P1086.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#define _for(aa, bb, cc) for (int aa = bb; aa <= cc; aa++)
#define for_(aa, bb, cc) for (int aa = bb; aa >= cc; aa--)
#include <bits/stdc++.h>
using namespace std;
const int N = 30;
int mp[N][N];
int n, m, k;
int tmd;
int fx, fy, ex, ey;
int pn;
int ans;
struct dire {
    int x, y, sum;
} stu[N * N];
bool comp(struct dire a, struct dire b) {
    return a.sum > b.sum;
}
int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
            if (mp[i][j] > 0) {
                stu[++pn].sum = mp[i][j];
                stu[pn].x = i;
                stu[pn].y = j;
            }
        }
    }
    sort(stu + 1, stu + pn + 1, comp);
    fx = 1;
    fy = stu[1].y;
    k--;
    for (int i = 1; i <= pn; i++) {
        tmd = 0;
        ex = stu[i].x;
        ey = stu[i].y;
        tmd = abs(fx - ex) + abs(fy - ey);
        k--;
        k -= tmd;
        if (k >= ex) {
            ans += mp[ex][ey];
            fx = ex;
            fy = ey;
        } else {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
