/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-07-25
 * @Network   ""
 * @License   GNU General Public License 2.0
 * @Platform  Win 7
 * @FileName  T1.cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/OI/Accoders/Contest-2025-07-25/T1.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("num.in", "r", stdin);
    freopen("num.out", "w", stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    long long n;
    int a[10] = {0, 1, 2, 4, 7, 8, 11, 13, 14};
    cin >> n;
    if (n % 8 == 0) {
        cout << a[8] + 15 * ((n - 1) / 8);
    } else {
        cout << a[n % 8] + 15 * (n / 8);
    }
    // fclose(stdin);
    // fclosetdout);
    return 0;
}