/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-07-27
 * @Network   "https://www.luogu.com.cn/contest/255793"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  T1.cpp
 * @FilePath  /media/frank/FrankW/_default/Mine/Working/code-spaces/OI/OJ/Luogu/[LGR-234-Div.3]Cfz-Round-6/T1.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

string s;
int n;
bool check(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0')
            return false;
    }
    return true;
}
int main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> n >> k;
    for (int j = 1; j <= n; j++) {
        cin >> s;
        unsigned long long ans = 0;
        if (check(s)) {
            ans = 1;
            int tot = 0;
            for (int i = 0; i < s.size(); i++) {
                ans = ans * (s[i] - '0');
                if (ans > k)
                    break;
            }
        }
        if (ans <= k)
            cout << "kawaii\n";
        else
            cout << "dame\n";
    }
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}