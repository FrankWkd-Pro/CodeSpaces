/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-07-27
 * @Network   "https://www.luogu.com.cn/contest/255793"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  T2.cpp
 * @FilePath  /media/frank/FrankW/_default/Mine/Working/code-spaces/OI/OJ/Luogu/[LGR-234-Div.3]Cfz-Round-6/T2.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
int now_byte;
int n, m;
string s;
int byt[1010000];
bool appear[1010000];
bool being[1010000];
int main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int now_num = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        now_byte += (appear[x] == 1 ? 0 : 1) * to_string(x).size();
        now_num += (appear[x] == 1 ? 0 : 1);
        appear[x] = 1;
        byt[x] = now_byte + now_num - 1;
        // cout << byt[x] << endl;
    }
    for (int i = 1; i <= m; i++) cout << byt[i] << " ";
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}