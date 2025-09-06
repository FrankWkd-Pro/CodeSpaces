#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

int main() {
    //	1  2  3  4  5  6 x/6 == 0 or x == 6
    //	12 11 10 9  8  7 x/6 == 1 or x == 12
    int n, m, w;
    cin >> w >> m >> n;
    int yushu_n = n % w, yushu_m = m % w;
    int shang_n = n / w, shang_m = m / w;
    int x_n, x_m, y_n, y_m;  // 坐标，不是行列
    if (yushu_n == 0) {
        y_n = shang_n;
        if (shang_n % 2 == 1) {  // 奇数列
            x_n = w;
        } else {
            x_n = 1;
        }
    } else {
        y_n = shang_n + 1;
        if ((shang_n + 1) % 2 == 1) {
            x_n = yushu_n;
        } else {
            x_n = w - yushu_n + 1;
        }
    }
    //	cout<<x_n<<" "<<y_n;
    if (yushu_m == 0) {
        y_m = shang_m;
        if (shang_m % 2 == 1) {  // 奇数列
            x_m = w;
        } else {
            x_m = 1;
        }
    } else {
        y_m = shang_m + 1;
        if ((shang_m + 1) % 2 == 1) {
            x_m = yushu_m;
        } else {
            x_m = w - yushu_m + 1;
        }
    }
    //	cout<<x_n<< "<<y_n;
    cout << abs(x_n - x_m) + abs(y_n - y_m);
}

// 1  2  3  4 5 6
// 12 11 10 9 8 7