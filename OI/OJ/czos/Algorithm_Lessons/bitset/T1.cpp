
// #pragma GCC optimize(3)
#define _for(cc, ba, ab) for (int cc = (ba); cc <= (ab); cc++)
#define for_(cc, ba, ab) for (int cc = (ba); cc >= (ab); cc--)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
bitset<N> b1, b2;
int n, m, x;
// #define int long long
void output(const bitset<N> &b) {
    bool f = 0;
    _for(i, 1, N - 1) {
        if (b[i]) {
            cout << i << " ";
            f = 1;
        }
    }
    if (!f)
        cout << "EMPTY";
    cout << "\n";
}

int main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> n >> m;
    _for(i, 1, n) {
        cin >> x;
        b1.set(x);
    }
    _for(i, 1, m) {
        cin >> x;
        b2.set(x);
    }
    output(b1 & b2);
    output(b1 | b2);
    output(b1 & ~b2);
    return 0;
}