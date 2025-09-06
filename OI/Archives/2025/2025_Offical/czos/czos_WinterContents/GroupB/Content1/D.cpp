#include <bits/stdc++.h>

#include <iostream>
using namespace std;
int a[101011], b[101011];
int main() {
    int ans = 0;
    int x, y, n;
    cin >> x >> n >> y;
    for (int i = 1; i <= n; i++) {
        cin >> a[1] >> b[1];
        if (b[1] == 0)
            continue;
        int times = y % b[1] != 0 ? y / b[1] + 1 : y / b[1];
        // cout << endl<< "-----" << times << endl;
        if (x - times * a[1] >= 0) {
            cout << i << endl;
            ans++;
        }
    }
    if (ans == 0) {
        ans--;
        cout << ans;
    }
    return 0;
}