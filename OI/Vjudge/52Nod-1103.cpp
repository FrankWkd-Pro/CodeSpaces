/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-06-30
 * @Network   "https://vjudge.net/problem/51Nod-1103"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  52Nod-1103.cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/Vjudge/52Nod-1103.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
int a[1010100], n;
int ori[1010100];
struct node {
    int data, con;
} ans[1010100];
void print(int x, int y) {
    cout << y - x << endl;
    for (int i = x + 1; i <= y; i++) {
        cout << ori[i] << "\n";
    }
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ori[i] = a[i];
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        a[i] %= n;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            print(0, i);
            return 0;
        }
        ans[a[i]].data++;
        if (ans[a[i]].data > 1) {
            print(ans[a[i]].con, i);
            return 0;
        }
        ans[a[i]].con = i;
    }
    return 0;
}