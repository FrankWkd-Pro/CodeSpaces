/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-09-02
 * @Network   ""
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  T5.cpp
 * @FilePath  /workspaces/CodeSpaces/OI/czos/Algorithm_Lessons/bitset/T5.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int N = 10;

int main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    // reverse(s1.begin(), s1.end());
    // reverse(s2.begin(), s2.end());
    bitset<N> a(s1);
    bitset<N> b(s2);
    string op;
    cin >> op;
    if (op == "and") {
        cout << (a & b);
    } else if (op == "or") {
        cout << (a | b);
    } else if (op == "xor") {
        cout << (a ^ b);
    }
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}  // TODO