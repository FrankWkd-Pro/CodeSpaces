/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-07-25
 * @Network   ""
 * @License   GNU General Public License 2.0
 * @Platform  Win 7
 * @FileName  T3.cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/OI/Accoders/Contest-2025-07-25/T3.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
int a[1000100], t[1001000], contri[1001000], n;
int main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        t[a[i]]++;
    }
    cout << n;
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}