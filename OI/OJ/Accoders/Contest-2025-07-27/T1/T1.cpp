/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-07-27
 * @Network   ""
 * @License   GNU General Public License 2.0
 * @Platform  Win 7
 * @FileName  T1.cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/OI/OJ/Accoders/Contest-2025-07-27/T1/T1.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int main() {
    freopen("lexi.in", "r", stdin);
    freopen("lexi.out", "w", stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> s1 >> s2;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] >= 'A' and s1[i] <= 'Z')
            s1[i] = s1[i] - 'A' + 'a';
        if (s2[i] >= 'A' and s2[i] <= 'Z')
            s2[i] = s2[i] - 'A' + 'a';
    }
    // cout << s1 << " " << s2 << endl;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] < s2[i]) {
            cout << -1;
            return 0;
        } else if (s1[i] > s2[i]) {
            cout << 1;
            return 0;
        }
    }

    cout << 0;
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}