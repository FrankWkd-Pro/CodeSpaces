/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author     FrankWKD
 * @Date       2025-09-27
 * @Network    ""
 * @License    GNU General Public License 2.0
 * @Platform   [Frank]iMac Ubuntu Pro 24.04 LTS
 * @Name       T4.cpp
 * @Path       ~/桌面/Contest-2025-09-27/T4/T4.cpp
 * @Sol        --
 */

#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
int n, t[1000010], alt[1000010], k;
int main() {
    freopen("chores.in", "r", stdin);
    freopen("chores.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
        alt[i] = t[i];
        scanf("%d", &k);
        for (int j = 1; j <= k; j++) {
            int a;
            scanf("%d", &a);
            alt[i] = max(alt[i], alt[a] + t[i]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, alt[i]);
    printf("%d\n", ans);
}