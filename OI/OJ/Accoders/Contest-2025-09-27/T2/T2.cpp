/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author     FrankWKD
 * @Date       2025-09-27
 * @Network    "http://www.accoders.com/problem.php?cid=5149&pid=1"
 * @License    GNU General Public License 2.0
 * @Platform   [Frank]iMac Ubuntu Pro 24.04 LTS
 * @Name       T2.cpp
 * @Path       ~/桌面/Contest-2025-09-27/T2/T2.cpp
 * @Sol        --
 */

// #pragma GCC optimize(3)
#define _for(cc, ba, ab) for (int cc = (ba); cc <= (ab); cc++)
#define for_(cc, ba, ab) for (int cc = (ba); cc >= (ab); cc--)
#include <bits/stdc++.h>
using namespace std;
// #define int long long
int n, x, other;
struct node {
    int idx, val;
} a[4010];
bool cmp(node ii, node jj) {
    return ii.val == jj.val ? ii.idx < jj.idx : ii.val < jj.val;
}
void init() {
    _for(i, 1, n) a[i].idx = i;
}
int main() {
    freopen("pack.in", "r", stdin);
    freopen("pack.out", "w", stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> n;
    init();
    while (1) {
        cin >> x;
        if (x == 0)
            break;
        if (x > 0 and x < 100)
            a[1].val++;
        else {
            bool f = 0;
            _for(i, 2, n) {
                int l = i * 50;
                int r = l + 50;
                if (x >= l and x < r) {
                    a[i].val++;
                    f = 1;
                }
            }
            if (!f) {
                other++;
                // cout << x << endl;
            }
        }
    }
    int maxx = 0;
    _for(i, 1, n) {
        if (a[i].val > maxx) {
            maxx = a[i].val;
        }
    }

    vector<int> v;
    _for(i, 1, n) {
        if (a[i].val == maxx)
            v.push_back(a[i].idx);
    }
    sort(v.begin(), v.end());
    for (auto i : v) {
        cout << "NO." << i << endl;
    }
    if (other > 0)
        cout << "Other:" << other;

    return 0;
}
/*
hack:
4
0-100
100-150
150-200
200-250
1 100 149 150 150 177 199 200 250 201 251 250

*/
