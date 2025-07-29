/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-07-27
 * @Network   "http://www.accoders.com/problem.php?cid=2332&pid=1"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  The-XOR-Largest-Pair.cpp
 * @FilePath  /media/frank/FrankW/_default/Mine/Working/code-spaces/OI/OJ/Accoders/Trie/The-XOR-Largest-Pair.cpp
 * @Solution  首先我们看看题目，要找一个两个数字最大的异或结果，而且这两个数字二进制下小于32位。因为异或是不进位的加法，所以我们只要保证两个数字在32位二进制下不同的字符最多即可。那么我们先用所有数字的32位二进制数建一个Trie树，对于每个数字按着它的二进制顺着trie树从上到下找有没有这一位和当前的数的这一二进制位不同的，如果有那么就前往该节点，最后取每个数找到跟它匹配的数的异或值中的最大值输出即可。
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1010010][3];  // 如题
int idx;            // 以该节点为单词结尾的单词个数，最大的节点编号
int input, n, ans;
void insert() {
    int x, p = 0, inpu = input;
    // 需要从低位到高位建树&查找，因为高位占收益的大部分
    for (int i = 30; i >= 0 and inpu > 0; i--) {
        x = (inpu >> i) & 1;
        if (a[p][x] == 0)
            a[p][x] = ++idx;
        p = a[p][x];
    }
}
int count() {
    int x, p = 0, res = 0, base = 1;

    for (int i = 30; i >= 0 and input > 0; i--) {
        x = ((input >> i) & 1) ^ 1;
        if (a[p][x] != 0)
            res += (1 << i), p = a[p][x];
        else if (a[p][x ^ 1] != 0)
            p = a[p][x ^ 1];
        else
            break;
    }
    return res;
}
signed main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        // 小tricks：我们对于每个数只计算在它前面的数，这样能够避免每对数重复算两次，降低一些复杂度（虽然没降多少、、、）
        cin >> input;
        insert();
        ans = max(ans, count());
    }
    cout << ans << endl;
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}