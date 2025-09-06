/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-07-18
 * @Network   "https://oj.czos.cn/contest/problem?id=25573&pid=4"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  T5.cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/czos/CSP-S_Practise/Lesson2/T5.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
int T, n;
int ans, s[22], c[5];
int num() {
    int tot = 0;
    memset(c, 0, sizeof c);
    int t = (s[0] == 2);  // 判断是否有双王
    for (int i = 0; i <= 14; i++) {
        c[s[i]]++;  // 有4张牌的种类数，有1张牌的种类数，有2张牌的种类数...
    }
    while (c[4] > 0 and c[2] - t >= 2) {
        c[4]--;
        c[2] -= 2;
        tot++;
    }
    while (c[4] > 0 and c[1] >= 2) {
        c[4]--;
        c[1] -= 2;
        tot++;
    }
    while (c[4] > 0 and c[2] > 0) {
        c[4]--;
        c[2] -= 1;
        tot++;
    }
    while (c[3] > 0 and c[2] - t > 0) {
        c[3]--;
        c[2] -= 1;
        tot++;
    }
    while (c[3] > 0 and c[1] > 0) {
        c[3]--;
        c[1] -= 1;
        tot++;
    }
    return tot + c[1] + c[2] + c[3] + c[4];
}
void dfs(int x) {
    // x: 出顺子的数量
    if (x >= ans)
        return;                 // 最优性剪枝
    ans = min(ans, x + num());  // 更新答案
    for (int i = 3; i > 0; i--) {
        for (int j = 3; j <= 14; j++) {
            int p = j;
            while (s[p] >= i and p <= 14) {
                if ((i == 3 and p - j + 1 >= 2) or (i == 2 and p - j + 1 >= 3) or (i == 1 and p - j + 1 >= 5)) {
                    for (int k = j; k <= p; k++) s[k] -= i;
                    dfs(x + 1);  // 搜索～
                    for (int k = j; k <= p; k++) s[k] += i;
                }
                p++;  // warning!
            }
        }
    }
}

int main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> T >> n;
    while (T--) {
        ans = n;
        memset(s, 0, sizeof s);
        for (int i = 1; i <= n; i++) {
            int a, b;
            cin >> a >> b;
            if (a == 1)
                a = 14;
            s[a]++;
        }
        dfs(0);
        cout << ans << endl;
    }
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}