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
deque<int> q;
int a[1010100];
int n;
int main() {
    // freopen("T2_duel_Data/duel4.in", "r", stdin);
    // freopen("T2_Run_data.out", "w", stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        if (!q.empty() and q.back() < a[i]) {
            q.pop_back();
            q.push_front(a[i]);
        } else
            q.push_back(a[i]);
    }
    cout << q.size();
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}