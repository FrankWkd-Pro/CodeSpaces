#include <bits/stdc++.h>
using namespace std;
int b[20];
int a[20], ans = INT_MAX;
string s, target;
int main() {
    cin >> target;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        a[s[i] - '0']++;
    }
    for (int i = 0; i < target.size(); i++) {
        b[target[i] - '0']++;
    }
    // for (int i = 1; i <= 10; i++) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    for (int i = 0; i < 10; i++) {
        int totNow = 0;
        if (b[i] == 0)
            continue;
        // cout << i << " " << a[i] << " " << b[i] << endl;
        if (i == 2 or i == 5) {
            totNow = (a[2] + a[5]) / (b[2] + b[5]);
        } else if (i == 6 or i == 9) {
            totNow = (a[6] + a[9]) / (b[6] + b[9]);
        } else
            totNow = a[i] / b[i];
        ans = min(ans, totNow);
        // cout << totNow << " " << ans << endl;
    }
    cout << ans << endl;
    return 0;
}