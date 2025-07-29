/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-07-29
 * @Network   ""
 * @License   GNU General Public License 3.0
 * @Platform
 * @FileName  T2.cpp
 * @FilePath  /media/frank/FrankW/_default/Mine/Working/code-spaces/OI/OJ/Accoders/Contest-2025-07-29/Problem2/T2.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
// #define int long long
#define _for(cc, ba, ab) for (int cc = (ba); cc <= (ab); cc++)
#define for_(cc, ba, ab) for (int cc = (ba); cc >= (ab); cc--)
#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int pos = 0;  // 0-based
    for (int i = 2; i <= n; ++i) {
        pos = (pos + m) % i;
    }
    cout << pos + 1 << endl;
    return 0;
}