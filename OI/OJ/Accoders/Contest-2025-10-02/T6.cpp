/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-10-02
 * @Network   "http://www.accoders.com/problem.php?cid=5135&pid=5"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  T6.cpp
 * @FilePath  /workspaces/CodeSpaces/OI/OJ/Accoders/Contest-2025-10-02/T6.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#define _for(aa, bb, cc) for (auto aa = bb; aa <= cc; aa++)
#define for_(aa, bb, cc) for (auto aa = bb; aa >= cc; aa--)
#include <bits/stdc++.h>
using namespace std;
const int N = 220000;
struct node {
    int l, r, color;
    // color=1->white
    // color=2->black
} a[N];
int n, num, ans;

multiset<int> white, black;
bool comp(node x, node y) {
    if (x.r < y.r)
        return (true);
    if (x.r == y.r && x.l < y.l)
        return (true);
    return (false);
}
int main() {
    freopen("bicolored.in", "r", stdin);
    freopen("bicolored.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].color);
    sort(a + 1, a + n + 1, comp);

    num = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i].color == 1) {
            multiset<int>::iterator it = black.lower_bound(a[i].l);
            if (it != black.end()) {
                num++;
                black.erase(it);
            } else
                white.insert(a[i].r);
        } else {
            multiset<int>::iterator it = white.lower_bound(a[i].l);
            if (it != white.end()) {
                num++;
                white.erase(it);
            } else
                black.insert(a[i].r);
        }
    }
    ans = n - num;
    printf("%d", ans);
    return 0;
}

////////////////////// CPH-NG DATA STARTS //////////////////////
/*
H4sIAAAAAAAAA6tWykvMTVWyUgoxU9JRKkkuVrKKjtVRKsnMTfXJzM0sUbIyNDAw
qAUAiOvuEScAAAA=
 */
/////////////////////// CPH-NG DATA ENDS ///////////////////////
