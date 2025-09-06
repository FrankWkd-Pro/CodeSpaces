#include <bits/stdc++.h>
using namespace std;

int x[55];  // 定义蚂蚁数组

int main() {
    int n;  // 蚂蚁数
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", &x[i]);  // 输入每个蚂蚁的情况
    int l = 0, r = 0;                                 // 统计在第1只蚂蚁左侧朝右、右侧朝左的蚂蚁数。
    for (int i = 2; i <= n; i++) {
        if (abs(x[i]) < abs(x[1]) && x[i] > 0)
            l++;  // 左侧朝右
        if (abs(x[i]) > abs(x[1]) && x[i] < 0)
            r++;  // 右侧朝左
    }
    int sum = 0;     // 定义感冒蚂蚁总数
    if (x[1] < 0) {  // 第1只蚂蚁朝左
        if (l == 0)
            sum = 1;
        else
            sum = l + r + 1;
    } else {  // 第1只蚂蚁朝右
        if (r == 0)
            sum = 1;
        else
            sum = l + r + 1;
    }
    cout << sum;
    return 0;
}