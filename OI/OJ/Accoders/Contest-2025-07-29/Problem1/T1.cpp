/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-07-29
 * @Network   ""
 * @License   GNU General Public License 3.0
 * @Platform  Win 7
 * @FileName  T1.cpp
 * @FilePath  /media/frank/FrankW/_default/Mine/Working/code-spaces/OI/OJ/Accoders/Contest-2025-07-29/Problem1/T1.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
// #define int long long
#define _for(cc, ba, ab) for (int cc = (ba); cc <= (ab); cc++)
#define for_(cc, ba, ab) for (int cc = (ba); cc >= (ab); cc--)
#include <bits/stdc++.h>
using namespace std;
long long n, x, tot;
long long two, five;
int main() {
    freopen("zero.in", "r", stdin);
    freopen("zero.out", "w", stdout);
    cin >> n;
    _for(i, 1, n) {
        cin >> x;
        while (x % 5 == 0) five += 1, x /= 5;
        while (x % 2 == 0) two += 1, x /= 2;
    }
    // 统计若干个数统计乘积末尾0的个数
    while (two > 0 && five > 0) {
        tot++;
        two -= 1;
        five -= 1;
    }
    long long kkk = (two > 0 ? 2 * two : 1) * (five > 0 ? 5 * five : 1);
    // cout << kkk << endl;
    while (kkk % 10 == 0) tot++, kkk /= 10;
    cout << tot << endl;
    return 0;
}