/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-07-26
 * @Network   "https://www.luogu.com.cn/problem/T624735?contestId=261525"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  T624735- [MX-X14-T1].cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/OI/Luogu/T624735- [MX-X14-T1].cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
string s;
int t[10100];
int k[10100];
string z;
int n;
int main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> n >> s >> z;
    for (int i = 0; i < n; i++) {
        t[s[i]]++, k[z[i]]++;
    }
    for (int i = 0; i <= 10010; i++) {
        if (t[i] != k[i]) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}