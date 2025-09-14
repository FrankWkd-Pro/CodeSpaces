/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-09-14
 * @Network   "https://oj.czos.cn/contest/problem?id=27599&pid=3"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  T1.cpp
 * @FilePath  /workspaces/CodeSpaces/OI/OJ/czos/Algorithm_Lessons/manacher/T1.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#define _for(aa, bb, cc) for (int aa = bb; aa <= cc; aa++)
#define for_(aa, bb, cc) for (int aa = bb; aa >= cc; aa--)
#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N = 1e7 + 10;
char a[N], [N * 2];
int p[N * 2];
int k, n;
int main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> a + 1;
    n = strlen(a + 1);
    s[0] = '$';
    s[++k] = '#';
    for (int i = 1; i <= n; i++) {
        s[++k] = a[i];
        s[++k] = '#';
    }
    n = k;
    int ans = 1;
    for (int i = 2, l, r = 1; i <= n; i++) {
        if (i <= r)
            p[i] = min(p[l + r - i], r - i + 1);
        while (s[i - p[i]] == s[i + p[i]]) p[i]++;
    }
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}  // TODO Mancher算法例题还没写完！