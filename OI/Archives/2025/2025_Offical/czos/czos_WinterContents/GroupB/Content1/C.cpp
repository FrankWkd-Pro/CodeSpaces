#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, ans = 0;
    cin >> a >> b;
    for (int i = 1; i * i * i * i * i * i <= b; i++) {
        int cool_number = i * i * i * i * i * i;
        if (cool_number >= a && cool_number <= b) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}