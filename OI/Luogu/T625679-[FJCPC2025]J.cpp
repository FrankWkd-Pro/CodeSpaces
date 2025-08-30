/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-07-06
 * @Network   ""
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  T625679-[FJCPC2025]J.cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/Luogu/T625679-[FJCPC2025]J.cpp
 * @Solution  一种比较简单的做法是考虑二进制构造。不难发现 2^{2i} 一定是完全平方数。我们回顾一下树状数组中的一个概念，lowbit(n) 为可以整除 n的最大的二的幂次方 2^i 。那么们每次加 x = lowbit(n) 即可，显然lowbit(n) 必然是递增的，当前的x 必然和历史 x 不同。
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
long long lowbit(long long x) {
    return x & -x;
}
int main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    int t;
    long long x;
    cin >> t;
    while (t--) {
        cin >> x;
        int times = 0;
        vector<int> v;
        while (sqrt(x) != ceil(sqrt(x))) {
            v.push_back(lowbit(x));
            x += lowbit(x);
            times++;
        }
        cout << times << endl;
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        puts("");
    }
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}