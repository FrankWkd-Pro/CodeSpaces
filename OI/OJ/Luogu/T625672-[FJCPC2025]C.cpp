/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-07-06
 * @Network   "https://www.luogu.com.cn/problem/T625672?contestId=254970"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  T625672-[FJCPC2025]C.cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/Luogu/T625672-[FJCPC2025]C.cpp
 * @Solution  经推理可得，如果n<=3，就是最大数，否则就是第二大的数。
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    int t, n;
    int a[100010];
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n);
        if (n <= 3)
            cout << a[n] << "\n";
        else
            cout << a[n - 1] << "\n";
    }
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}