/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-09-06
 * @Network   "https://www.luogu.com.cn/problem/P13992"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  P13992-[MX-X19]T1.cpp
 * @FilePath  /workspaces/CodeSpaces/OI/OJ/Luogu/P13992-[MX-X19]T1.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    int n;
    string s;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        int cnt = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] >= 'A' and s[j] <= 'Z')
                cnt++;
        }
        cout << max(min(5 - cnt, abs((int)s.size() - 5)), 0) << "\n";
    }
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}