#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    ans = n;
    while (n >= 3) {
        ans += n / 3;
        n = n / 3 + n % 3;
    }
    cout << ans << endl;
}