/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-10-04
 * @Network   ""
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  C.cpp
 * @FilePath  /workspaces/CodeSpaces/OI/OJ/Codeforces/CF2152/C.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#define _for(aa, bb, cc) for (auto aa = bb; aa <= cc; aa++)
#define for_(aa, bb, cc) for (auto aa = bb; aa >= cc; aa--)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n + 1);                        // 1-based索引
        vector<int> pre0(n + 1, 0), pre1(n + 1, 0);  // 前缀和统计0和1的数量

        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            pre0[i] = pre0[i - 1] + (a[i] == 0);
            pre1[i] = pre1[i - 1] + (a[i] == 1);
        }

        while (q--) {
            int l, r;
            cin >> l >> r;
            int len = r - l + 1;

            // 检查长度是否为3的倍数
            if (len % 3 != 0) {
                cout << -1 << '\n';
                continue;
            }

            // 计算区间内0和1的数量
            int cnt0 = pre0[r] - pre0[l - 1];
            int cnt1 = pre1[r] - pre1[l - 1];

            // 检查0和1的数量是否为3的倍数
            if (cnt0 % 3 != 0 || cnt1 % 3 != 0) {
                cout << -1 << '\n';
                continue;
            }

            // 合法区间的最小代价为三元组数量
            cout << len << '\n';
        }
    }

    return 0;
}
