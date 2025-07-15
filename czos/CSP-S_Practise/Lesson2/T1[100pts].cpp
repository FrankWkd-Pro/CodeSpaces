/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-07-14
 * @Network   "https://oj.czos.cn/contest/problem?id=25573&pid=0&_pjax=%23p0"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  T1[100pts].cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/czos/CSP-S_Practise/Lesson2/T1[100pts].cpp
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
    string s;
    long long c;
    cin >> s >> c;
    if (c == 1)
        cout << s[0];
    else {
        if (s[0] == '1') {
            long long i = 0;
            while (i < min(c - 1, (long long)(s.size() - 1)) and s[i] == '1') i++;
            cout << s[i];
        } else
            cout << s[0];
    }
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}