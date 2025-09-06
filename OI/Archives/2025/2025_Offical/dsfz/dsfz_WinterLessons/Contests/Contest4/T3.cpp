#include <bits/stdc++.h>
using namespace std;
int n;  // 直接开方减少循环次数
int main() {
    cin >> n;
    for (int i = 0; i * i <= n; i++) {
        int i2 = i * i;
        for (int j = 0; i2 + j * j <= n; j++) {
            int j2 = j * j;
            for (int k = 0; i2 + j2 + k * k <= n; k++) {
                int k2 = k * k, x = n - i2 - j2 - k2, gx = sqrt(x);
                if (gx * gx == x)
                    return cout << i << " " << j << " " << k << " " << gx, 0;
            }
        }
    }
    return 0;
}