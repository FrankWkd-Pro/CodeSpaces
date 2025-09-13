/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-09-13
 * @Network   "https://www.luogu.com.cn/problem/T664741?contestId=275290"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  T664741-[MX-X20-T1][FAOI-R7]T1.cpp
 * @FilePath  /workspaces/CodeSpaces/OI/OJ/Luogu/T664741-[MX-X20-T1][FAOI-R7]T1.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    int a, b, k,ans = 0;
    cin >> a >> b >> k;
    while(a < b){
        a = max(a+k,a*k);
        ans++;
    }
    cout << ans << endl;
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}