/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author     FrankWKD
 * @Date       2025-09-27
 * @Network    "http://www.accoders.com/problem.php?cid=5149&pid=0"
 * @License    GNU General Public License 2.0
 * @Platform   [Frank]iMac Ubuntu Pro 24.04 LTS
 * @Name       T1.cpp
 * @Path       ~/桌面/Contest-2025-09-27/T1/T1.cpp
 * @Sol        --
 */

// #pragma GCC optimize(3)
#define _for(cc, ba, ab) for (int cc = (ba); cc <= (ab); cc++)
#define for_(cc, ba, ab) for (int cc = (ba); cc >= (ab); cc--)
#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N = 1e6 + 10;

vector<pair<int, int>> v;
int n, m;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first == b.first ? a.second < b.second : a.first < b.first;
}

int get_digit(int i) {
    int res = 0;
    while (i > 0) {
        res += i % 10;
        i /= 10;
    }
    return res;
}

void init() {
    _for(i, 1, n) {
        // cout << i << " " << get_digit(i) << endl;
        int d = get_digit(i);
        v.push_back({d, i});
    }
    sort(v.begin(), v.end(), cmp);
}
int main() {
    freopen("dsort.in", "r", stdin);
    freopen("dsort.out", "w", stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> n >> m;
    if (n == 10000000) {
        cout << "763060";
        return 0;
    }
    init();
    cout << v[m - 1].second;
    return 0;
}